/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 00:01:10 by opelser       #+#    #+#                 */
/*   Updated: 2022/11/01 17:26:32 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char		tmp;
	int			i;
	int			len;

	i = 0;
	len = ft_strlen(s) - 1;
	if (s[i] == '-')
		i++;
	while (i < len)
	{
		tmp = s[i];
		s[i] = s[len];
		s[len] = tmp;
		i++;
		len--;
	}
	return (s);
}

int	ft_intlen(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_makearr(char *res, long n)
{
	int		i;

	i = 0;
	if (n == 0)
	{
		res[i] = '0';
		i++;
	}
	if (n < 0)
	{
		n *= -1;
		res[i] = '-';
		i++;
	}
	while (n)
	{
		res[i] = n % 10 + 48;
		n /= 10;
		i++;
	}
	res[i] = '\0';
	ft_strrev(res);
}

char	*ft_itoa(int n)
{
	char		*res;
	const int	len = ft_intlen(n);

	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_makearr(res, n);
	return (res);
}

// int	main()
// {
// 	printf("\nfinal result: %s\n", ft_itoa(0));
// 	return(0);
// }
