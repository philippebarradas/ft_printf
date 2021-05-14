/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:51:04 by phbarrad          #+#    #+#             */
/*   Updated: 2020/12/04 19:01:53 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void				p_case(va_list ap, t_data *data)
{
	unsigned long	a;
	int				len;

	a = (unsigned long)va_arg(ap, void *);
	len = ft_strlenbase(a, "0123456789abcdef");
	org_nbr(data, len);
	if (data->avnbr >= 3 && a == 0 && data->point == 1)
		data->before++;
	else if (data->avnbr <= -3 && a == 0 && data->point == 1)
		data->after++;
	if (data->after > 0)
		data->after -= 2;
	if (data->before > 0)
		data->before -= 2;
	aff_before(data);
	if (aff_nbr_p(data, a) == 0)
	{
		ft_putstr_fd("0x", 1, data);
		aff_betwin(data);
		aff_col_1(a, "0123456789abcdef", data);
	}
	aff_after(data);
}

void				mx_case(va_list ap, t_data *data)
{
	int				len;
	unsigned long	a;

	a = (unsigned long)va_arg(ap, unsigned long);
	len = ft_strlenbase_un(a, "0123456789ABCDEF");
	org_nbr(data, len);
	aff_before(data);
	aff_betwin(data);
	if (aff_nbr(data, a) == 0)
		aff_col_1_un(a, "0123456789ABCDEF", data);
	aff_after(data);
}

void				x_case(va_list ap, t_data *data)
{
	unsigned long	a;
	int				len;

	a = (unsigned long)va_arg(ap, unsigned long);
	len = ft_strlenbase_un(a, "0123456789abcdef");
	org_nbr(data, len);
	aff_before(data);
	aff_betwin(data);
	if (aff_nbr(data, a) == 0)
		aff_col_1_un(a, "0123456789abcdef", data);
	aff_after(data);
}

void				u_case(va_list ap, t_data *data)
{
	unsigned		a;
	char			*utoa;

	a = (unsigned)va_arg(ap, int);
	utoa = ft_utoa(a);
	org_nbr(data, ft_strlenpos(utoa));
	aff_before(data);
	aff_betwin(data);
	if (aff_nbr(data, a) == 0)
		ft_putnbru_fd(a, 1, data);
	aff_after(data);
	free(utoa);
}

void				d_i_case(va_list ap, t_data *data)
{
	int				a;
	char			*toa;

	a = va_arg(ap, int);
	toa = ft_itoa(a);
	org_nbr(data, ft_strlenpos(toa));
	if (a < 0)
	{
		data->before--;
		data->after--;
	}
	if (a < 0 && data->before <= 0 && data->after <= 0 && data->zero == 1 &&
	data->moins == 0 && data->ap < ft_len(toa) && ((data->ap < 0 &&
	data->av < 0) || (data->ap < 0 || data->av < 0) || (data->point == 0)))
		data->betwin--;
	aff_before(data);
	if (a < 0)
		ft_putchar_fd('-', 1, data);
	aff_betwin(data);
	if (aff_nbr(data, a) == 0)
		ft_putnbr_fd(a, 1, data);
	aff_after(data);
	free(toa);
}
