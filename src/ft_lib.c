/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:34:36 by phbarrad          #+#    #+#             */
/*   Updated: 2020/12/04 15:39:05 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void					aff_col_1(unsigned long nbr, char *base, t_data *data)
{
	unsigned long		len_base;

	len_base = 0;
	while (base[len_base])
		len_base++;
	if (nbr >= len_base)
		aff_col_1(nbr / len_base, base, data);
	ft_putchar_fd(base[nbr % len_base], 1, data);
}

int						ft_strlenbase(unsigned long nbr, char *base)
{
	unsigned long		len_base;
	int					i;

	i = 0;
	len_base = 0;
	while (base[len_base])
		len_base++;
	while (nbr >= len_base)
	{
		nbr = nbr / len_base;
		i++;
	}
	i++;
	return (i);
}

int						ft_strlen_int(int n)
{
	unsigned int		nbr;
	int					i;

	i = 0;
	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		i++;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		i++;
	}
	i++;
	return (i);
}

void					aff_col_1_un(unsigned int nbr, char *base, t_data *data)
{
	unsigned int		len_base;

	len_base = 0;
	while (base[len_base])
		len_base++;
	if (nbr >= len_base)
		aff_col_1(nbr / len_base, base, data);
	ft_putchar_fd((base[nbr % len_base]), 1, data);
}

int						ft_strlenbase_un(unsigned int nbr, char *base)
{
	unsigned int		len_base;
	int					i;

	i = 0;
	len_base = 0;
	while (base[len_base])
		len_base++;
	while (nbr >= len_base)
	{
		nbr = nbr / len_base;
		i++;
	}
	i++;
	return (i);
}
