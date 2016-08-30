#include <stdio.h>
#include "librtmp_send264.h"
#include "MythConfig.hh"
#include "mythStreamDecoder.hh"
mythVirtualDecoder* decoder;
int read_buffer1(unsigned char *buf, int buf_size ){
	return decoder->get(buf, buf_size);
}

int main(int argc, char* argv[])
{
	//fp_send1 = fopen("test.h264", "rb");
	decoder = mythStreamDecoder::CreateNew("192.168.31.103", 1017);
	decoder->start();
	//��ʼ�������ӵ�������
	RTMP264_Connect("rtmp://localhost:1935/live/stream");
	
	//����
	RTMP264_Send(read_buffer1);

	//�Ͽ����Ӳ��ͷ������Դ
	RTMP264_Close();

	return 0;
}

