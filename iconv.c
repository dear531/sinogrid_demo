#include <iconv.h>
#include <stdio.h>
int main(void)
{
	char inbuff[] = "12345", outbuf[] = "abcdefghijk";
	iconv_t cd = (iconv_t)-1;
	cd = iconv_open("GBK", "UTF-8");
#if 0
       size_t iconv(iconv_t cd,
                    char **inbuf, size_t *inbytesleft,
                    char **outbuf, size_t *outbytesleft);
#endif
	char *pin = inbuff, *pout = outbuf;
	size_t inlen = sizeof(inbuff), outlen = sizeof(outbuf);
	iconv(cd, &pin, &inlen, &pout, &outlen);
	fprintf(stdout, "outbuff:%s\n", outbuf);
	int i = 0;
	for (i = 0; sizeof(outbuf) > i; i++)
	{
		fprintf(stdout, "outbuf[%d]%c\n", i, outbuf[i]);
	}
	if ((iconv_t)-1 != cd)
	{
		iconv_close(cd);
		cd = (iconv_t)-1;
	}
	return 0;
}
