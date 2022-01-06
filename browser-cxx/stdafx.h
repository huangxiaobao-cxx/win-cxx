#pragma once
//stdfax.h:
#define STRICT
#define WIN32_LEAN_AND_MEAN
//#define _WTL_USE_CSTRING
#define _WTYPES_NS


#include <atlbase.h>  
#include <atlapp.h>  
extern CAppModule _Module;
#define _WTL_NO_CSTRING  
#include <atlwin.h>  
#include <atlctrls.h>  
#define _WTL_NO_WTYPES
#include <atlframe.h>  
#include <atlmisc.h>  
#include <atlcrack.h>  

#include "gdiplus.h"

#include <memory>

#ifndef TRACE

#define TRACE(format, ...)\
do\
{\
	CString szFormat;\
	szFormat.AppendFormat(format, __VA_ARGS__);\
	OutputDebugString(szFormat);\
}while(0);\


#endif // !TRACE

