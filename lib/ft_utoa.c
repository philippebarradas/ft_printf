/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:31:36 by phbarrad          #+#    #+#             */
/*   Updated: 2020/12/04 15:32:18 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static char		*ft_revstr(char *str)
{
	int			i;
	int			len;
	char		temp;

	len = 0;
	i = 0;
	while (str[len])
		len++;
	len--;
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
	return (str);
}

static char		*f_zero(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static int		n_size(unsigned n, int pos)
{
	int			size;

	size = 1;
	if (n == 0)
		return (2);
	if (pos < 0)
		size++;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_utoa(unsigned n)
{
	int			i;
	unsigned	nbr;
	unsigned	pos;
	char		*str;

	pos = n;
	i = 0;
	nbr = n;
	if (!(str = malloc(sizeof(char) * (n_size(nbr, pos)))))
		return (NULL);
	if (n == 0)
		return (f_zero(str));
	while (nbr > 0)
	{
		str[i++] = ((nbr % 10) + '0');
		nbr = nbr / 10;
	}
	str[i] = '\0';
	return (ft_revstr(str));
}
