/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:39:00 by ncolomer          #+#    #+#             */
/*   Updated: 2019/11/07 14:51:58 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int
	test_line(char const *filename, int fd, char **buffer)
{
	int	r;

	r = get_next_line(fd, buffer);
	printf("[%-23s]%2d-%s\n", filename, r, *buffer);
	if (*buffer)
		free(*buffer);
	*buffer = NULL;
	return (r);
}

int
	main(void)
{
	char		*buffer = NULL;
	int			i, j;
	int			test_count;
	char const	*tests[100] = {
		"tests/lorem_ipsum",
		"tests/simple",
		"tests/empty",
		"tests/empty_one",
		"tests/multi_in_one",
		"tests/many_lines", // 5
		"tests/over_buffer",
		"tests/63_line",
		"tests/63_line_nl",
		"tests/64_line",
		"tests/64_line_nl", // 10
		"tests/65_line",
		"tests/65_line_nl",
		"tests/baudelaire",
		"tests/large_file",
		"tests/long_line", // 15
		"get_next_line.c",
		"get_next_line_utils.c",
		"get_next_line.h",
		//"/dev/random",
		NULL
	};
	int			fds[100];
	int			line_bk[100];
	int			line_bk_s[100];

	test_count = 0;
	while (tests[test_count])
		fds[test_count++] = -42;

	// Open
	i = 0;
	while (i < test_count)
	{
		fds[i] = open(tests[i], O_RDONLY);
		line_bk[i] = 0;
		line_bk_s[i] = 0;
		i++;
	}

	// Test
	printf("*********************\n* BUFFER_SIZE %5d *\n*********************\n", BUFFER_SIZE);

	i = 0;
	while (i < 100)
	{
		j = (i % 8) % test_count;
		line_bk[j] += test_line(tests[j], fds[j], &buffer);
		line_bk_s[j]++;

		j = (i % 20) % test_count;
		line_bk[j] += test_line(tests[j], fds[j], &buffer);
		line_bk_s[j]++;

		j = (i % 36) % test_count;
		line_bk[j] += test_line(tests[j], fds[j], &buffer);
		line_bk_s[j]++;

		if (i % 50 == 0)
			test_line("STDIN", STDIN_FILENO, &buffer);
		if (i % 80 == 0)
			test_line("Invalid file descriptor", 4242, &buffer);
		i++;
	}

	// Large file
	i = 0;
	while (i < 500)
	{
		line_bk[14] += test_line(tests[14], fds[14], &buffer);
		line_bk_s[14]++;
		i++;
	}

	// Returned 0 and total get_next_line calls for each tests
	i = 0;
	while (i < test_count)
	{
		printf("[%-23s] lines: %3d (%d)\n", tests[i], line_bk[i], line_bk_s[i]);
		i++;
	}

	// Close
	i = 0;
	while (i < test_count)
		close(fds[i++]);

	return (0);
}
