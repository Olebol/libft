/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 19:21:20 by opelser       #+#    #+#                 */
/*   Updated: 2022/12/19 20:32:50 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd)
{
	write(1, &fd, 10);
	return ("WIP");
}

int main(void)
{
	int		file;
	
	file = open("test.txt", O_RDONLY);
	get_next_line(file);

	close(file);
	return 0;
}