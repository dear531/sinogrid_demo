#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	FILE	*fp;
	char	buf[1024];
	char	*command = NULL;
#if 0
	command	= "ls";
#else
	command	= "snmpwalk -v 3 -l authNoPriv -u zhangliuying -a MD5 -A zhangliuying 192.168.12.78 .1.3.6.1.4.1.99999.16";
#endif
	fp		= popen(command, "r");
	while (memset(buf, 0x00, sizeof(buf)), fgets(buf, sizeof(buf), fp) != NULL){
		fprintf(stdout, "%s", buf);
	}
	pclose(fp);

	return 0;
}
