#!/usr/bin/env python3
# Copyright (c) 2015-2017 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
"""Test basic data RPCs ."""

from test_framework.test_framework import BitcoinTestFramework
from test_framework.util import *

import os
import json
import http.client
import urllib.parse

class HTTPBasicsTest (BitcoinTestFramework):
    def __init__(self):
        super().__init__()
        self.num_nodes = 1
        self.setup_clean_chain = True
        self.extra_args = [["-txindex=1", "-datacarriersize=220"]]

    def setup_network(self):
        self.setup_nodes()


    def run_test(self):

        # mining 100 blocks
        self.nodes[0].generate(100)

        ################################################################################
        # Checking RPC calls for data retrieval (in the first 100 blocks of the chain) #
        ################################################################################

        url = urllib.parse.urlparse(self.nodes[0].url)

        #Old authpair
        authpair = url.username + ':' + url.password

        headers = {"Authorization": "Basic " + str_to_b64str(authpair)}

        conn = http.client.HTTPConnection(url.hostname, url.port)

        addresses = []
        accounts = ["john", "doe", "another"]

        self.log.info("Creating sender address")
        addresses = omnilayer_createAddresses(accounts, conn, headers)


        self.log.info("Testing omni_getinfo")
        out = omnilayer_HTTP(conn, headers, False, "omni_getinfo")
        # self.log.info(out)
        assert_equal(out['result']['omnicoreversion_int'], 1)
        assert_equal(out['result']['omnicoreversion'], '')
        assert_equal(out['result']['bitcoincoreversion'], '')
        assert_equal(out['result']['blocktransactions'], 0)
        assert_equal(out['result']['block'], 100)

        self.log.info("Testing omni_listproperties")
        out = omnilayer_HTTP(conn, headers, True, "omni_listproperties")
        # self.log.info(out)

        # Checking the first property in the list
        assert_equal(out['result'][0]['propertyid'], 1)
        assert_equal(out['result'][0]['name'], "Betelgeuse")
        assert_equal(out['result'][0]['data'], "The native and first token of OmniLayer Protocol, builded on top of Bitcoin Gold.")
        assert_equal(out['result'][0]['url'], "http://www.betelgeuse.org")
        assert_equal(out['result'][0]['divisible'], True)
        assert_equal(out['result'][0]['category'], "N/A")
        assert_equal(out['result'][0]['subcategory'], "N/A")

        # Checking the second property in the list
        assert_equal(out['result'][1]['propertyid'], 2)
        assert_equal(out['result'][1]['name'], "Test Betelgeuse")
        assert_equal(out['result'][1]['data'], "The native and first  test token of OmniLayer Protocol, builded on top of Bitcoin Gold.")
        assert_equal(out['result'][1]['url'], "http://www.betelgeuse.org")
        assert_equal(out['result'][1]['divisible'], True)
        assert_equal(out['result'][1]['category'], "N/A")
        assert_equal(out['result'][1]['subcategory'], "N/A")

        self.log.info("Testing omni_getbalance")
        params = str([addresses[0], 1]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
        # self.log.info(out)
        assert_equal(out['result']['balance'],'0.00000000')
        assert_equal(out['result']['reserved'],'0.00000000')


        self.log.info("Testing omni_getproperty")
        params = str([1])
        out = omnilayer_HTTP(conn, headers, True, "omni_getproperty",params)
        # self.log.info(out)

        assert_equal(out['result']['propertyid'],1)
        assert_equal(out['result']['name'],'Betelgeuse')
        assert_equal(out['result']['data'],'The native and first token of OmniLayer Protocol, builded on top of Bitcoin Gold.')
        assert_equal(out['result']['url'],'http://www.betelgeuse.org')
        assert_equal(out['result']['divisible'],True)
        assert_equal(out['result']['managedissuance'], False)
        assert_equal(out['result']['fixedissuance'], False)
        assert_equal(out['result']['totaltokens'],'0.00000000')

        conn.close()


if __name__ == '__main__':
    HTTPBasicsTest ().main ()
