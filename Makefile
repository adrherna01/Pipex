# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 10:33:04 by adrherna          #+#    #+#              #
#    Updated: 2023/12/22 13:21:19 by adrherna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = pipex
CFLAGS   = -g -Wall -Wextra -Werror -fsanitize=address
CFILES   = pipex.c utils.c
OBJ      = $(CFILES:.c=.o)
CC       = cc
LIBFT_DIR = ./libft
LIBFT    = $(LIBFT_DIR)/libft.a


.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft

$(LIBFT):
	make -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_DIR) clean

run: $(NAME)
	./$(NAME)


