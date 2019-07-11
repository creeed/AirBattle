#ifndef _TOOLS_H_
#define  _TOOLS_H_

#include <vector>
#include <string>
#include "cocos2d.h"
#include "cocos-ext.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma comment(lib,"libiconv.lib")
#include "iconv.h"
#else
#include "libiconv/include/iconv.h"
#endif


// URLCode 使用
char Char2Num(char ch);
int URLEncode(const char* str, const int strSize, char* result, const int resultSize);
int URLDecode(const char* str, const int strSize, char* result, const int resultSize);

// GBK UTF 转化
int convert(const char *from_charset, const char *to_charset,  char *gbkStr, size_t inlen, char *outbuf, size_t outlen);
const char* TCN(char *gbkStr);
const char* TCNTCP(char *gbkStr);
const char* TGBK(char *utfStr);

typedef std::vector<std::string> String_Array;
void split(std::string src, const char* token, String_Array& vect);

#endif

