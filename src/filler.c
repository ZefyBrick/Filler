/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:55:07 by cdubuque          #+#    #+#             */
/*   Updated: 2019/11/04 04:10:11 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_piece_place_find(t_player **play, char *line)
{
	ft_piece_create(play, line);
	ft_piece_full(play);
	ft_find_position(play, 0);
	ft_get_cor_to_vrm(play);
}

void			ft_go_parsing(t_player **play)
{
	char		*line;
	int			i;

	get_next_line(0, &line);
	if (ft_strstr(line, "Plateau") != NULL && MAP_X == -1)
		ft_create_map(play, line);
	free(line);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau") != NULL)
			ft_free_gnl(&line);
		i = -1;
		while (++i < MAP_Y)
		{
			ft_free_gnl(&line);
			ft_map_full(play, line);
		}
		ft_free_gnl(&line);
		if (ft_strstr(line, "Piece") != NULL)
			ft_piece_place_find(play, line);
		else
			exit(0);
		free(line);
	}
}

void			ft_enemy_my(t_player **play)
{
	int			c;
	int			i;

	c = -1;
	while (++c < 2)
	{
		i = -1;
		while (++i < 1500)
			ENEMY[c][i] = -1;
	}
	c = -1;
	while (++c < 2)
	{
		i = -1;
		while (++i < 1500)
			MY[c][i] = -1;
	}
}

void			ft_create_play(t_player **play)
{
	if (!((*play) = (t_player *)malloc(sizeof(t_player))))
		exit(0);
	if (!(START = (t_start *)malloc(sizeof(t_start))))
		exit(0);
	ft_enemy_my(play);
	PLAYER = 0;
	MAP_X = -1;
	MAP_Y = -1;
	(*play)->piece_x = -1;
	(*play)->piece_y = -1;
	START->x = -1;
	START->y = -1;
	XY = -1;
	MAN = -1;
	(*play)->m = -1;
	(*play)->en = -1;
}

int				main(void)
{
	char		*line;
	t_player	*play;
	int			i;

	i = -1;
	ft_create_play(&play);
	if (get_next_line(0, &line) && ft_strstr(line, "$$$") != NULL)
	{
		if (line[10] == '1')
			play->player = 1;
		else
			play->player = 2;
		free(line);
		ft_go_parsing(&play);
	}
	exit(0);
}
