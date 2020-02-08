/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:44:17 by cdubuque          #+#    #+#             */
/*   Updated: 2019/11/04 03:23:55 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_no_enemy(t_player **play, t_start *tmp_m, int i, int *man)
{
	if (ENEMY[0][0] == -1)
	{
		if (*man == -1 || *man > ft_modul_int(MY[0][i]) \
		+ ft_modul_int(MY[1][i]))
		{
			*man = ft_modul_int(MY[0][i]) + ft_modul_int(MY[1][i]);
			tmp_m->x = MY[0][i];
			tmp_m->y = MY[1][i];
		}
	}
}

void			ft_free_gnl(char **line)
{
	free(*line);
	get_next_line(0, line);
}

void			ft_my_enemy_del(t_player **play)
{
	int			i;

	i = -1;
	while (++i < 1500 && MY[0][i] != -1)
	{
		MY[0][i] = -1;
		MY[1][i] = -1;
	}
	i = -1;
	while (++i < 1500 && ENEMY[0][i] != -1)
	{
		ENEMY[0][i] = -1;
		ENEMY[1][i] = -1;
	}
	(*play)->m = -1;
	(*play)->en = -1;
	i = -1;
	free(PL_Y);
	free(PL_X);
	free(D_PL_X);
	free(D_PL_Y);
}

void			ft_my(t_player **play, int c, int j)
{
	MY[0][++((*play)->m)] = j;
	MY[1][(*play)->m] = c;
}

void			ft_enemy(t_player **play, int c, int j)
{
	ENEMY[0][++((*play)->en)] = j;
	ENEMY[1][(*play)->en] = c;
}
