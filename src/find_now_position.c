/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_now_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:11:07 by cdubuque          #+#    #+#             */
/*   Updated: 2019/11/04 04:04:25 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_count_envir(t_player **play, int c, int i)
{
	int		count;

	count = 0;
	while (++i < XY && PL_X[i] != -1)
	{
		if (PL_X[i] == PL_X[c] && PL_Y[i] == PL_Y[c] - 1)
			++count;
		if (PL_X[i] == PL_X[c] && PL_Y[i] == PL_Y[c] + 1)
			++count;
		if (PL_X[i] == PL_X[c] - 1 && PL_Y[i] == PL_Y[c])
			++count;
		if (PL_X[i] == PL_X[c] + 1 && PL_Y[i] == PL_Y[c])
			++count;
	}
	return (count);
}

void	ft_del_no_exit2(int *del, t_player **play)
{
	int		c;
	int		i;

	c = -1;
	while (++c < 1500 && del[c] != -1)
		;
	while (--c > -1)
	{
		i = del[c];
		while (i < XY && PL_X[i] != -1)
		{
			PL_X[i] = PL_X[i + 1];
			PL_Y[i] = PL_Y[i + 1];
			++i;
		}
	}
}

void	ft_del_no_exit(t_player **play)
{
	int		c;
	int		i;
	int		del[1500];
	int		d;

	d = -1;
	while (++d < 1500)
		del[d] = -1;
	d = -1;
	c = -1;
	while (++c < XY && PL_X[c] != -1)
	{
		i = -1;
		if (ft_count_envir(play, c, i) == 4)
			del[++d] = c;
	}
	if (del[0] != -1)
		ft_del_no_exit2(del, play);
}

void	ft_my_place(t_player **play, t_start *tmp_m, t_start *tmp_e, int man)
{
	int		c;

	c = -1;
	MAN = -1;
	START->x = -1;
	START->y = -1;
	while (++c < XY && PL_X[c] != -1)
	{
		if (!(ft_duble_full(play, c, tmp_m, tmp_e)))
			;
		else if (man == -1 || MAN < man)
		{
			man = MAN;
			START->x = tmp_m->x - PL_X[c];
			START->y = tmp_m->y - PL_Y[c];
		}
	}
	if (START->x == -1)
	{
		ft_my_tmp_del(play, tmp_m, tmp_e);
		ft_find_position(play, 1);
		return ;
	}
	ft_my_enemy_del(play);
}

void	ft_find_now_position(t_player **play, t_start *tmp_m, t_start *tmp_e)
{
	int			i;
	int			j;
	int			man;

	i = -1;
	man = -1;
	while (++i < 1500 && MY[0][i] != -1)
	{
		ft_no_enemy(play, tmp_m, i, &man);
		j = -1;
		while (++j < 1500 && ENEMY[0][j] != -1)
		{
			if (man == -1 || man > ft_modul_int(MY[0][i] - ENEMY[0][j]) \
			+ ft_modul_int(MY[1][i] - ENEMY[1][j]))
			{
				man = ft_modul_int(MY[0][i] - ENEMY[0][j]) \
				+ ft_modul_int(MY[1][i] - ENEMY[1][j]);
				tmp_m->x = MY[0][i];
				tmp_m->y = MY[1][i];
				tmp_e->x = ENEMY[0][j];
				tmp_e->y = ENEMY[1][j];
			}
		}
	}
}
