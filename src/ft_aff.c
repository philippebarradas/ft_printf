/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:16:53 by phbarrad          #+#    #+#             */
/*   Updated: 2020/12/04 18:42:24 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	aff_before(t_data *data)
{
	while (data->before > 0)
	{
		ft_putchar_fd(' ', 1, data);
		data->before--;
	}
}

void	aff_betwin(t_data *data)
{
	while (data->betwin > 0)
	{
		ft_putchar_fd('0', 1, data);
		data->betwin--;
	}
}

void	aff_after(t_data *data)
{
	while (data->after > 0)
	{
		ft_putchar_fd(' ', 1, data);
		data->after--;
	}
}

int		aff_nbr(t_data *data, unsigned int a)
{
	if ((a == 0) && ((data->point == 1 && data->ap == 0 && (data->av > 0 ||
	data->av < 0)) || (data->moins == 1 && data->zero == 1 && data->point == 1
	&& data->av != 0 && data->ap == 0) || (data->moins == 1 && data->zero == 0
	&& data->point == 1 && data->av != 0 && data->ap == 0) || (data->moins == 0
	&& data->zero == 0 && data->foix == 0 && data->point == 1 && data->av != 0
	&& data->ap == 0) || (data->moins == 0 && data->zero == 1 && data->foix == 0
	&& data->point == 1 && data->av != 0 && data->ap == 0)))
		ft_putchar_fd(' ', 1, data);
	else if ((a == 0) && (
	(data->moins == 0 && data->zero == 1 && data->point == 1 && data->ap == 0
	&& data->av == 0) || (data->moins == 0 && data->zero == 0 &&
	data->point == 1 && data->foix == 0 && data->ap == 0) || (data->point == 1
	&& data->foix == 1 && data->moins == 0 && data->av == 0 && data->ap == 0) ||
	(data->moins == 1 && data->point == 1 && data->av == 0 && data->ap == 0)))
		return (1);
	else
		return (0);
	return (1);
}

int		aff_nbr_p(t_data *data, unsigned long a)
{
	if ((a == 0) && ((data->point == 1 && data->ap == 0 && (data->av > 0 ||
	data->av < 0)) || (data->moins == 1 && data->zero == 1 && data->point == 1
	&& data->av != 0 && data->ap == 0) || (data->moins == 1 && data->zero == 0
	&& data->point == 1 && data->av != 0 && data->ap == 0) || (data->moins == 0
	&& data->zero == 0 && data->foix == 0 && data->point == 1 && data->av != 0
	&& data->ap == 0) || (data->moins == 0 && data->zero == 1 && data->foix == 0
	&& data->point == 1 && data->av != 0 && data->ap == 0)))
		ft_putstr_fd("0x", 1, data);
	else if ((a == 0) && ((data->moins == 0 && data->zero == 1 &&
	data->point == 1 && data->ap == 0 && data->av == 0) || (data->moins == 0 &&
	data->zero == 0 && data->point == 1 && data->foix == 0 && data->ap == 0) ||
	(data->point == 1 && data->foix == 1 && data->moins == 0 && data->av == 0
	&& data->ap == 0) || (data->moins == 1 && data->zero == 0 &&
	data->point == 1 && data->av == 0 && data->ap == 0)))
	{
		ft_putstr_fd("0x", 1, data);
		return (1);
	}
	else
		return (0);
	return (1);
}
