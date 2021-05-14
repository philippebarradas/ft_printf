/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_org.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:15:19 by phbarrad          #+#    #+#             */
/*   Updated: 2020/12/05 18:46:31 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void		after_nbr(t_data *data, int len, int div)
{
	if (data->avnbr > 0 && data->moins == 0 &&
	(data->pzero == 0 || data->zero == 1))
		data->before = data->avnbr - div;
	else if (data->avnbr < 0 || data->moins == 1)
		data->after = ft_abs(data->avnbr) - div;
	else if (data->avnbr > len)
		data->after = data->apnbr - div;
	data->betwin = data->apnbr - len;
	if (data->zero == 1 && data->moins == 1 && data->point == 0)
	{
		data->after = data->betwin;
		data->betwin = 0;
	}
	if (data->zero == 1 && data->point == 1 && data->apnbr < 0 &&
	data->avnbr > 0)
	{
		data->betwin = data->before;
		data->before = 0;
	}
}

void		org_nbr(t_data *data, int len)
{
	int		div;

	if (len < data->apnbr)
		div = data->apnbr;
	else
		div = len;
	if (data->zero == 1 && data->point == 0 && data->apnbr == 0 &&
	data->avnbr > 0)
	{
		data->apnbr = data->avnbr;
		data->avnbr = 0;
	}
	after_nbr(data, len, div);
}
