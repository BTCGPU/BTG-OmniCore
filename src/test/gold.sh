#!/bin/bash
SRCDIR=/media/ale/data/BTCGPU/src
DATADIR=/media/ale/data
NUL=/dev/null
clear
printf "Preparing a test environment...\n"
printf "Starting a fresh regtest daemon\n"
rm -r /media/ale/data/regtest
$SRCDIR/bgoldd -datadir=$DATADIR -regtest -daemon -server
$SRCDIR/bgold-cli -regtest -datadir=$DATADIR -rpcwait=1 generate 101 >$NUL
ADDR2=$($SRCDIR/bgold-cli -regtest -datadir=$DATADIR getnewaddress ale)
ADDR3=$($SRCDIR/bgold-cli -regtest -datadir=$DATADIR getnewaddress ale)
printf "Checking unspent of ADDR\n"
TRA=$($SRCDIR/bgold-cli -datadir=$DATADIR -regtest listunspent)
txid=`echo "$TRA" | jq '.['"$idx"']' | jq .'"txid"'`
vout=`echo "$TRA" | jq '.['"$idx"']' | jq .'"vout"'`
scriptPubKey=`echo "$TRA" | jq '.['"$idx"']' | jq .'"scriptPubKey"'`
amount=`echo "$TRA" | jq '.['"$idx"']' | jq .'"amount"'`
ADDR=`echo "$TRA" | jq '.['"$idx"']' | jq .'"address"'`
printf "the txid:\n"
printf "${txid}\n"
printf "the vout:\n"
printf "${vout}\n"
printf "the scriptPubKey:\n"
printf "${scriptPubKey}\n"
printf "amount:\n"
printf "${amount}\n"
printf "address:\n"
printf "${ADDR}\n"

# the payload to send 0.1 OMNI:
printf "the payload for send 0.1 OMNI:"
PAYLOAD="00000000000000020000000000989680"
printf "${PAYLOAD}\n"
TRA=$($SRCDIR/bgold-cli -regtest -datadir=$DATADIR createrawtransaction '[{"txid": '${txid}',"vout":'${vout}'}]' '{}')
printf " Attaching the Payload:\n"
TRA2=$($SRCDIR/bgold-cli -regtest -datadir=$DATADIR omni_createrawtx_opreturn "${TRA}" "${PAYLOAD}")
printf " Attach reference/receiver:\n"
TRA3=$($SRCDIR/bgold-cli -regtest -datadir=$DATADIR omni_createrawtx_reference "${TRA2}" "${ADDR2}")
printf " Attach change:\n"
TRA4=$($SRCDIR/bgold-cli -regtest -datadir=$DATADIR omni_createrawtx_change "${TRA3}" '[{"txid":'${txid}',"vout":'${vout}',"scriptPubKey":'${scriptPubKey}',"value":'${amount}'}]' "${ADDR3}" 0.0006)
TRA5=$($SRCDIR/bgold-cli -regtest -datadir=$DATADIR signrawtransaction "${TRA4}")
hex=`echo "$TRA5" | jq .'"hex"'`
hex1=`echo ${hex//[^a-zA-Z0-9]/}`
TRA6=$($SRCDIR/bgold-cli -datadir=$DATADIR sendrawtransaction ${hex1} true)
$SRCDIR/bgold-cli -regtest -datadir=$DATADIR getrawtransaction ${TRA6} 1
$SRCDIR/bgold-cli -datadir=$DATADIR generate 1 > $NUL
$SRCDIR/bgold-cli -regtest -datadir=$DATADIR stop
