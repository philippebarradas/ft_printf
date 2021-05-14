/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:20:49 by phbarrad          #+#    #+#             */
/*   Updated: 2020/11/17 14:20:54 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void		ft_putstr_fd(char *s, int fd, t_data *data)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		data->count++;
		write(fd, &(s[i]), 1);
	}
}
