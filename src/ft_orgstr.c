/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_orgstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:32:26 by phbarrad          #+#    #+#             */
/*   Updated: 2020/12/05 17:32:34 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void		whnot(int len, int div, t_data *data)
{
	if (len < div || div == 0)
		data->before = data->avnbr - len;
	else
		data->before = data->avnbr - div;
	if (data->apnbr == 0)
		data->before += len;
}

void		org_str_lt(t_data *data, int len)
{
	if (data->zero == 1 && data->av > 0 && data->av > data->ap &&
	data->moins == 0 && (data->point == 0 || data->ap != 0))
	{
		data->betwin = data->before;
		data->before = 0;
		aff_betwin(data);
		data->betwin = len;
	}
}

void		before_str(t_data *data, int len, int div)
{
	if (data->moins == 1 && data->avnbr > 0 && data->apnbr >= 0)
		data->after = data->avnbr - div;
	else if (data->moins == 1 && data->apnbr > 0 && data->avnbr == 0 &&
	data->zero == 0 && data->foix_2 == 0)
		data->after = data->apnbr - len;
	else if (data->avnbr < data->apnbr && data->avnbr > 0)
		data->before = data->avnbr - len;
	else if (data->apnbr == data->avnbr && data->avnbr != 0 &&
	data->avnbr - len > 0)
		data->before = data->avnbr - len;
	else if (data->apnbr < 0 && data->avnbr > 0 && data->moins == 0)
		data->before = data->avnbr - len;
	else if (data->apnbr > 0 && (data->apnbr - len) > 0 && data->point == 0)
		data->before = data->apnbr - len;
	else if (data->avnbr - data->apnbr > 0 && data->avnbr > 0 &&
	data->foix_2 == 1 && data->moins == 0)
		whnot(len, div, data);
	else if (data->avnbr - data->apnbr > 0 && data->avnbr > 0 &&
	data->moins == 0)
		data->before = data->avnbr - div;
}

void		after_str(t_data *data, int len, int div)
{
	if (data->after != 0)
		;
	else if (data->avnbr > 0 && data->avnbr > ft_abs(data->apnbr) &&
	data->point == 1 && data->moins == 0)
		data->after = 0;
	else if (data->avnbr > 0 && data->apnbr < 0 && data->point == 1 &&
	data->foix_2 == 1 && data->moins == 0)
		data->after = 0;
	else if (data->apnbr < 0 && (ft_abs(data->apnbr) - len) > 0 &&
	data->foix_2 == 1)
		data->after = ft_abs(data->avnbr) - len;
	else if (data->apnbr < 0 && (ft_abs(data->apnbr) - len) > 0 &&
	data->point == 0)
		data->after = ft_abs(data->apnbr) - len;
	else if (data->apnbr < 0)
		data->after = ft_abs(data->avnbr) - len;
	else if (data->avnbr < 0 &&
	((ft_abs(data->avnbr) >= len) || (ft_abs(data->avnbr) >= data->apnbr)))
		data->after = ft_abs(data->avnbr) - div;
}

void		org_str(t_data *data, int len)
{
	int		div;

	div = 0;
	if (data->apnbr > len)
		div = len;
	else
		div = data->apnbr;
	if (data->point == 0 && data->apnbr == 0 && data->avnbr != 0)
	{
		data->apnbr = data->avnbr;
		data->avnbr = 0;
	}
	before_str(data, len, div);
	if (data->point == 1 && data->apnbr >= 0)
		data->betwin = ft_abs(data->apnbr);
	else
		data->betwin = len;
	after_str(data, len, div);
}
