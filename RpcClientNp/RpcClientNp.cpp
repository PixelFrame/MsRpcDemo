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
    RPC_WSTR pszProtocolSequence = (RPC_WSTR)L"ncacn_np";
    RPC_WSTR pszNetworkAddress = NULL;
    RPC_WSTR pszEndpoint = (RPC_WSTR)L"\\pipe\\RpcDemo";
    RPC_WSTR pszOptions = NULL;
    RPC_WSTR pszStringBinding = NULL;
    unsigned long ulCode;

    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <Server Name>" << std::endl;
        return 1;
    }

    if (strcmp(argv[1], ".") == 0)
    {
        status = RpcStringBindingCompose(pszUuid,
            pszProtocolSequence,
            pszNetworkAddress,
            pszEndpoint,
            pszOptions,
            &pszStringBinding);
        PrintRpcStatus("RpcStringBindingCompose", status);
    }
    else
    {
        wchar_t netAddr[255] = L"\\\\";
        int wchars_num = MultiByteToWideChar(CP_UTF8, 0, argv[1], -1, NULL, 0);
        wchar_t* wargv = new wchar_t[wchars_num];
        MultiByteToWideChar(CP_UTF8, 0, argv[1], -1, wargv, wchars_num);

        wcscat_s(netAddr, 255, wargv);
        delete[] wargv;
        pszNetworkAddress = (RPC_WSTR)netAddr;

        status = RpcStringBindingCompose(pszUuid,
            pszProtocolSequence,
            pszNetworkAddress,
            pszEndpoint,
            pszOptions,
            &pszStringBinding);
        PrintRpcStatus("RpcStringBindingCompose", status);
        std::cout << "RPC Server Address: \\\\" << argv[1] << "\\pipe\\RpcDemo" << std::endl;
    }
    status = RpcBindingFromStringBinding(pszStringBinding, &RpcDemo_Binding);
    PrintRpcStatus("RpcBindingFromStringBinding", status);

    RpcTryExcept
    {
        std::cout << "\n# Write your message now. \n  > Input Q/q to exit.\n  > Input SHUTDOWN to close server.\n\n";
        char message[1024] = "\0";
        while (std::cin >> message)
        {
            if (strcmp(message, "SHUTDOWN") == 0)
            {
                Shutdown();
                break;
            }
            if (strcmp(message, "Q") == 0 || strcmp(message, "q") == 0)
            {
                break;
            }
            Hello((unsigned char*)message);
            std::cout << "Message Sent" << std::endl;
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
