/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 19:21:20 by opelser       #+#    #+#                 */
/*   Updated: 2022/12/23 13:20:11 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char			*str;
	static char		*rest;

	str = malloc(1);
	if (find_newline(rest) == -1)
	{
		if (rest != NULL)
		{
			str = ft_strjoin(str, rest);
			rest = divide_lines(str, rest);
		}

		if ((str = make_str(fd, str)) == NULL)
			return (NULL);
		rest = divide_lines(str, rest);
	}
	else
	if (rest)
	{
		str = ft_strjoin(str, rest);
		free (rest);
		str = make_str(fd, str);
		rest = divide_lines(str, rest);
	}
	if (str[0] == '\0')
		return (NULL);

	return(str);
}

ssize_t	find_newline(char *str)
{
	ssize_t i;

	i = 0;

	if (!str)
		return (-1);

	while (str[i] != '\n' && str[i] != '\0')
		i++;

	return (i);
}

char	*divide_lines(char *str, char *rest)
{
	int		i;
	int		len;

	i = find_newline(str) + 1;
	len = ft_strlen(str) - i + 1;
	rest = malloc(len * sizeof(char));
	ft_strlcpy(rest, str + i, len);
	while (str[i] != '\0')
	{
		str[i] = '\0';
		i++;
	}
	// printf("< %s >\t", rest);
	return (rest);
}

char	*make_str(int fd, char *str)
{
	int		bytes;
	int		truefalse;
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);

	bytes = read(fd, buf, BUFFER_SIZE);
	buf[bytes] = '\0';

	while ((truefalse = find_newline(buf)) == BUFFER_SIZE)
	{
		str = ft_strjoin(str, buf);
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		buf[bytes] = '\0';
	}
	str = ft_strjoin(str, buf);
	free(buf);

	if (truefalse == -1)
		return (str);

	return (str);
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

	// str = malloc(1);
	// // ft_strlcpy(str, "abcdef\nabcdef", 15);
	// make_str(file, str, NULL);
	// return 0;

	int		count = 0;
	while (count < argv[2][0] - 48)
	{
		str = get_next_line(file);
		if (str != NULL)
			printf("line %d:\t %s", count + 1, str);
		else
		{
			printf("\nget_next_line failed to execute\n");
			return (0);
		}

		
		count++;
	}

	close(file);
	return 0;
}
