/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:48:19 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/06 11:30:36 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fcntl.h"
#include <stdio.h>
#include <string.h>

/*
	test case
	- wrong fd
	- read error
	- byte zero
	- file with new line and end new line
	- file with out new line
	- long line
	- many line
	- all new line
	- long line no new line
*/

int	main(void)
{
	char	*line = NULL;
	int		fd;

	/* wrong fd */
	fd = -1;
	line = get_next_line(fd);
	if (line != NULL)
	{
		printf ("Error: wrong file describe\n");
		return (-1);
	}
	printf ("wrong file describe: passed\n");

	/* byte zero */
	fd = open("byte_zero", O_RDONLY);
	line = get_next_line(fd);
	if (line != NULL)
	{
		printf ("Error: byte_zero\n");
		return (-1);
	}
	printf ("byte_zero: passed\n");
	close (fd);

	/* file with new line */
	char	*strs[] = {
		"Can I call you baby?\n",
		"Can you be my friend?\n",
		"Can you be my lover up until the very end?\n",
		"Let me show you love, oh, I don't pretend\n",
		"Stick by my side even when the world is givin' in, yeah\n",
		NULL
	};
	fd = open("files/file_with_nl_end_nl", O_RDONLY);
	for (int i = 0; strs[i]; i++){		
		line = get_next_line(fd);
		if (strcmp (line, strs[i]) != 0)
		{
			printf ("Error: file_with_nl_end_nl\n");
			close (fd);
			return (-1);
		}
		free (line);
	}
	close (fd);
	printf ("file with new line: passed\n");

	/* file with new line end no new line */
	strs[4] = "Stick by my side even when the world is givin' in, yeah";
	fd = open("files/file_with_nl_end_no_nl", O_RDONLY);
	for (int i = 0; strs[i]; i++){		
		line = get_next_line(fd);
		if (strcmp (line, strs[i]) != 0)
		{
			printf ("Error: file_with_nl_end_no_nl\n");
			close (fd);
			return (-1);
		}
		free (line);
	}
	close (fd);
	printf ("file with new line end no new line: passed\n");

	return (0);
}
