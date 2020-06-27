#!/usr/bin/env python3
# Copyright (c) 2015-2017 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
"""Test Creating fixed tokens."""

from test_framework.test_framework import BitcoinTestFramework
from test_framework.util import *

import os
import json
import http.client
import urllib.parse

class FixedBasicsTest (BitcoinTestFramework):
    def __init__(self):
        super().__init__()
        self.num_nodes = 1
        self.setup_clean_chain = True
        self.extra_args = [["-txindex=1", "-datacarriersize=220"]]

    def setup_network(self):
        self.setup_nodes()

    def run_test(self):

        self.log.info("Preparing the workspace...")

        # mining 200 blocks
        self.nodes[0].generate(200)

        ################################################################################
        # Checking RPC omni_sendissuancefixed and omni_send (in the first 200 blocks of the chain) #
        ################################################################################

        url = urllib.parse.urlparse(self.nodes[0].url)

        #Old authpair
        authpair = url.username + ':' + url.password

        headers = {"Authorization": "Basic " + str_to_b64str(authpair)}

        addresses = []
        accounts = ["john", "doe", "another"]

        conn = http.client.HTTPConnection(url.hostname, url.port)
        conn.connect()

        self.log.info("Creating sender address")
        addresses = omnilayer_createAddresses(accounts, conn, headers)

        self.log.info("Funding addresses with BTG")
        amount = 0.1
        omnilayer_fundingAddresses(addresses, amount, conn, headers)

        self.log.info("Checking the BTG balance in every account")
        omnilayer_checkingBalance(accounts, amount, conn, headers)


        self.log.info("Creating new tokens (sendissuancefixed)")
        array = [0]
        params = str([addresses[0], 1, 2, 0,"N/A", "N/A", "lihki", "url", "data", "3000"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_sendissuancefixed",params)
        # self.log.info(out)

        self.nodes[0].generate(1)


        self.log.info("Checking the property")
        params = str([3])
        out = omnilayer_HTTP(conn, headers, True, "omni_getproperty",params)
        # self.log.info(out)
        assert_equal(out['result']['propertyid'], 3)
        assert_equal(out['result']['name'],'lihki')
        assert_equal(out['result']['issuer'], addresses[0])
        assert_equal(out['result']['data'],'data')
        assert_equal(out['result']['url'],'url')
        assert_equal(out['result']['category'],'N/A')
        assert_equal(out['result']['subcategory'],'N/A')
        assert_equal(out['result']['divisible'],True)
        assert_equal(out['result']['totaltokens'],'3000.00000000')


        self.log.info("Checking token balance in every address")
        for addr in addresses:
            params = str([addr, 3]).replace("'",'"')
            out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
            # self.log.info(out)
            amount = ""
            assert_equal(out['error'], None)
            if addr == addresses[0]:
                 amount = '3000.00000000'
            else:
                 amount = '0.00000000'

            assert_equal(out['result']['balance'], amount)
            assert_equal(out['result']['reserved'],'0.00000000')


        self.log.info("Sending 2000 tokens to receiver (omni_send)")
        params = str([addresses[0], addresses[1], 3, "2000"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_send",params)
        # self.log.info(out)

        self.nodes[0].generate(1)


        self.log.info("Checking tokens in receiver address")
        params = str([addresses[1], 3]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result']['balance'],'2000.00000000')
        assert_equal(out['result']['reserved'],'0.00000000')


        self.log.info("Sending 1000 tokens to from receiver to last address (using omni_send)")
        params = str([addresses[1], addresses[2], 3,"1000"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_send",params)
        # self.log.info(out)
        assert_equal(out['error'], None)

        self.nodes[0].generate(1)


        self.log.info("Checking tokens in receiver address and last address")
        for i in range(2):
            params = str([addresses[i], 3]).replace("'",'"')
            out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
            # self.log.info(out)
            assert_equal(out['error'], None)
            assert_equal(out['result']['balance'],'1000.00000000')
            assert_equal(out['result']['reserved'],'0.00000000')


        self.log.info("Trying to change the issuer")
        params = str([addresses[0], addresses[1], 3]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, False, "omni_sendchangeissuer",params)
        # self.log.info(out)

        self.nodes[0].generate(1)


        self.log.info("Checking issuer's balance now")
        params = str([addresses[1], 3]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result']['balance'],'1000.00000000')
        assert_equal(out['result']['reserved'],'0.00000000')


        conn.close()


if __name__ == '__main__':
    FixedBasicsTest ().main ()
