/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:44:59 by phbarrad          #+#    #+#             */
/*   Updated: 2020/12/04 19:25:16 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void		ft_foix(const char *str, t_data *data)
{
	int		j;
	int		e;

	e = 0;
	j = 0;
	while (str[j] && str[j] != 'c' && str[j] != 's' && str[j] != 'p' &&
	str[j] != 'd' && str[j] != 'i' && str[j] != 'u' && str[j] != 'x' &&
	str[j] != 'X' && str[j] != '%')
	{
		if (str[j] == '*')
			e++;
		j++;
	}
	if (e == 2)
		data->foix_2 = 1;
}

void		get_flag(int j, const char *str, t_data *data, int i)
{
	if (str[j] == '-')
		data->moins = 1;
	if ((str[j] == '0' && i == 0) ||
	(str[j] == '0' && i > 0 && ft_isdigit(str[j - 1]) == 0))
		data->zero = 1;
	if (str[j] == '*')
		data->foix = 1;
	if (str[j] == '0' && i > 0 && ft_isdigit(str[j - 1]) == 0 &&
	data->point == 1)
		data->pzero = 1;
}

void		get_arg(int j, const char *str, t_data *data, va_list ap)
{
	if (data->foix == 1 && data->point == 0 && data->avnbr == 0
	&& data->foix_2 == 0)
		data->avnbr = va_arg(ap, int);
	if (data->foix == 1 && data->point == 1 && data->apnbr == 0
	&& data->foix_2 == 0)
		data->apnbr = va_arg(ap, int);
	if (str[j] == '.')
		data->point = 1;
}

int			recup_conv(int j, const char *str, t_data *data, va_list ap)
{
	int		i;

	i = 0;
	while (str[j] && str[j] != 'c' && str[j] != 's' && str[j] != 'p' &&
	str[j] != 'd' && str[j] != 'i' && str[j] != 'u' && str[j] != 'x' &&
	str[j] != 'X' && str[j] != '%')
	{
		get_flag(j, str, data, i);
		if (ft_atoi(str + j) != 0 && data->avnbr == 0 && data->point == 0)
		{
			data->avnbr = ft_atoi(str + j);
			j = j + ft_strlen_int(data->avnbr) - 1;
			i = i + ft_strlen_int(data->avnbr) - 1;
		}
		else if (ft_atoi(str + j) != 0 && data->apnbr == 0 && data->point == 1)
		{
			data->apnbr = ft_atoi(str + j);
			j = j + ft_strlen_int(data->apnbr) - 1;
			i = i + ft_strlen_int(data->apnbr) - 1;
		}
		get_arg(j, str, data, ap);
		j++;
		i++;
	}
	return (i);
}
