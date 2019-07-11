#include "OsApi.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
void sleep_os(uint32_t millionseconds)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	Sleep(millionseconds);
#else
	usleep(millionseconds * 1000);
#endif
}

uint32_t gettickcount_os()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	return GetTickCount();
#else
	uint32_t current_time;
	struct timeval current;
	gettimeofday(&current, NULL);
	current_time = current.tv_sec * 1000 + current.tv_usec/1000;

	return current_time;

#endif
}
/////////////////////////////////////////////////////////////////////////////////////////////////