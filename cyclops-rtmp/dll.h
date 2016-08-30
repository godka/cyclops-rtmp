#pragma once
//#include <Windows.h>
#ifdef _MSC_VER 
#define MYTHAPI _stdcall
#ifdef __cplusplus
#define HBAPI extern "C" __declspec (dllexport)
#else
#define HBAPI __declspec (dllexport)
#endif
#else
#define HBAPI
#define  MYTHAPI
#endif

HBAPI void* MYTHAPI RTMPInit(char* rtmplink);
HBAPI int MYTHAPI BigPotInputVideo(void* handle, char* filename);
HBAPI int MYTHAPI BigPotSeek(void* handle, int seek);
HBAPI int MYTHAPI BigPotClose(void* handle);