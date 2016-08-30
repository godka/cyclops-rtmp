#pragma once
#include "MythConfig.hh"
#include <stdio.h>
#include <stdlib.h>
#include "librtmp/rtmp.h"   
#include "librtmp/rtmp_sys.h"   
#include "librtmp/amf.h"  
#ifdef WIN32     
#include <windows.h>  
#pragma comment(lib,"WS2_32.lib")   
#pragma comment(lib,"winmm.lib")  
#endif 
#include <string>
using namespace std;
//�����ͷ���ȣ�RTMP_MAX_HEADER_SIZE=18
#define RTMP_HEAD_SIZE   (sizeof(RTMPPacket)+RTMP_MAX_HEADER_SIZE)
//�洢Nal��Ԫ���ݵ�buffer��С
#define BUFFER_SIZE 4096
//��ѰNal��Ԫʱ��һЩ��־
#define GOT_A_NAL_CROSS_BUFFER BUFFER_SIZE+1
#define GOT_A_NAL_INCLUDE_A_BUFFER BUFFER_SIZE+2
#define NO_MORE_BUFFER_TO_READ BUFFER_SIZE+3

/**
* _NaluUnit
* �ڲ��ṹ�塣�ýṹ����Ҫ���ڴ洢�ʹ���Nal��Ԫ�����͡���С������
*/
typedef struct _NaluUnit
{
	int type;
	int size;
	unsigned char *data;
}NaluUnit;

/**
* _RTMPMetadata
* �ڲ��ṹ�塣�ýṹ����Ҫ���ڴ洢�ʹ���Ԫ������Ϣ
*/
typedef struct _RTMPMetadata
{
	// video, must be h264 type   
	unsigned int    nWidth;
	unsigned int    nHeight;
	unsigned int    nFrameRate;
	unsigned int    nSpsLen;
	unsigned char   *Sps;
	unsigned int    nPpsLen;
	unsigned char   *Pps;
} RTMPMetadata, *LPRTMPMetadata;

enum
{
	VIDEO_CODECID_H264 = 7,
};

typedef  unsigned int UINT;
typedef  unsigned char BYTE;
typedef  unsigned long DWORD;

class mythVirtualRTMP
{
public:
	static mythVirtualRTMP* CreateNew(const char* url){
		return new mythVirtualRTMP(url);
	}
	int Start();
	~mythVirtualRTMP();
protected:
	mythVirtualRTMP(const char* url);
	virtual int read_buffer(unsigned char *buf, int buf_size);
	UINT Ue(BYTE *pBuff, UINT nLen, UINT &nStartBit);
	int Se(BYTE *pBuff, UINT nLen, UINT &nStartBit);
	DWORD u(UINT BitCount, BYTE * buf, UINT &nStartBit);
	void de_emulation_prevention(BYTE* buf, unsigned int* buf_size);
	int h264_decode_sps(BYTE * buf, unsigned int nLen, int &width, int &height, int &fps);
private:
	int RTMP264_Connect(const char* url);
	int RTMP264_Send();
	void RTMP264_Close();
	int ReadOneNaluFromBuf(NaluUnit &nalu);
	int SendH264Packet(unsigned char *data, unsigned int size, int bIsKeyFrame, unsigned int nTimeStamp);
	int ReadFirstNaluFromBuf(NaluUnit &nalu);
	int SendVideoSpsPps(unsigned char *pps, int pps_len, unsigned char * sps, int sps_len);
	int SendPacket(unsigned int nPacketType, unsigned char *data, unsigned int size, unsigned int nTimestamp);
	unsigned int  m_nFileBufSize;
	unsigned int  nalhead_pos;
	RTMP* m_pRtmp;
	RTMPMetadata metaData;
	unsigned char *m_pFileBuf;
	unsigned char *m_pFileBuf_tmp;
	unsigned char* m_pFileBuf_tmp_old;	//used for realloc
	string rtmpurl;
	inline int InitSockets()
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

	/**
	* �ͷ�winsock
	*
	* @�ɹ��򷵻�0 , ʧ���򷵻���Ӧ�������
	*/
	inline void CleanupSockets()
	{
#ifdef WIN32     
		WSACleanup();
#endif     
	}
};

