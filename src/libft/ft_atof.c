/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:23:04 by opelser           #+#    #+#             */
/*   Updated: 2024/03/21 16:24:30 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static float	decimals(const char *str, int i)
{
	float	factor;
	float	result;

	result = 0;
	factor = 0.1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result += (str[i] - '0') * factor;
		factor *= 0.1;
		i++;
	}
	return (result);
}

float	ft_atof(const char *str)
{
	float	result;
	int		sign;
	int		i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		result += decimals(str, i + 1);
	return (result * sign);
}
