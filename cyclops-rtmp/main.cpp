#include "mythStreamRTMP.hh"
int main(int argc, char* argv[])
{
	auto t = mythStreamRTMP::CreateNew("rtmp://localhost/live/stream");
	t->Start();
	return 0;
}

