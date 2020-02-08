/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:46:27 by cdubuque          #+#    #+#             */
/*   Updated: 2019/11/04 04:03:46 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdarg.h>
# define BUFF_SIZE 2
# define MAP (*play)->map
# define MAP_X (*play)->map_x
# define MAP_Y (*play)->map_y
# define PL_Y (*play)->pl_y
# define PL_X (*play)->pl_x
# define PLAYER (*play)->player
# define START (*play)->start
# define ENEMY (*play)->enemy
# define MY (*play)->my
# define XY (*play)->xy
# define MAN (*play)->man
# define D_PL_X (*play)->duble_x
# define D_PL_Y (*play)->duble_y

typedef struct		s_start
{
	int				x;
	int				y;
}					t_start;

typedef struct		s_player
{
	int				player;
	int				**map;
	int				map_x;
	int				map_y;
	int				piece_x;
	int				piece_y;
	int				xy;
	int				*pl_x;
	int				*duble_x;
	int				*pl_y;
	int				*duble_y;
	int				enemy[2][1500];
	int				my[2][1500];
	int				man;
	int				en;
	int				m;
	t_start			*start;
}					t_player;

int					get_next_line(const int fd, char **line);
/*
**filler
*/
void				ft_piece_place_find(t_player **play, char *line);
void				ft_go_parsing(t_player **play);
void				ft_enemy_my(t_player **play);
void				ft_create_play(t_player **play);
/*
**writing
*/
void				ft_piece_full(t_player **play);
void				ft_piece_create(t_player **play, char *line);
void				ft_map_full(t_player **play, char *line);
void				ft_create_map(t_player **play, char *line);
/*
**find_position
*/
int					ft_environment(t_player **play, int c, int j);
void				ft_who_play(t_player **play, int c, int j, int i);
void				ft_create_stacks(t_player **play);
void				ft_find_position(t_player **play, int i);
/*
**tools
*/
void				ft_no_enemy(t_player **play, t_start *tmp_m, int i, \
					int *man);
void				ft_free_gnl(char **line);
void				ft_my_enemy_del(t_player **play);
void				ft_my(t_player **play, int c, int j);
void				ft_enemy(t_player **play, int c, int j);
/*
**find_now_position
*/
void				ft_del_no_exit2(int *del, t_player **play);
int					ft_count_envir(t_player **play, int c, int i);
void				ft_del_no_exit(t_player **play);
void				ft_my_place(t_player **play, t_start *tmp_m, \
					t_start *tmp_e, int man);
void				ft_find_now_position(t_player **play, t_start *tmp_m, \
					t_start *tmp_e);
/*
**find_the_best_position
*/
void				ft_minus_one(t_player **play, t_start *tmp_m, \
					t_start *tmp_e);
void				ft_my_tmp_del(t_player **play, t_start *tmp_m, \
					t_start *tmp_e);
int					ft_valid_or_not(t_player **play, int c, int d, \
					t_start *tmp_e);
int					ft_duble_full(t_player **play, int c, t_start *tmp_m, \
					t_start *tmp_e);
/*
**vm
*/
int					ft_strlen_num(int num);
void				ft_supwrite(t_player **play, char *str, int i);
void				ft_get_cor_to_vrm(t_player **play);
#endif
