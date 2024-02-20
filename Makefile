# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 13:41:10 by akozin            #+#    #+#              #
#    Updated: 2024/02/20 14:51:55 by akozin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/
LIBFT_A = $(addprefix $(LIBFT), libft.a)

MLX = mlx/
MLX_A = $(addprefix $(MLX), libmlx.a)

GNL = gnl/
GNL_A = $(addprefix $(GNL), libgnl.a)

FTPRINTF = ft_printf/
FTPRINTF_A = $(addprefix $(FTPRINTF), libftprintf.a)

NAME = fdf

MAKE = make

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCNAMES = fdf.c \
	   read_map.c \
	   drawer.c \
	   line_iterator.c \
	   image_handler.c \
	   keycode_handler.c \
	   miscutils.c

SRCS = $(addprefix src/, $(SRCNAMES))
OBJS = $(SRCS:.c=.o)
DFILES = $(SRCS:.c=.d)

RM = rm -f

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT_A) $(MLX_A) $(GNL_A) $(FTPRINTF_A)
	$(CC) $(OBJS) -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(FTPRINTF) -lftprintf -L$(MLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJS): %.o: %.c Makefile
	$(CC) $(CFLAGS) -Imlx -MMD -MP -c -o $@ $<

$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

$(MLX_A):
	$(MAKE) -C $(MLX)

$(GNL_A):
	$(MAKE) -C $(GNL)

$(FTPRINTF_A):
	$(MAKE) -C $(FTPRINTF)

-include $(DFILES)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(MAKE) clean -C $(MLX)
	$(MAKE) clean -C $(GNL)
	$(MAKE) clean -C $(FTPRINTF)
	$(RM) $(OBJS) $(DFILES)

fclean:	
	$(MAKE) fclean -C $(LIBFT)
	$(MAKE) clean -C $(MLX)
	$(MAKE) fclean -C $(GNL)
	$(MAKE) fclean -C $(FTPRINTF)
	$(RM) $(OBJS) $(DFILES)
	$(RM) $(NAME)

re:			fclean all

.PHONY = all clean fclean re
