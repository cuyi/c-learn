#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

#ifndef THREAD_LOCAL_TMP_BUF_SIZE
#define THREAD_LOCAL_TMP_BUF_SIZE 20
#endif

namespace utils{

inline const char* printInternal( const char* text, const int value){
	static __thread char buf[THREAD_LOCAL_TMP_BUF_SIZE] = {0};
	::std::snprintf(buf, THREAD_LOCAL_TMP_BUF_SIZE, "%s%i", text, (int)(value));
	return buf;
}

inline const char* printRawUnknowValue(const int v){
	return printInternal("ERROR: ", v);
}
}
