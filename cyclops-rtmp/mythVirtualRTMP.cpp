#include "mythVirtualRTMP.hh"


mythVirtualRTMP::mythVirtualRTMP(const char* url)
{
}


mythVirtualRTMP::~mythVirtualRTMP()
{
}

int mythVirtualRTMP::RTMP264_Connect(const char* url)
{
	nalhead_pos = 0;
	m_nFileBufSize = BUFFER_SIZE;
	m_pFileBuf = (unsigned char*) malloc(BUFFER_SIZE);
	m_pFileBuf_tmp = (unsigned char*) malloc(BUFFER_SIZE * 10);
	InitSockets();

	m_pRtmp = RTMP_Alloc();
	RTMP_Init(m_pRtmp);
	/*����URL*/
	if (RTMP_SetupURL(m_pRtmp, (char*) url) == FALSE)
	{
		RTMP_Free(m_pRtmp);
		return false;
	}
	/*���ÿ�д,��������,�����������������ǰʹ��,������Ч*/
	RTMP_EnableWrite(m_pRtmp);
	/*���ӷ�����*/
	if (RTMP_Connect(m_pRtmp, NULL) == FALSE)
	{
		RTMP_Free(m_pRtmp);
		return false;
	}

	/*������*/
	if (RTMP_ConnectStream(m_pRtmp, 0) == FALSE)
	{
		RTMP_Close(m_pRtmp);
		RTMP_Free(m_pRtmp);
		return false;
	}
	return true;
}

int mythVirtualRTMP::RTMP264_Send()
{

}

void mythVirtualRTMP::RTMP264_Close()
{

}
