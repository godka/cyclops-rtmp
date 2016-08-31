#pragma once
#include "mythVirtualRTMP.hh"
#include "mythAvlist.hh"
class mythStreamRTMP :
	public mythVirtualRTMP,public mythAvlist
{
public:	
	static mythStreamRTMP* CreateNew(const char* url){
		return new mythStreamRTMP(url);
	}
	virtual int read_buffer(unsigned char *buf, int buf_size);
	~mythStreamRTMP();
protected:
	mythStreamRTMP(const char* url);
};

