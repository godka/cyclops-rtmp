#pragma once
#include "mythVirtualRTMP.hh"
#include "mythStreamDecoder.hh"
class mythSimpleRTMP :
	public mythVirtualRTMP
{
public:
	static mythSimpleRTMP* CreateNew(const char* url){
		return new mythSimpleRTMP(url);
	}
	~mythSimpleRTMP();
	virtual int read_buffer(unsigned char *buf, int buf_size);
protected:
	mythSimpleRTMP(const char* url);
private:
	mythVirtualDecoder* decoder;
};

