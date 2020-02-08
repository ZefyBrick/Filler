/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_best_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 20:26:01 by cdubuque          #+#    #+#             */
/*   Updated: 2019/11/04 04:03:59 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_minus_one(t_player **play, t_start *tmp_m, t_start *tmp_e)
{
	int		i;

	i = -1;
	tmp_m->x = -1;
	tmp_m->y = -1;
	tmp_e->x = -1;
	tmp_e->y = -1;
	START->x = -1;
	START->y = -1;
	while (++i < XY && D_PL_X[i] != -1)
	{
		D_PL_X[i] = -1;
		D_PL_Y[i] = -1;
	}
}

void	ft_my_tmp_del(t_player **play, t_start *tmp_m, t_start *tmp_e)
{
	int		c;

	c = -1;
	while (++c < 1500 && (MY[0][c] != tmp_m->x || MY[1][c] != tmp_m->y))
		;
	if (c == 0 && MY[0][1] == -1)
	{
		MY[0][0] = -1;
		MY[1][0] = -1;
		return ;
	}
	while (c < 1500 && MY[0][c] != -1)
	{
		MY[0][c] = MY[0][c + 1];
		MY[1][c] = MY[1][c + 1];
		++c;
	}
	ft_minus_one(play, tmp_m, tmp_e);
}

int		ft_valid_or_not(t_player **play, int c, int d, t_start *tmp_e)
{
	if (d != c)
	{
		if (D_PL_X[d] >= MAP_X || D_PL_Y[d] >= MAP_Y)
			return (0);
		if (MAP[D_PL_Y[d]][D_PL_X[d]] != 0)
			return (0);
		if (MAN == -1 || MAN > ft_modul_int(D_PL_X[d] - tmp_e->x) \
			+ ft_modul_int(D_PL_Y[d] - tmp_e->y))
			MAN = ft_modul_int(D_PL_X[d] - tmp_e->x) \
			+ ft_modul_int(D_PL_Y[d] - tmp_e->y);
	}
	return (1);
}

int		ft_duble_full(t_player **play, int c, t_start *tmp_m, t_start *tmp_e)
{
	int		i;
	int		j;
	int		d;

	d = -1;
	i = tmp_m->x - PL_X[c];
	j = tmp_m->y - PL_Y[c];
	if (i < 0 || j < 0)
		return (0);
	while (++d < XY && PL_X[d] != -1)
	{
		D_PL_X[d] = PL_X[d] + i;
		D_PL_Y[d] = PL_Y[d] + j;
		if (!(ft_valid_or_not(play, c, d, tmp_e)))
			return (0);
	}
	return (1);
}
