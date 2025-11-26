#pragma once
#include <cstdio>

namespace SqString {

size_t const MaxSize = 100;

struct SqString {
    char data[MaxSize];
    size_t length;
};

void Assign(SqString &s,char const str[]);
void DestroyStr(SqString s);
void StrCopy(SqString &s, SqString t);
void Assign(SqString &s, char str[]);
void DestroyStr(SqString s) ;
void StrCopy(SqString &s, SqString t);
size_t StrLength(SqString s);
bool StrEqual(SqString s, SqString t);
SqString Concat(SqString s, SqString t);
SqString SubStr(SqString s,int i,int j);
size_t Index(SqString s, SqString t);
int InsStr(SqString &s, int i, SqString t);
int DelStr(SqString &s, int i, int j);
SqString RepStrAll(SqString s,SqString s1,SqString s2);
void DispStr(SqString s);

} // SqString
