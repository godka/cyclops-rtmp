#include "mythSimpleRTMP.hh"
int main(int argc, char* argv[])
{
	auto t = mythSimpleRTMP::CreateNew("rtmp://localhost/live/stream");
	t->Start();
	return 0;
}

