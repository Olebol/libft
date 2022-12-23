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

ssize_t	find_newline(char *str)
{
	ssize_t i;

	i = 0;
	if (!str)
		return (-1);

	while (str[i] != '\n' && str[i] != '\0')
		i++;

	if (str[i] == '\0')
		return (-1);

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

	// printf("\n[FUNCTION CALL]\n%s < rest\n\n", rest);
	// printf("\n[CHECKPOINT 1]\n%s < rest\n\n", rest);
	// printf("> %s < rest\n[END OF FUNCTION]\n\n", rest);

	if (find_newline(rest) == -1)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buf == NULL)
			return (NULL);

		if (!(bytes = read(fd, buf, BUFFER_SIZE)) && (!rest))
			return (NULL);

		else if (rest)
		{
			ft_strlcpy(str, rest, ft_strlen(rest) + 1);
			free(rest);
			rest = NULL;
			return (str);
		}
		buf[bytes] = '\0';
	}
	else
		buf = rest;

	str = malloc(1);
	str = ft_strjoin(str, buf);

	if (find_newline(str))
		rest = divide_lines(str, rest);

	free(buf);

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