#/bin/bash
#因为文件有时候可能是多个，所以FNR表示文件中的序号，会根据文件变化重新开始计数
#而输入流的序号则不会发生变化，一直累加
awk	'{
		sum = 0;
		print NF, NR, FNR;
		print "";
	}' tmp1.txt tmp1.txt

