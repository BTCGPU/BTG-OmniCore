#ifndef OMNICORE_RPCTX
#define OMNICORE_RPCTX



#include "rpc/server.h"
#include "wallet/wallet.h"
#include <univalue.h>

UniValue omni_sendrawtx(const JSONRPCRequest& request);
UniValue omni_send(const JSONRPCRequest& request);
UniValue omni_sendall(const JSONRPCRequest& request);
UniValue omni_senddexsell(const JSONRPCRequest& request);
UniValue omni_senddexaccept(const JSONRPCRequest& request);
UniValue omni_sendissuancecrowdsale(const JSONRPCRequest& request);
UniValue omni_sendissuancefixed(const JSONRPCRequest& request);
UniValue omni_sendissuancemanaged(const JSONRPCRequest& request);
UniValue omni_sendsto(const JSONRPCRequest& request);
UniValue omni_sendgrant(const JSONRPCRequest& request);
UniValue omni_sendrevoke(const JSONRPCRequest& request);
UniValue omni_sendclosecrowdsale(const JSONRPCRequest& request);
UniValue trade_MP(const JSONRPCRequest& request);
UniValue omni_sendtrade(const JSONRPCRequest& request);
UniValue omni_sendcanceltradesbyprice(const JSONRPCRequest& request);
UniValue omni_sendcanceltradesbypair(const JSONRPCRequest& request);
UniValue omni_sendcancelalltrades(const JSONRPCRequest& request);
UniValue omni_sendchangeissuer(const JSONRPCRequest& request);
UniValue omni_sendactivation(const JSONRPCRequest& request);
UniValue omni_sendalert(const JSONRPCRequest& request);

#endif // OMNICORE_RPCTX
