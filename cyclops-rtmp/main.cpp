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
	//初始化并连接到服务器
	RTMP264_Connect("rtmp://localhost:1935/live/stream");
	
	//发送
	RTMP264_Send(read_buffer1);

	//断开连接并释放相关资源
	RTMP264_Close();

	return 0;
}

