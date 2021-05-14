/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:17:28 by phbarrad          #+#    #+#             */
/*   Updated: 2020/12/04 19:08:56 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct	s_data
{
	int			moins;
	int			zero;
	int			point;
	int			foix;
	int			foix_2;
	int			pzero;
	int			avnbr;
	int			apnbr;
	int			before;
	int			betwin;
	int			after;
	int			av;
	int			ap;
	int			count;
}				t_data;

int				ft_printf(const char *str, ...);
void			ft_putchar_fd(char c, int fd, t_data *data);
void			ft_putstr_fd(char *s, int fd, t_data *data);
int				ft_strlen_int(int n);

int				ft_strlen_ent(int n);
int				ft_strlen_ent_pos(int n);

void			init_data(t_data	*data);
void			ft_foix(const char *str, t_data *data);

void			aff_col_1(unsigned long nbr, char *base, t_data *data);
void			aff_col_1_un(unsigned int nbr, char *base, t_data *data);

int				ft_strlenbase(unsigned long nbr, char *base);

void			ft_putnbr_fd(int n, int fd, t_data *data);
void			ft_putnbru_fd(unsigned n, int fd, t_data *data);

int				ft_strlenbase_un(unsigned int nbr, char *base);

int				ft_abs(int nbr);

void			org_nbr(t_data *data, int len);
void			org_str(t_data *data, int len);
void			org_c_pc(t_data *data, int len);
void			whnot(int len, int div, t_data *data);
void			org_str_lt(t_data *data, int len);

void			aff_before(t_data *data);
void			aff_betwin(t_data *data);
void			aff_after(t_data *data);

int				aff_nbr(t_data *data, unsigned int a);
int				aff_nbr_p(t_data *data, unsigned long a);

char			*ft_strdup(const char *s1);

char			*ft_utoa(unsigned n);
char			*ft_itoa(int n);

int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);

size_t			ft_strlen(const char *str);
size_t			ft_strlenpos(const char *str);
int				ft_len(char *str);

void			f_e_case(va_list ap, t_data	*data);
void			d_i_case(va_list ap, t_data	*data);
void			s_case(va_list ap, t_data	*data);
void			c_case(va_list ap, t_data	*data);
void			p_case(va_list ap, t_data	*data);
void			x_case(va_list ap, t_data	*data);
void			mx_case(va_list ap, t_data	*data);
void			u_case(va_list ap, t_data	*data);
void			prc_case(va_list ap, t_data	*data);

int				recup_conv(int j, const char *str, t_data	*data, va_list ap);

#endif
