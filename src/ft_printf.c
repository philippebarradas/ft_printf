/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:48:20 by phbarrad          #+#    #+#             */
/*   Updated: 2020/12/04 16:36:13 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void		init_data(t_data *data)
{
	data->moins = 0;
	data->zero = 0;
	data->point = 0;
	data->foix = 0;
	data->foix_2 = 0;
	data->pzero = 0;
	data->avnbr = 0;
	data->apnbr = 0;
	data->before = 0;
	data->betwin = 0;
	data->after = 0;
	data->av = 0;
	data->ap = 0;
}

int			quel_modul(t_data *data, char const str, va_list ap, ...)
{
	int		i;
	void	(*fulltab[9]) (va_list ap, t_data *data);
	char	*allindex;

	allindex = ft_strdup("cspdiuxX%\0");
	fulltab[0] = c_case;
	fulltab[1] = s_case;
	fulltab[2] = p_case;
	fulltab[3] = d_i_case;
	fulltab[4] = d_i_case;
	fulltab[5] = u_case;
	fulltab[6] = x_case;
	fulltab[7] = mx_case;
	fulltab[8] = prc_case;
	i = 0;
	while (allindex[i])
	{
		if (str == allindex[i])
			fulltab[i](ap, data);
		i++;
	}
	free(allindex);
	return (0);
}

int			ft_ebroch(t_data *data, int j, char const *str, va_list ap)
{
	int		len_conv;

	ft_foix(str + j + 1, data);
	len_conv = recup_conv(j + 1, str, data, ap) + 1;
	if (data->foix_2 == 1 && data->foix == 1)
	{
		data->avnbr = va_arg(ap, int);
		data->apnbr = va_arg(ap, int);
	}
	data->av = data->avnbr;
	data->ap = data->apnbr;
	if (!str[j + len_conv])
		return (-1);
	quel_modul(data, str[j + len_conv], ap);
	return (j + len_conv);
}

int			parcour_str(const char *str, t_data *data, va_list ap)
{
	int		j;

	j = 0;
	while (str[j])
	{
		init_data(data);
		if (str[j] == '%')
			j = ft_ebroch(data, j, str, ap);
		else
			ft_putchar_fd(str[j], 1, data);
		if (j == -1)
		{
			free(data);
			return (0);
		}
		j++;
	}
	return (j);
}

int			ft_printf(const char *str, ...)
{
	t_data	*data;
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	if (!(data = malloc(sizeof(t_data))))
		return (0);
	data->count = count;
	if (parcour_str(str, data, ap) == 0)
		return (0);
	count = data->count;
	free(data);
	va_end(ap);
	return (count);
}
