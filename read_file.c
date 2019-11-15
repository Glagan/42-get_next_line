/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:20:50 by ncolomer          #+#    #+#             */
/*   Updated: 2019/11/15 12:26:10 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int
	main(void)
{
	int		r;
	char	*line;

	line = NULL;
	while ((r = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	if (r >= 0)
	{
		printf("%s", line);
		free(line);
		line = NULL;
	}
	return (0);
}
