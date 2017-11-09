/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:49:36 by domelche          #+#    #+#             */
/*   Updated: 2017/10/26 18:49:38 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_pass_spcs(const char *str)
{
	int		i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

static int	ft_atoi_pass_zres(const char *str, int i)
{
	while (str[i] == '0')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	res;
	unsigned long long	max;

	res = 0;
	max = 9223372036854775807;
	i = ft_atoi_pass_spcs(str);
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	i = ft_atoi_pass_zres(str, i);
	while (ft_isdigit(str[i]) != 0)
		res = res * 10 + (str[i++] - '0');
	if (res > max && sign > 0)
		return (-1);
	if (res > max + 1 && sign < 0)
		return (0);
	return ((int)(res * sign));
}
