#include <stdio.h>
#include <string.h>
#include <iconv.h>

#define OUTLEN 255

int main()
{
	char *in_utf8 = "姝ｅ?ㄥ??瑁?";
	char *in_gb2312 = "正在安装";
	char out[OUTLEN];
	int rc;
	in_utf8 = "1234567890";
	in_gb2312 = "0987654321";
	
	memset(out, 0x00, OUTLEN);
	//unicode码转为gb2312码
	rc = u2g(in_utf8,strlen(in_utf8),out,OUTLEN);
	printf("unicode-->gb2312 out=%s, out length :%ld\n",out, strlen(out));

	memset(out, 0x00, OUTLEN);
	//gb2312码转为unicode码
	rc = g2u(in_gb2312,strlen(in_gb2312),out,OUTLEN);
	printf("gb2312-->unicode out=%s, out length :%ld\n",out, strlen(out));
}
//代码转换:从一种编码转为另一种编码
int code_convert(char *from_charset,char *to_charset,char*inbuf,int inlen,char *outbuf,int outlen)
{
	iconv_t cd;
	int rc;
	char **pin = &inbuf;
	char **pout = &outbuf;

	cd = iconv_open(to_charset,from_charset);
	if (cd==0) return -1;
	memset(outbuf,0,outlen);
#if 0
       size_t iconv(iconv_t cd,
                    char **inbuf, size_t *inbytesleft,
                    char **outbuf, size_t *outbytesleft);
#endif
	if(iconv(cd,pin,(size_t *)&inlen,pout,(size_t *)&outlen)==-1)return -1;
	iconv_close(cd);
	return 0;
}
//UNICODE码转为GB2312码
int u2g(char *inbuf,int inlen,char *outbuf,int outlen)
{
	return code_convert("utf-8","gb2312",inbuf,inlen,outbuf,outlen);
}
//GB2312码转为UNICODE码
int g2u(char *inbuf,size_t inlen,char *outbuf,size_t outlen)
{
	return code_convert("gb2312","utf-8",inbuf,inlen,outbuf,outlen);
}

