#include "SqString.h"

namespace SqString {

void Assign(SqString &s, char const str[]) {
    int i = 0;
    while (str[i] != '\0') {
        s.data[i] = str[i];
        i++;
    }
    s.length = i;
}

void DestroyStr(SqString s) {}

void StrCopy(SqString &s, SqString t) {
    int i;
    for (i = 0; i < t.length; i++) {
        s.data[i] = t.data[i];
    }
    s.length = t.length;
}

size_t StrLength(SqString s) {
    return s.length;
}

bool StrEqual(SqString s, SqString t) {
    int i = 0;
    if (s.length != t.length) {
        return false;
    } else {
        for (i = 0; i < s.length; i++) {
            if (s.data[i] != t.data[i]) {
                return false;
            }
        }
        return true;
    }
}

SqString Concat(SqString s, SqString t) {
    SqString r;
    int i, j;
    for (i = 0; i < s.length; i++) {
        r.data[i] = s.data[i];
    }
    for (j = 0; i < t.length; j++) {
        r.data[s.length + j] = t.data[j];
    }
    r.length = i + j;
    return r;
}

SqString SubStr(SqString s,int i,int j) {
   SqString t;
   int k;
   if (i < 1 || i > s.length || j < 1 || i + j > s.length + 1)
       t.length = 0;    //参数错误时返回空串
   else {
       for (k = i - 1; k < i + j; k++) {
           t.data[k - i + 1] = s.data[k];
       }
       t.length = j;
   }
   return t;
}

size_t Index(SqString s, SqString t) {
    int i = 0, j = 0;
    while (i < s.length && j < t.length) {
        if (s.data[i] == t.data[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
   }
   if (j >= t.length) 
       return i - t.length + 1; //返回第一个字符的位置
   else
       return 0;        //返回0
}

// 呃呃()

int InsStr(SqString &s, int i, SqString t) {
    int j;
    if (i < 1 || i > s.length+1)
        return -1;
    else {
        for (j=s.length-1;j>=i-1;j--)
            s.data[j+t.length]=s.data[j];
        for (j=0;j<t.length;j++)
            s.data[i+j-1]=t.data[j];
        s.length=s.length+t.length;
        return 0;
    }
}

int DelStr(SqString &s, int i, int j) {
    int k;
    if (i<1 || i>s.length || j<1 || i+j>s.length+1)
        return 0;
    else {
        for(k=i+j-1;k<s.length;k++)
            s.data[k-j]=s.data[k];
        s.length=s.length-j;
        return 1;
    }
}

SqString RepStrAll(SqString s,SqString s1,SqString s2)
{  int i;
   i=Index(s,s1);
   while (i>0)
   {	DelStr(s,i,s1.length);	//删除子串s1
	InsStr(s,i,s2);		//插入子串s2
	i=Index(s,s1);
   }
   return s;
}

void DispStr(SqString s)
{  int i;
   for (i=0;i<s.length;i++)
	printf("%c",s.data[i]);
   printf("\n");
}

} // SqString
