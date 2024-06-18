# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 11:52:48 by akozin            #+#    #+#              #
#    Updated: 2024/06/18 16:40:01 by akozin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIE
CFILES = get_next_line.c get_next_line_utils.c
OFILES = $(CFILES:.c=.o)
DFILES = $(CFILES:.c=.d)

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

$(OFILES): %.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c -o $@ $<

-include $(DFILES)

clean:
	$(RM) $(OFILES) $(DFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
