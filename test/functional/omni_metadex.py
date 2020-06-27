#!/usr/bin/env python3
# Copyright (c) 2015-2017 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
"""Test MetaDEx functions."""

from test_framework.test_framework import BitcoinTestFramework
from test_framework.util import *

import os
import json
import http.client
import urllib.parse

class MetaDExBasicsTest (BitcoinTestFramework):
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
        # Checking RPC omni_sendtrade (in the first 200 blocks of the chain) #
        ################################################################################

        url = urllib.parse.urlparse(self.nodes[0].url)

        #Old authpair
        authpair = url.username + ':' + url.password

        headers = {"Authorization": "Basic " + str_to_b64str(authpair)}

        addresses = []
        accounts = ["john", "doe", "another", "mark"]

        conn = http.client.HTTPConnection(url.hostname, url.port)
        conn.connect()

        self.log.info("Creating addresses")
        addresses = omnilayer_createAddresses(accounts, conn, headers)

        self.log.info("Funding addresses with BTG")
        amount = 1.1
        omnilayer_fundingAddresses(addresses, amount, conn, headers)

        self.log.info("Checking the BTG balance in every account")
        omnilayer_checkingBalance(accounts, amount, conn, headers)

        self.log.info("Creating new tokens  (lihki)")
        params = str([addresses[0],1, 2, 0, "N/A", "N/A", "lihki", "url", "data", "20000000000"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_sendissuancefixed",params)
        assert_equal(out['error'], None)
        # self.log.info(out)

        self.nodes[0].generate(1)


        self.log.info("Creating new tokens  (dan)")
        params = str([addresses[1], 1, 2, 0, "N/A", "N/A", "dan", "url", "data", "100001.00000000"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_sendissuancefixed",params)
        assert_equal(out['error'], None)
        # self.log.info(out)

        self.nodes[0].generate(1)

        self.log.info("Checking the property: lihki")
        params = str([3])
        out = omnilayer_HTTP(conn, headers, True, "omni_getproperty",params)

        assert_equal(out['error'], None)
        # self.log.info(out)
        assert_equal(out['result']['propertyid'],3)
        assert_equal(out['result']['name'],'lihki')
        assert_equal(out['result']['data'],'data')
        assert_equal(out['result']['url'],'url')
        assert_equal(out['result']['category'],'N/A')
        assert_equal(out['result']['subcategory'],'N/A')
        assert_equal(out['result']['divisible'],True)
        assert_equal(out['result']['totaltokens'],'20000000000.00000000')


        self.log.info("Checking the property: dan ")
        params = str([4])
        out = omnilayer_HTTP(conn, headers, True, "omni_getproperty",params)
        assert_equal(out['error'], None)
        # self.log.info(out)
        assert_equal(out['result']['propertyid'], 4)
        assert_equal(out['result']['name'],'dan')
        assert_equal(out['result']['data'],'data')
        assert_equal(out['result']['url'],'url')
        assert_equal(out['result']['category'],'N/A')
        assert_equal(out['result']['subcategory'],'N/A')
        assert_equal(out['result']['divisible'],True)
        assert_equal(out['result']['totaltokens'],'100001.00000000')


        self.log.info("Checking tokens balance in lihki's owner ")
        params = str([addresses[0], 3]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result']['balance'],'20000000000.00000000')
        assert_equal(out['result']['reserved'],'0.00000000')


        self.log.info("Checking tokens balance in dan's owner ")
        params = str([addresses[1], 4]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result']['balance'],'100001.00000000')
        assert_equal(out['result']['reserved'],'0.00000000')


        self.log.info("Sending a trade in MetaDEx")
        params = str([addresses[0], 3, "500", 4, "2000"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_sendtrade",params)
        # self.log.info(out)
        assert_equal(out['error'], None)

        self.nodes[0].generate(1)


        self.log.info("Checking the trade in orderbook")
        params = str([3])
        out = omnilayer_HTTP(conn, headers, True, "omni_getorderbook",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result'][0]['address'], addresses[0])
        assert_equal(out['result'][0]['propertyidforsale'],3)
        assert_equal(out['result'][0]['amountforsale'],'500.00000000')
        assert_equal(out['result'][0]['propertyiddesired'],4)
        assert_equal(out['result'][0]['amountdesired'],'2000.00000000')


        self.log.info("Cancelling all trades in MetaDEx")
        params = str([addresses[0], 1]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, False, "omni_sendcancelalltrades",params)
        # self.log.info(out)

        assert_equal(out['error'], None)

        self.nodes[0].generate(1)


        self.log.info("Checking the trades in orderbook")
        params = str([3])
        out = omnilayer_HTTP(conn, headers, True, "omni_getorderbook",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result'],[])

        self.log.info("Sending a new  trade in MetaDEx")
        params = str([addresses[0], 3, "1000", 4, "2000"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_sendtrade",params)
        # self.log.info(out)
        assert_equal(out['error'], None)

        self.nodes[0].generate(1)

        self.log.info("Checking the trade in orderbook")
        params = str([3])
        out = omnilayer_HTTP(conn, headers, True, "omni_getorderbook",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result'][0]['address'], addresses[0])
        assert_equal(out['result'][0]['propertyidforsale'],3)
        assert_equal(out['result'][0]['amountforsale'],'1000.00000000')
        assert_equal(out['result'][0]['propertyiddesired'],4)
        assert_equal(out['result'][0]['amountdesired'],'2000.00000000')

        self.log.info("Sending a second trade in MetaDEx")
        params = str([addresses[1], 4, "2000", 3, "1000"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_sendtrade",params)
        assert_equal(out['error'], None)

        self.nodes[0].generate(1)


        self.log.info("Checking tokens balance for first address")
        params = str([addresses[0], 3]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result']['balance'],'19999999000.00000000')
        assert_equal(out['result']['reserved'],'0.00000000')

        params = str([addresses[0], 4]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result']['balance'],'2000.00000000')
        assert_equal(out['result']['reserved'],'0.00000000')

        self.log.info("Checking tokens balance for second address")
        params = str([addresses[1], 3]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result']['balance'], '1000.00000000')
        assert_equal(out['result']['reserved'],'0.00000000')

        params = str([addresses[1], 4]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result']['balance'],'98001.00000000')
        assert_equal(out['result']['reserved'],'0.00000000')


        self.log.info("Sending 10000000000 lihki tokens to fourth address")
        params = str([addresses[0], addresses[3],3, "10000000000"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_send",params)
        assert_equal(out['error'], None)
        # self.log.info(out)

        self.nodes[0].generate(1)


        self.log.info("Checking tokens in receiver address")
        params = str([addresses[3], 3]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result']['balance'],'10000000000.00000000')
        assert_equal(out['result']['reserved'],'0.00000000')

        self.log.info("Sending 1 dan token to third address")
        params = str([addresses[1], addresses[2], 4, "1"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_send",params)
        assert_equal(out['error'], None)
        # self.log.info(out)

        self.nodes[0].generate(1)

        self.log.info("Checking dan tokens in receiver address")
        params = str([addresses[2], 4]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result']['balance'],'1.00000000')
        assert_equal(out['result']['reserved'],'0.00000000')


        self.log.info("Sending a big trade in MetaDEx")
        params = str([addresses[3], 3, "10000000000", 4, "0.00000002"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_sendtrade",params)
        # self.log.info(out)
        assert_equal(out['error'], None)

        self.nodes[0].generate(1)

        self.log.info("Checking the trade in orderbook")
        params = str([3])
        out = omnilayer_HTTP(conn, headers, True, "omni_getorderbook",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result'][0]['address'], addresses[3])
        assert_equal(out['result'][0]['propertyidforsale'], 3)
        assert_equal(out['result'][0]['amountforsale'],'10000000000.00000000')
        assert_equal(out['result'][0]['propertyiddesired'], 4)
        assert_equal(out['result'][0]['amountdesired'],'0.00000002')

        self.log.info("Sending a small trade in MetaDEx")
        params = str([addresses[2], 4, "0.00000001", 3, "5000000000"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_sendtrade",params)
        # self.log.info(out)
        assert_equal(out['error'], None)

        self.nodes[0].generate(1)

        self.log.info("Checking lihki tokens in third address")
        params = str([addresses[2], 3]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result']['balance'],'5000000000.00000000') # 5000000000 minus fees
        assert_equal(out['result']['reserved'],'0.00000000')


        self.log.info("Checking dan tokens in fourth address")
        params = str([addresses[3], 4]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result']['balance'],'0.00000001')
        assert_equal(out['result']['reserved'],'0.00000000')

        conn.close()

if __name__ == '__main__':
    MetaDExBasicsTest ().main ()
