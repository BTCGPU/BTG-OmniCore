#ifndef OMNICORE_RPCRAWTX_H
#define OMNICORE_RPCRAWTX_H

#include "rpc/server.h"
#include <univalue.h>

// UniValue omni_decodetransaction(const UniValue& params, bool fHelp);
UniValue omni_createrawtx_opreturn(const JSONRPCRequest& request);
// UniValue omni_createrawtx_multisig(const UniValue& params, bool fHelp);
// UniValue omni_createrawtx_input(const UniValue& params, bool fHelp);
UniValue omni_createrawtx_reference(const JSONRPCRequest& request);
UniValue omni_createrawtx_change(const JSONRPCRequest& request);


#endif // OMNICORE_RPCRAWTX_H
