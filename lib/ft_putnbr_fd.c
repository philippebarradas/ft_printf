/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:19:58 by phbarrad          #+#    #+#             */
/*   Updated: 2020/12/04 15:28:54 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void			ft_putfd(char c, int fd, t_data *data)
{
	data->count++;
	write(fd, &c, 1);
}

void				ft_putnbr_fd(int n, int fd, t_data *data)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
		nbr = -n;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd, data);
	ft_putfd((nbr % 10) + '0', fd, data);
}

void				ft_putnbru_fd(unsigned n, int fd, t_data *data)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr >= 10)
		ft_putnbru_fd(nbr / 10, fd, data);
	ft_putfd((nbr % 10) + '0', fd, data);
}
