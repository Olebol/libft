/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 19:21:20 by opelser       #+#    #+#                 */
/*   Updated: 2022/12/21 14:14:29 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char		*str;
	size_t			bytes_in_file;
	int				i = 0;

	printf("\n*/ GOES INTO FUNCTION /*\n");
	str = malloc(BUFFER_SIZE * sizeof(char));

	if (str == NULL)
		return (NULL);

	bytes_in_file = read(fd, str, BUFFER_SIZE);
	if (bytes_in_file == -1)
		return (NULL);
	str[bytes_in_file] = '\0';

	printf("\n*/ str: %s /*\n", str);
	
	return(str);
}

int main(int argc, char **argv)
{
	int		file;
	char	*str;

	if (argc != 3)
	{
		write(1, "Usage: ./get_next_line [file name] [amount of times]\n", 36);
		return (-1);
	}

	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		write(1, "Failed to open file\n", 21);
		return (-1);
	}
	
	int		count = 0;
	while (count < argv[2][0] - 48)
	{
		str = get_next_line(file);
		if (str == NULL)
		{
			write(1, "get_next_line failed to execute\n", 33);
			return (0);
		}

		int i = 0;

		printf("line %d: %s", count + 1, str);
		count++;
	}

	close(file);
	return 0;
}