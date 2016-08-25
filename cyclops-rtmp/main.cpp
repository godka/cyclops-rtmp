/**
 * Simplest Librtmp Send 264
 *
 * �����裬����
 * leixiaohua1020@126.com
 * zhanghuicuc@gmail.com
 * �й���ý��ѧ/���ֵ��Ӽ���
 * Communication University of China / Digital TV Technology
 * http://blog.csdn.net/leixiaohua1020
 *
 * ���������ڽ��ڴ��е�H.264����������RTMP��ý���������
 * This program can send local h264 stream to net server as rtmp live stream.
 */

#include <stdio.h>
#include "librtmp_send264.h"
#include "MythConfig.hh"
#include "mythStreamDecoder.hh"
mythVirtualDecoder* decoder;
FILE *fp_send1;

//���ļ��Ļص�����
//we use this callback function to read data from buffer
int read_buffer1(unsigned char *buf, int buf_size ){
	return decoder->get(buf, buf_size);
}

int main(int argc, char* argv[])
{
	//fp_send1 = fopen("test.h264", "rb");
	decoder = mythStreamDecoder::CreateNew("120.204.70.218", 1049);
	decoder->start();
	//��ʼ�������ӵ�������
	RTMP264_Connect("rtmp://localhost:1935/live/stream");
	
	//����
	RTMP264_Send(read_buffer1);

	//�Ͽ����Ӳ��ͷ������Դ
	RTMP264_Close();

	return 0;
}

