#pragma once
#include "MythConfig.hh"
#include <stdio.h>
#include <stdlib.h>
#include "librtmp_send264.h"
#include "librtmp/rtmp.h"   
#include "librtmp/rtmp_sys.h"   
#include "librtmp/amf.h"  
#include "sps_decode.h"
#define RTMP_HEAD_SIZE   (sizeof(RTMPPacket)+RTMP_MAX_HEADER_SIZE)
//存储Nal单元数据的buffer大小
#define BUFFER_SIZE 4096
//搜寻Nal单元时的一些标志
#define GOT_A_NAL_CROSS_BUFFER BUFFER_SIZE+1
#define GOT_A_NAL_INCLUDE_A_BUFFER BUFFER_SIZE+2
#define NO_MORE_BUFFER_TO_READ BUFFER_SIZE+3
#ifdef WIN32     
#include <windows.h>  
#pragma comment(lib,"WS2_32.lib")   
#pragma comment(lib,"winmm.lib")  
#endif 

class mythVirtualRTMP
{
public:
	mythVirtualRTMP(const char* url);
	~mythVirtualRTMP();
protected:
	virtual int read_buffer(unsigned char *buf, int buf_size);
private:
	int RTMP264_Connect(const char* url);
	int RTMP264_Send();
	void RTMP264_Close();


	unsigned int  m_nFileBufSize;
	unsigned int  nalhead_pos;
	RTMP* m_pRtmp;
	RTMPMetadata metaData;
	unsigned char *m_pFileBuf;
	unsigned char *m_pFileBuf_tmp;
	unsigned char* m_pFileBuf_tmp_old;	//used for realloc

	int InitSockets()
	{
#ifdef WIN32     
		WORD version;
		WSADATA wsaData;
		version = MAKEWORD(1, 1);
		return (WSAStartup(version, &wsaData) == 0);
#else     
		return TRUE;
#endif     
	}
};

