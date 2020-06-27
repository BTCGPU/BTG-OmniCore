#!/usr/bin/env python3
# Copyright (c) 2015-2017 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
"""Test DEx functions ."""

from test_framework.test_framework import BitcoinTestFramework
from test_framework.util import *

import os
import json
import http.client
import urllib.parse

class DExBasicsTest (BitcoinTestFramework):
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
        # Checking RPC omni_senddexoffer and omni_getactivedexsells (in the first 200 blocks of the chain) #
        ################################################################################

        url = urllib.parse.urlparse(self.nodes[0].url)

        #Old authpair
        authpair = url.username + ':' + url.password

        headers = {"Authorization": "Basic " + str_to_b64str(authpair)}

        addresses = []
        accounts = ["john", "doe", "another", "marks"]


        conn = http.client.HTTPConnection(url.hostname, url.port)
        conn.connect()

        self.log.info("Creating sender address")
        addresses = omnilayer_createAddresses(accounts, conn, headers)


        self.log.info("Funding addresses with BTG")
        amount = 5
        omnilayer_fundingAddresses(addresses, amount, conn, headers)

        self.log.info("Checking the BTG balance in every account")
        omnilayer_checkingBalance(accounts, amount, conn, headers)

        self.log.info("Creating new tokens (sendissuancefixed)")
        params = str([addresses[0], 1, 2, 0,"N/A", "N/A", "lihki", "url", "data","90000000"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_sendissuancefixed",params)
        # self.log.info(out)

        self.nodes[0].generate(1)

        self.log.info("Checking the property")
        params = str([3])
        out = omnilayer_HTTP(conn, headers, True, "omni_getproperty",params)
        assert_equal(out['error'], None)
        # self.log.info(out)
        assert_equal(out['result']['propertyid'],3)
        assert_equal(out['result']['name'],'lihki')
        assert_equal(out['result']['data'],'data')
        assert_equal(out['result']['url'],'url')
        assert_equal(out['result']['divisible'],True)
        assert_equal(out['result']['totaltokens'],'90000000.00000000')

        self.log.info("Checking token balance in every address")
        for addr in addresses:
            params = str([addr, 3]).replace("'",'"')
            out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
            # self.log.info(out)
            amount = ""
            assert_equal(out['error'], None)
            if addr == addresses[0]:
                 amount = '90000000.00000000'
            else:
                 amount = '0.00000000'

            assert_equal(out['result']['balance'], amount)
            assert_equal(out['result']['reserved'],'0.00000000')

        self.log.info("Sending 1000 tokens to second address")
        params = str([addresses[0], addresses[3], 3, "1000"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_send",params)
        # self.log.info(out)

        self.nodes[0].generate(1)


        self.log.info("Checking tokens in receiver address")
        params = str([addresses[3], 3]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result']['balance'],'1000.00000000')
        assert_equal(out['result']['reserved'],'0.00000000')


        self.log.info("Sending a DEx sell tokens offer")
        params = str([addresses[0], 3, "1000", "1", 250, "0.00001", 1]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, False, "omni_senddexsell",params)
        assert_equal(out['error'], None)
        # self.log.info(out)

        self.nodes[0].generate(1)

        self.log.info("Checking the offer in DEx")
        params = str([addresses[0]]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getactivedexsells",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result'][0]['propertyid'], 3)
        assert_equal(out['result'][0]['seller'], addresses[0])
        assert_equal(out['result'][0]['bitcoindesired'], '1.00000000')
        assert_equal(out['result'][0]['amountavailable'], '1000.00000000')
        assert_equal(out['result'][0]['amountaccepted'], '0.00000000')
        assert_equal(out['result'][0]['unitprice'], '0.00100000')
        assert_equal(out['result'][0]['minimumfee'], '0.00001000')


        self.log.info("Cancelling the DEx offer")
        params = str([addresses[0], 3, "1000", "1", 250, "0.00001", 3]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_senddexsell",params)
        assert_equal(out['error'], None)
        # self.log.info(out)

        self.nodes[0].generate(1)


        self.log.info("Checking the offer in DEx again")
        params = str([addresses[0]]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getactivedexsells",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result'], [])


        self.log.info("Putting a new DEx sell tokens offer")
        params = str([addresses[0], 3, "1000", "2", 250, "0.00001", 1]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_senddexsell",params)
        assert_equal(out['error'], None)
        # self.log.info(out)

        self.nodes[0].generate(1)

        self.log.info("Checking the new offer in DEx")
        params = str([addresses[0]]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getactivedexsells",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result'][0]['propertyid'], 3)
        assert_equal(out['result'][0]['seller'], addresses[0])
        assert_equal(out['result'][0]['bitcoindesired'], '2.00000000')
        assert_equal(out['result'][0]['amountavailable'], '1000.00000000')
        assert_equal(out['result'][0]['amountaccepted'], '0.00000000')
        assert_equal(out['result'][0]['unitprice'], '0.00200000')
        assert_equal(out['result'][0]['minimumfee'], '0.00001000')


        self.log.info("Changing the new DEx sell tokens offer")
        params = str([addresses[0], 3, "1000", "4", 250, "0.00001", 2]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_senddexsell",params)
        assert_equal(out['error'], None)
        # self.log.info(out)


        self.nodes[0].generate(1)

        self.log.info("Checking the new offer in DEx")
        params = str([addresses[0]]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getactivedexsells",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result'][0]['propertyid'], 3)
        assert_equal(out['result'][0]['seller'], addresses[0])
        assert_equal(out['result'][0]['bitcoindesired'], '4.00000000')
        assert_equal(out['result'][0]['amountavailable'], '1000.00000000')
        assert_equal(out['result'][0]['amountaccepted'], '0.00000000')
        assert_equal(out['result'][0]['unitprice'], '0.00400000')
        assert_equal(out['result'][0]['minimumfee'], '0.00001000')


        self.log.info("Accepting the full offer")
        params = str([addresses[1], addresses[0], 3, "1000"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_senddexaccept",params)
        assert_equal(out['error'], None)
        # self.log.info(out)

        self.nodes[0].generate(10)

        self.log.info("Checking the offer status")
        params = str([addresses[0]]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getactivedexsells",params)
        # self.log.info(out)

        assert_equal(out['error'], None)
        assert_equal(out['result'][0]['propertyid'], 3)
        assert_equal(out['result'][0]['seller'], addresses[0])
        assert_equal(out['result'][0]['bitcoindesired'], '0.00000000')
        assert_equal(out['result'][0]['amountavailable'], '0.00000000')
        assert_equal(out['result'][0]['amountaccepted'], '1000.00000000')
        assert_equal(out['result'][0]['unitprice'], '0.00400000')
        assert_equal(out['result'][0]['minimumfee'], '0.00001000')

        assert_equal(out['result'][0]['accepts'][0]['buyer'], addresses[1])
        assert_equal(out['result'][0]['accepts'][0]['amounttopay'], '4.00000000')
        assert_equal(out['result'][0]['accepts'][0]['amount'], '1000.00000000')
        assert_equal(out['result'][0]['accepts'][0]['block'], 208)
        assert_equal(out['result'][0]['accepts'][0]['blocksleft'], 241)


        self.log.info("Paying the tokens")
        params = str([addresses[1], addresses[0], "4.0"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, False, "omni_send_dexpayment",params)
        # self.log.info(out)

        self.nodes[0].generate(1)


        self.log.info("Checking token balance in seller address")
        params = str([addresses[0], 3]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result']['balance'], '89998000.00000000')
        assert_equal(out['result']['reserved'],'0.00000000')


        self.log.info("Checking token balance in buyer address")
        params = str([addresses[1], 3]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result']['balance'], '1000.00000000')
        assert_equal(out['result']['reserved'],'0.00000000')


        self.log.info("Checking the offer status")
        params = str([addresses[0]]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getactivedexsells",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result'],[])


        self.log.info("Checking a small token offer")
        params = str([addresses[0], 3, "0.00000001", "20", 250, "0.00001", 1]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, False, "omni_senddexsell",params)
        assert_equal(out['error'], None)
        # self.log.info(out)

        self.nodes[0].generate(1)

        self.log.info("Checking the offer in DEx")
        params = str([addresses[0]]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getactivedexsells",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result'][0]['propertyid'], 3)
        assert_equal(out['result'][0]['seller'], addresses[0])
        assert_equal(out['result'][0]['bitcoindesired'], '20.00000000')
        assert_equal(out['result'][0]['amountavailable'], '0.00000001')
        assert_equal(out['result'][0]['amountaccepted'], '0.00000000')
        assert_equal(out['result'][0]['unitprice'], '2000000000.00000000')
        assert_equal(out['result'][0]['minimumfee'], '0.00001000')


        self.log.info("Checking a smaller token offer")
        params = str([addresses[0], 3, "0.000000001", "20", 250, "0.00001", 1]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, False, "omni_senddexsell",params)
        # self.log.info(out)
        assert_equal(out['error']['code'], -3)
        assert_equal(out['error']['message'],'Invalid amount')


        self.log.info("Sending 20000000 tokens to second address")
        params = str([addresses[0], addresses[1], 3, "20000000"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_send",params)
        # self.log.info(out)

        self.nodes[0].generate(1)


        self.log.info("Checking tokens in receiver address")
        params = str([addresses[1], 3]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getbalance",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result']['balance'],'20001000.00000000')
        assert_equal(out['result']['reserved'],'0.00000000')

        self.log.info("Checking a big token offer")
        params = str([addresses[1], 3, "10000000.98765432", "20", 250, "0.00001", 1]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, False, "omni_senddexsell",params)
        # self.log.info(out)

        self.nodes[0].generate(1)

        self.log.info("Checking the offer in DEx")
        params = str([addresses[1]]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getactivedexsells",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result'][0]['propertyid'], 3)
        assert_equal(out['result'][0]['seller'], addresses[1])
        assert_equal(out['result'][0]['bitcoindesired'], '20.00000000')
        assert_equal(out['result'][0]['amountavailable'], '10000000.98765432')
        assert_equal(out['result'][0]['amountaccepted'], '0.00000000')
        assert_equal(out['result'][0]['unitprice'], '0.00000199')
        assert_equal(out['result'][0]['minimumfee'], '0.00001000')


        self.log.info("Cancelling the DEx offer")
        params = str([addresses[1], 3, "10000000.98765432", "20", 250, "0.00001", 3]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, False, "omni_senddexsell",params)
        # self.log.info(out)

        self.nodes[0].generate(1)


        self.log.info("Checking the offer in DEx ")
        params = str([addresses[1]]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getactivedexsells",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result'], [])


        self.log.info("Testing the payment window")
        self.log.info("Sending a new DEx offer")
        params = str([addresses[1], 3, "600", "1", 10, "0.00001", 1]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, False, "omni_senddexsell",params)
        # self.log.info(out)

        self.nodes[0].generate(1)

        self.log.info("Checking the offer in DEx ")
        params = str([addresses[1]]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getactivedexsells",params)
        # self.log.info(out)

        assert_equal(out['error'], None)
        assert_equal(out['result'][0]['propertyid'], 3)
        assert_equal(out['result'][0]['seller'], addresses[1])
        assert_equal(out['result'][0]['bitcoindesired'], '1.00000000')
        assert_equal(out['result'][0]['amountavailable'], '600.00000000')
        assert_equal(out['result'][0]['amountaccepted'], '0.00000000')
        assert_equal(out['result'][0]['unitprice'], '0.00166666')
        assert_equal(out['result'][0]['minimumfee'], '0.00001000')

        self.log.info("Accepting the full offer")
        params = str([addresses[3], addresses[1], 3, "600"]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_senddexaccept",params)
        assert_equal(out['error'], None)
        # self.log.info(out)

        self.nodes[0].generate(1)


        self.log.info("Checking the offer in DEx ")
        params = str([addresses[1]]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getactivedexsells",params)
        # self.log.info(out)

        assert_equal(out['error'], None)
        assert_equal(out['result'][0]['propertyid'], 3)
        assert_equal(out['result'][0]['seller'], addresses[1])
        assert_equal(out['result'][0]['bitcoindesired'], '0.00000000')
        assert_equal(out['result'][0]['amountavailable'], '0.00000000')
        assert_equal(out['result'][0]['amountaccepted'], '600.00000000')
        assert_equal(out['result'][0]['unitprice'], '0.00166666')
        assert_equal(out['result'][0]['minimumfee'], '0.00001000')

        assert_equal(out['result'][0]['accepts'][0]['buyer'], addresses[3])
        assert_equal(out['result'][0]['accepts'][0]['amount'], '600.00000000')
        assert_equal(out['result'][0]['accepts'][0]['amounttopay'], '1.00000000')
        assert_equal(out['result'][0]['accepts'][0]['blocksleft'], 10)


        self.log.info("Mining 10 blocks ")
        self.nodes[0].generate(10)

        self.log.info("Checking the offer in DEx again")
        params = str([addresses[1]]).replace("'",'"')
        out = omnilayer_HTTP(conn, headers, True, "omni_getactivedexsells",params)
        # self.log.info(out)
        assert_equal(out['error'], None)
        assert_equal(out['result'][0]['accepts'], [])

        conn.close()

if __name__ == '__main__':
    DExBasicsTest ().main ()
