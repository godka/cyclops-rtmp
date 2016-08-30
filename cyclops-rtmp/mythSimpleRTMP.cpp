#include "mythSimpleRTMP.hh"


mythSimpleRTMP::mythSimpleRTMP(const char* url)
	:mythVirtualRTMP(url)
{
	decoder = mythStreamDecoder::CreateNew("120.204.70.218", 1017);
	decoder->start();
}


mythSimpleRTMP::~mythSimpleRTMP()
{
}

int mythSimpleRTMP::read_buffer(unsigned char *buf, int buf_size)
{
	return decoder->get(buf, buf_size);
}
