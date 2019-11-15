rm -f get_next_line_bonus
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=64 -I. get_next_line_bonus.c get_next_line_utils_bonus.c test_bonus.c -o get_next_line_bonus
./get_next_line_bonus < tests/lorem_ipsum
rm -f get_next_line_bonus