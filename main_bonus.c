/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:44:04 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/06 13:15:27 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd1 = open("files/file_with_nl_end_nl", O_RDONLY);
    int     fd2 = open("files/file_with_nl_end_no_nl", O_RDONLY);
    char    *line;

    for (int i = 0; i < 6; i++){
        line = get_next_line(fd1);
        printf("fd: %d, line: %s", fd1, line);
        free (line);
        line = get_next_line(fd2);
        printf("fd: %d, line: %s", fd2, line);
        free (line);
    }
    close (fd1);
    close (fd2);
    return (0);
}