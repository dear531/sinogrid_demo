awk	'{
		sum = 0;
		for (i = 1; i <= NF; i++) {
			if (i == 2) {
				printf "%d", $i;
			} else if (i % 2 == 0) {
				printf " %d", $i;
			}
		}
		print "";
	}' tmp1.txt

