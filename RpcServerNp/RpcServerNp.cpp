#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "..\MsRpcDemo\RpcDemo_h.h"

#pragma comment(lib, "Rpcrt4.lib")

void PrintRpcStatus(const char* function, RPC_STATUS status)
{
    std::cout << "Entering: " << std::left << std::setw(25) << function
        << "-> RPC Status: " << status << std::endl;
    if (status)
    {
        std::cout << "Exiting on error..." << std::endl;
        exit(status);
    }
}

void Hello(const unsigned char* psz)
{
    std::cout << "Get Message From Client: " << psz << std::endl;
}

void Shutdown(void)
{
    RPC_STATUS status;

    status = RpcMgmtStopServerListening(NULL);
    PrintRpcStatus("RpcMgmtStopServerListening", status);
    
    status = RpcServerUnregisterIf(NULL, NULL, FALSE);
    PrintRpcStatus("RpcServerUnregisterIf", status);
}

int main(int argc, char* argv[])
{
    RPC_STATUS status;
    RPC_WSTR pszProtocolSequence = (RPC_WSTR)L"ncacn_np";
    RPC_WSTR pszSecurity = NULL;
    RPC_WSTR pszEndpoint = (RPC_WSTR)L"\\pipe\\RpcDemo";
    unsigned int cMinCalls = 1;
    unsigned int fDontWait = FALSE;

    status = RpcServerUseProtseqEp(pszProtocolSequence, 20, pszEndpoint, pszSecurity);
    PrintRpcStatus("RpcServerUseProtseqEp", status);
    
    status = RpcServerRegisterIf(RpcDemo_v1_0_s_ifspec, NULL, NULL);
    PrintRpcStatus("RpcServerRegisterIf", status);

    status = RpcServerListen(cMinCalls, 20, fDontWait);
    if(status) PrintRpcStatus("RpcServerListen", status);

    return 0;
}

void __RPC_FAR* __RPC_USER midl_user_allocate(size_t len)
{
    return (malloc(len));
}

void __RPC_USER midl_user_free(void __RPC_FAR* ptr)
{
    free(ptr);
}