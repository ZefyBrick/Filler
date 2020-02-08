/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:20:09 by cdubuque          #+#    #+#             */
/*   Updated: 2019/11/04 03:35:29 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_piece_full(t_player **play)
{
	char		*line;
	int			c;
	int			i;
	int			j;

	c = -1;
	j = -1;
	while (++c < (*play)->piece_y)
	{
		i = -1;
		get_next_line(0, &line);
		while (line[++i] != '\0')
		{
			if (line[i] == '*')
			{
				PL_Y[++j] = c;
				PL_X[j] = i;
			}
		}
		free(line);
	}
}

void			ft_piece_create(t_player **play, char *line)
{
	char		**arr;
	int			c;

	c = -1;
	arr = ft_strsplit(line, ' ');
	(*play)->piece_x = ft_atoi(arr[2]);
	(*play)->piece_y = ft_atoi(arr[1]);
	XY = (*play)->piece_x * (*play)->piece_y;
	if (!(PL_Y = (int *)malloc(sizeof(int) * XY)))
		exit(0);
	if (!(PL_X = (int *)malloc(sizeof(int) * XY)))
		exit(0);
	if (!(D_PL_Y = (int *)malloc(sizeof(int) * XY)))
		exit(0);
	if (!(D_PL_X = (int *)malloc(sizeof(int) * XY)))
		exit(0);
	while (++c < XY)
	{
		PL_Y[c] = -1;
		PL_X[c] = -1;
		D_PL_Y[c] = -1;
		D_PL_X[c] = -1;
	}
	ft_split_free(arr);
}

void			ft_map_full(t_player **play, char *line)
{
	char		**arr;
	int			i;

	i = -1;
	if (ft_strstr(line, "Piece") != NULL)
		exit(0);
	arr = ft_strsplit(line, ' ');
	while (arr[1][++i] != '\0')
	{
		if (arr[1][i] == 'X' || arr[1][i] == 'x')
			MAP[atoi(arr[0])][i] = 2;
		else if (arr[1][i] == 'O' || arr[1][i] == 'o')
			MAP[atoi(arr[0])][i] = 1;
	}
	ft_split_free(arr);
}

void			ft_create_map(t_player **play, char *line)
{
	char		**arr;
	int			c;
	int			i;

	c = -1;
	arr = ft_strsplit(line, ' ');
	MAP_Y = ft_atoi(arr[1]);
	MAP_X = ft_atoi(arr[2]);
	if (!(MAP = (int **)malloc(sizeof(int *) * MAP_Y)))
		exit(0);
	while (++c < MAP_Y)
	{
		if (!(MAP[c] = (int *)malloc(sizeof(int) * MAP_X)))
			exit(0);
		i = -1;
		while (++i < MAP_X)
			MAP[c][i] = 0;
	}
	ft_split_free(arr);
}
