#include "mythStreamRTMP.hh"




mythStreamRTMP::mythStreamRTMP(const char* url)
	:mythVirtualRTMP(url), mythAvlist(10)
{
}

int mythStreamRTMP::read_buffer(unsigned char *buf, int buf_size)
{
	return get(buf, buf_size);
}

mythStreamRTMP::~mythStreamRTMP()
{
}
