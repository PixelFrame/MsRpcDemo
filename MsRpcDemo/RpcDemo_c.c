

/* this ALWAYS GENERATED file contains the RPC client stubs */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for RpcDemo.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_)


#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#include <string.h>

#include "RpcDemo_h.h"

#define TYPE_FORMAT_STRING_SIZE   7                                 
#define PROC_FORMAT_STRING_SIZE   91                                
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _RpcDemo_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } RpcDemo_MIDL_TYPE_FORMAT_STRING;

typedef struct _RpcDemo_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } RpcDemo_MIDL_PROC_FORMAT_STRING;

typedef struct _RpcDemo_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } RpcDemo_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const RpcDemo_MIDL_TYPE_FORMAT_STRING RpcDemo__MIDL_TypeFormatString;
extern const RpcDemo_MIDL_PROC_FORMAT_STRING RpcDemo__MIDL_ProcFormatString;
extern const RpcDemo_MIDL_EXPR_FORMAT_STRING RpcDemo__MIDL_ExprFormatString;

#define GENERIC_BINDING_TABLE_SIZE   0            


/* Standard interface: RpcDemo, ver. 1.0,
   GUID={0x89a2a56f,0x0bd9,0x4c5f,{0x9c,0xc1,0x92,0xad,0x65,0xc3,0x8a,0x19}} */

handle_t RpcDemo_Binding;


static const RPC_CLIENT_INTERFACE RpcDemo___RpcClientInterface =
    {
    sizeof(RPC_CLIENT_INTERFACE),
    {{0x89a2a56f,0x0bd9,0x4c5f,{0x9c,0xc1,0x92,0xad,0x65,0xc3,0x8a,0x19}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    0,
    0,
    0,
    0,
    0x00000000
    };
RPC_IF_HANDLE RpcDemo_v1_0_c_ifspec = (RPC_IF_HANDLE)& RpcDemo___RpcClientInterface;

extern const MIDL_STUB_DESC RpcDemo_StubDesc;

static RPC_BINDING_HANDLE RpcDemo__MIDL_AutoBindHandle;


void Hello( 
    /* [string][in] */ const unsigned char *psz)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&RpcDemo_StubDesc,
                  (PFORMAT_STRING) &RpcDemo__MIDL_ProcFormatString.Format[0],
                  ( unsigned char * )&psz);
    
}


int ConnTest( 
    /* [string][in] */ const unsigned char *psz)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&RpcDemo_StubDesc,
                  (PFORMAT_STRING) &RpcDemo__MIDL_ProcFormatString.Format[30],
                  ( unsigned char * )&psz);
    return ( int  )_RetVal.Simple;
    
}


void Shutdown( void)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&RpcDemo_StubDesc,
                  (PFORMAT_STRING) &RpcDemo__MIDL_ProcFormatString.Format[66],
                  ( unsigned char * )0);
    
}


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif
#if !(TARGET_IS_NT60_OR_LATER)
#error You need Windows Vista or later to run this stub because it uses these features:
#error   compiled for Windows Vista.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const RpcDemo_MIDL_PROC_FORMAT_STRING RpcDemo__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Hello */

			0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* 0 */
/* 14 */	0x42,		/* Oi2 Flags:  clt must size, has ext, */
			0x1,		/* 1 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter psz */

/* 24 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 26 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 28 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Procedure ConnTest */

/* 30 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 32 */	NdrFcLong( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0x1 ),	/* 1 */
/* 38 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 40 */	NdrFcShort( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 46 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter psz */

/* 54 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 56 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 58 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Return value */

/* 60 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Shutdown */

/* 66 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 68 */	NdrFcLong( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x2 ),	/* 2 */
/* 74 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 76 */	NdrFcShort( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x0 ),	/* 0 */
/* 80 */	0x40,		/* Oi2 Flags:  has ext, */
			0x0,		/* 0 */
/* 82 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 84 */	NdrFcShort( 0x0 ),	/* 0 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };

static const RpcDemo_MIDL_TYPE_FORMAT_STRING RpcDemo__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  4 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static const unsigned short RpcDemo_FormatStringOffsetTable[] =
    {
    0,
    30,
    66
    };


static const MIDL_STUB_DESC RpcDemo_StubDesc = 
    {
    (void *)& RpcDemo___RpcClientInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    &RpcDemo_Binding,
    0,
    0,
    0,
    0,
    RpcDemo__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x60001, /* Ndr library version */
    0,
    0x801026e, /* MIDL Version 8.1.622 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_) */

