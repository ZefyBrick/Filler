# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 16:44:07 by cdubuque          #+#    #+#              #
#    Updated: 2019/11/04 04:09:14 by cdubuque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FL = cdubuque.filler

INC = ./inc/filler.h

LIB = libft/libft.a

FLFILES = filler.c get_next_line.c  writing.c find_position.c tools.c \
find_now_position.c find_the_best_position.c vm.c

FLSRC = $(addprefix src/,$(FLFILES))

FLOBJ = $(addprefix obj/,$(FLFILES:.c=.o))

FLAGS = -g -Wall -Wextra -Werror

all : $(FL)

$(FL) : $(FLOBJ)
	@make -C libft/
	@gcc -o $(FL) $(FLOBJ) $(LIB)

obj/%.o: src/%.c $(INC)
	@mkdir -p obj/
	@gcc $(FLAGS) -Iinc -o $@ -c $<

clean :
	@make clean -C libft/
	@rm -rf obj/

fclean : clean
	@make fclean -C libft
	@rm -f $(FL)

re : fclean all
