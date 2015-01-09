/*

$ ./a.out -a 1234 -b432 -c -d
optind:3
optarg:1234
ch:a
option a:'1234'
optopt+
=======
optind:4
optarg:432
ch:b
option b:'432'
optopt+
=======
optind:5
optarg:(null)
ch:c
option c
optopt+
=======
optind:6
optarg:(null)
ch:d
option d
optopt+
=======

 */
#include <stdio.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
  int ch;
  opterr=0;
  
  while((ch=getopt(argc,argv,"a:b::cde"))!=-1)
  {
    printf("optind:%d\n",optind);
    printf("optarg:%s\n",optarg);
    printf("ch:%c\n",ch);
    switch(ch)
    {
      case 'a':
        printf("option a:'%s'\n",optarg);
        break;
      case 'b':
        printf("option b:'%s'\n",optarg);
        break;
      case 'c':
        printf("option c\n");
        break;
      case 'd':
        printf("option d\n");
        break;
      case 'e':
        printf("option e\n");
        break;
      default:
        printf("other option:%c\n",ch);
    }
    printf("optopt+%c\n",optopt);
	printf("=======\n");
  }

}    
