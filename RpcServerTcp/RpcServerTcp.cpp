﻿#include <iostream>
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
    std::cout << "Received Message From Client: " << psz << std::endl;
}

int ConnTest(const unsigned char* psz)
{
    std::cout << "Connected by Client: " << psz << std::endl;
    return 0;
}

void Shutdown(void)
{
    std::cout << "Received SHUTDOWN from Client" << std::endl;

    RPC_STATUS status;

    status = RpcMgmtStopServerListening(NULL);
    PrintRpcStatus("RpcMgmtStopServerListening", status);

    status = RpcServerUnregisterIf(NULL, NULL, FALSE);
    PrintRpcStatus("RpcServerUnregisterIf", status);
}

int main(int argc, char* argv[])
{
    RPC_STATUS status;
    RPC_WSTR pszProtocolSequence = (RPC_WSTR)L"ncacn_ip_tcp";
    RPC_WSTR pszSecurity = NULL;
    RPC_WSTR pszEndpoint = NULL;
    RPC_BINDING_VECTOR* rpcBindingVector;
    unsigned int cMinCalls = 1;

    if (argc > 2)
    {
        std::cout << "Usage: " << argv[0] << " [<Port>]" << std::endl;
        exit(1);
    }
    else if(argc > 1)
    {
        int iPort = 0;
        sscanf_s(argv[1], "%d", &iPort);
        if (iPort < 1 || iPort > 65535)
        {
            std::cout << "Invalid Port" << std::endl;
            exit(1);
        }

        wchar_t pszPort[6];
        wsprintf(pszPort, L"%d", iPort);
        pszEndpoint = (RPC_WSTR)pszPort;
    }

    status = RpcServerUseProtseqEp(pszProtocolSequence, 20, pszEndpoint, pszSecurity);
    PrintRpcStatus("RpcServerUseProtseq", status);

    status = RpcServerInqBindings(&rpcBindingVector);
    PrintRpcStatus("RpcServerInqBindings", status);

    status = RpcEpRegister(RpcDemo_v1_0_s_ifspec, rpcBindingVector, NULL, NULL);
    PrintRpcStatus("RpcEpRegister", status);

    status = RpcServerRegisterIfEx(RpcDemo_v1_0_s_ifspec, NULL, NULL, RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH, 20, NULL);
    PrintRpcStatus("RpcServerRegisterIf", status);

    status = RpcServerListen(cMinCalls, 20, FALSE);
    if (status) PrintRpcStatus("RpcServerListen", status);

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