/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:20:16 by seunghan          #+#    #+#             */
/*   Updated: 2024/01/31 12:11:12 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include"get_next_line_bonus.h"
int main(void)
{
	char *str;
	int fd1;
	int fd2;
	int fd3;

	fd1 = open("test1.txt", O_RDONLY);
	str = get_next_line(fd1);
    printf("%s", str);
	str = get_next_line(fd1);
    printf("%s", str);
	str = get_next_line(fd1);
    printf("%s", str);
	str = get_next_line(fd1);
    printf("%s", str);
    /*fd2 = open("test1.txt", O_RDONLY);*/
	str = get_next_line(fd2);
    printf("%s", str);
	str = get_next_line(fd2);
    printf("%s", str);
	str = get_next_line(fd2);
    printf("%s", str);
	str = get_next_line(fd2);
    printf("%s", str);
}
