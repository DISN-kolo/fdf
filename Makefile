# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 13:41:10 by akozin            #+#    #+#              #
#    Updated: 2024/02/10 15:27:58 by akozin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/
LIBFT_A = $(addprefix $(LIBFT), libft.a)

MLX = mlx/
MLX_A = $(addprefix $(MLX), libmlx.a)

GNL = gnl/
GNL_A = $(addprefix $(GNL), libgnl.a)

NAME = fdf

MAKE = make

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = fdf.c
OBJS = $(SRCS:.c=.o)
DFILES = $(SRCS:.c=.d)

RM = rm -f

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT_A) $(MLX_A) $(GNL_A)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -Imlx -MMD -MP -c -o $@ $<

$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

$(MLX_A):
	$(MAKE) -C $(MLX)

$(GNL_A):
	$(MAKE) -C $(GNL)

-include $(DFILES)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(MAKE) clean -C $(MLX)
	$(MAKE) clean -C $(GNL)
	$(RM) $(OBJS) $(DFILES)

fclean:		clean
	$(MAKE) fclean -C $(LIBFT)
	$(MAKE) fclean -C $(GNL)
	$(RM) $(NAME)

re:			fclean all

.PHONY = all clean fclean re
