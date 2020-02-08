/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 02:56:02 by cdubuque          #+#    #+#             */
/*   Updated: 2019/11/04 03:00:47 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_strlen_num(int num)
{
	int length;

	length = 1;
	if (num > 9)
	{
		while (num > 9)
		{
			num = num / 10;
			length = length * 10;
		}
	}
	return (length);
}

void			ft_supwrite(t_player **play, char *str, int i)
{
	int del;

	del = ft_strlen_num(START->y);
	while (del > 0)
	{
		str[i++] = (START->y / del) + '0';
		START->y = START->y % del;
		del = del / 10;
	}
	str[i++] = ' ';
	del = ft_strlen_num(START->x);
	while (del > 0)
	{
		str[i++] = (START->x / del) + '0';
		START->x = START->x % del;
		del = del / 10;
	}
	str[i++] = '\n';
	str[i] = '\0';
}

void			ft_get_cor_to_vrm(t_player **play)
{
	char	str[10];

	if (START->x != -1 && START->y != -1)
	{
		ft_supwrite(play, str, 0);
		write(1, str, ft_strlen(str));
	}
	else
		write(1, "-1 -1\n", 6);
}
