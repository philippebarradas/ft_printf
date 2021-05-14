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

void		org_c_pc(t_data *data, int len)
{
	if (data->avnbr > 0 && data->moins == 0 &&
	(data->pzero == 1 || data->zero == 0))
		data->before = data->avnbr - len;
	else if (data->avnbr > 0 && data->pzero == 0 && data->zero == 1)
		data->betwin = data->avnbr - len;
	else if (data->avnbr < 0 || data->moins == 1)
		data->after = ft_abs(data->avnbr) - len;
	else if (data->avnbr > len)
		data->after = data->apnbr - len;
}

void		s_case(va_list ap, t_data *data)
{
	char	*str;
	int		i;
	int		len;
	int		fee;

	str = va_arg(ap, char *);
	i = -1;
	fee = 0;
	if (!str)
	{
		str = ft_strdup("(null)");
		fee = 1;
	}
	len = ft_strlen(str);
	org_str(data, len);
	org_str_lt(data, len);
	aff_before(data);
	while (str[++i] && data->betwin > 0)
	{
		ft_putchar_fd(str[i], 1, data);
		data->betwin--;
	}
	aff_after(data);
	if (fee == 1)
		free(str);
}

void		prc_case(va_list ap, t_data *data)
{
	int		len;

	if (!ap)
		return ;
	len = 1;
	org_c_pc(data, len);
	aff_before(data);
	aff_betwin(data);
	ft_putchar_fd('%', 1, data);
	aff_after(data);
}

void		c_case(va_list ap, t_data *data)
{
	char	c;
	int		len;

	len = 1;
	c = (char)va_arg(ap, int);
	org_c_pc(data, len);
	aff_before(data);
	aff_betwin(data);
	ft_putchar_fd(c, 1, data);
	aff_after(data);
}
