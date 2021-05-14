/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:26:03 by phbarrad          #+#    #+#             */
/*   Updated: 2020/12/04 15:30:06 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

size_t				ft_strlen(const char *str)
{
	size_t			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t				ft_strlenpos(const char *str)
{
	size_t			i;
	size_t			e;

	i = 0;
	e = 0;
	while (str[i])
	{
		if (str[i] != '-')
			e++;
		i++;
	}
	return (e);
}

int					ft_len(char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
