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

int main(int argc, char* argv[])
{
    RPC_STATUS status;
    RPC_WSTR pszUuid = NULL;
    RPC_WSTR pszProtocolSequence = (RPC_WSTR)L"ncacn_ip_tcp";
    RPC_WSTR pszNetworkAddress = NULL;
    RPC_WSTR pszEndpoint = NULL;
    RPC_WSTR pszOptions = NULL;
    RPC_WSTR pszStringBinding = NULL;
    unsigned long ulCode;

    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " <Server Name> <Hello Text>" << std::endl;
        return 1;
    }

    wchar_t netAddr[255];
    int wchars_num = MultiByteToWideChar(CP_UTF8, 0, argv[1], -1, NULL, 0);
    wchar_t* wargv = new wchar_t[wchars_num];
    MultiByteToWideChar(CP_UTF8, 0, argv[1], -1, wargv, wchars_num);

    wcscpy_s(netAddr, 255, wargv);      // Copy Network Address to Heap
    pszNetworkAddress = (RPC_WSTR)netAddr;
    delete[] wargv;

    status = RpcStringBindingCompose(pszUuid,
        pszProtocolSequence,
        pszNetworkAddress,
        pszEndpoint,
        pszOptions,
        &pszStringBinding);
    PrintRpcStatus("RpcStringBindingCompose", status);
    std::cout << "Connecting " << argv[1] << std::endl;
    
    status = RpcBindingFromStringBinding(pszStringBinding, &RpcDemo_Binding);
    PrintRpcStatus("RpcBindingFromStringBinding", status);

    RpcTryExcept
    {
        if (strcmp(argv[2], "SHUTDOWN") == 0)
        {
            Shutdown();
        }
        else
        {
            Hello((unsigned char*)argv[2]);
        }
    }
        RpcExcept(1)
    {
        ulCode = RpcExceptionCode();
        std::cout << "RPC Exception: " << ulCode << std::endl;
    }
    RpcEndExcept;

    status = RpcStringFree(&pszStringBinding);
    PrintRpcStatus("RpcStringFree", status);
    status = RpcBindingFree(&RpcDemo_Binding);
    PrintRpcStatus("RpcBindingFree", status);

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
