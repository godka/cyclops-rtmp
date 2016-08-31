#include "dll.h"
#include "mythStreamRTMP.hh"
HBAPI void* MYTHAPI RTMPInit(char* rtmplink){
	mythStreamRTMP* streamrtmp = mythStreamRTMP::CreateNew(rtmplink);
	return streamrtmp;
}

HBAPI int MYTHAPI RTMPStart(void* ptr){
	if (ptr){
		mythStreamRTMP* streamrtmp = (mythStreamRTMP*) ptr;
		streamrtmp->Start();
		return 0;
	}
	return 1;
}

HBAPI int MYTHAPI RTMPPutH264Data(void* ptr,char* data,int len){
	if (ptr){
		mythStreamRTMP* streamrtmp = (mythStreamRTMP*) ptr;
		streamrtmp->put((unsigned char*)data, len);
		return 0;
	}
	return 1;
}

HBAPI int MYTHAPI RTMPClose(void* ptr){
	if (ptr){
		mythStreamRTMP* streamrtmp = (mythStreamRTMP*) ptr;
		streamrtmp->isPushing = false;
		//delete streamrtmp;
		return 0;
	}
	return 1;
}