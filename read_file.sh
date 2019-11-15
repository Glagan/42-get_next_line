if [ $# -ge 2 ]; then
	rm -f read_file
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$1 -I. get_next_line.c get_next_line_utils.c read_file.c -o read_file
	if [ $2 = "/dev/random" ]; then
		./read_file	< $2
	else
		./read_file < $2 | cat -e > y
		cat -e $2 > r
		if [ $# -eq 3 ]; then
			diff -y r y
		else
			diff -y --suppress-common-lines r y
		fi
	fi
	rm -f read_file y r
else
	echo "bash read_file.sh BUFFER_SIZE PATH"
fi
