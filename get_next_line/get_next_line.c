/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 19:21:20 by opelser       #+#    #+#                 */
/*   Updated: 2022/12/22 18:50:51 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	find_newline(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char	*divide_lines(char *str, char *rest)
{
	size_t i;
	size_t rest_size;

	i = find_newline(str) + 1;
	rest_size = ft_strlen(str) - i + 1;
	rest = malloc((rest_size * sizeof(char)));
	ft_strlcpy(rest, str + i, rest_size);
	
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	char			*buf;
	char			*str;
	static char		*rest;
	size_t			bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));

	if (buf == NULL)
		return (NULL);

	if (!(bytes = read(fd, buf, BUFFER_SIZE)))
		return (NULL);
	buf[bytes] = '\0';
	str = malloc(1);
	str = ft_strjoin(str, buf);
	if (find_newline(str))
		rest = divide_lines(str, rest);
	printf("%s < rest\n\n", rest);
	return(str);
}

int main(int argc, char **argv)
{
	int		file;
	char	*str;

	if (argc != 3)
	{
		write(1, "Usage: ./get_next_line [file name] [amount of times]\n", 54);
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

		printf("line %d:\t %s", count + 1, str);
		count++;
	}

	close(file);
	return 0;
}