/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 05:04:37 by olga              #+#    #+#             */
/*   Updated: 2019/11/04 03:17:37 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_environment(t_player **play, int c, int j)
{
	int			count;

	count = 0;
	if (c != 0 && MAP[c - 1][j] == 0)
		++count;
	if (c != MAP_Y - 1 && MAP[c + 1][j] == 0)
		++count;
	if (j != 0 && MAP[c][j - 1] == 0)
		++count;
	if (j != MAP_X - 1 && MAP[c][j + 1] == 0)
		++count;
	return (count);
}

void			ft_who_play(t_player **play, int c, int j, int i)
{
	if (i == 2)
	{
		if (PLAYER == 1)
			ft_enemy(play, j, c);
		else
			ft_my(play, j, c);
	}
	else
	{
		if (PLAYER == 1)
			ft_my(play, j, c);
		else
			ft_enemy(play, j, c);
	}
}

void			ft_create_stacks(t_player **play)
{
	int			c;
	int			j;

	c = -1;
	while (++c < MAP_Y)
	{
		j = -1;
		while (++j < MAP_X)
		{
			if (MAP[c][j] == 1)
			{
				if (ft_environment(play, c, j))
					ft_who_play(play, j, c, 1);
			}
			else if (MAP[c][j] == 2)
				if (ft_environment(play, c, j))
					ft_who_play(play, j, c, 2);
		}
	}
}

void			ft_find_position(t_player **play, int i)
{
	t_start		*tmp_m;
	t_start		*tmp_e;

	if (!(tmp_m = (t_start *)malloc(sizeof(t_start))))
		exit(0);
	tmp_m->x = -1;
	tmp_m->y = -1;
	if (!(tmp_e = (t_start *)malloc(sizeof(t_start))))
		exit(0);
	tmp_e->x = -1;
	tmp_e->y = -1;
	if (i == 0)
		ft_create_stacks(play);
	else if (i == 1 && MY[0][0] == -1)
		return ;
	if (tmp_e->x == -1)
	{
		tmp_e->x = 0;
		tmp_e->y = 0;
	}
	ft_find_now_position(play, tmp_m, tmp_e);
	ft_my_place(play, tmp_m, tmp_e, -1);
	free(tmp_m);
	free(tmp_e);
}
