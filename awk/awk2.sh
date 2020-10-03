awk	'{
		sum = 0;
		print NF, NR, FNR;
		print "";
	}' tmp1.txt tmp1.txt

