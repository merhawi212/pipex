# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 20:21:25 by mkiflema          #+#    #+#              #
#    Updated: 2023/02/22 19:53:51 by mkiflema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

M_SRCS	= ft_pipex.c ft_utils.c main.c
B_SRCS	= ft_pipex_bonus.c constr_pipex_bonus.c ft_utils_bonus.c ft_here_doc_bonus.c main_bonus.c

CFLAGS	= -Wall -Wextra -Werror
#  -fsanitize=address 
CC 		= cc
RM		= rm -f

M_OBJS	= $(M_SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(M_OBJS)
	@cd ./libft && make
	@$(CC) $(CFLAGS) $(M_OBJS) ./libft/libft.a -o $(NAME)

clean:
	@cd ./libft && make clean
	@$(RM) $(M_OBJS) $(B_OBJS)

fclean: clean
	@cd ./libft && make fclean
	@$(RM) $(NAME)

re: fclean all

bonus: $(B_OBJS)
	@cd ./libft && make
	@$(CC) $(CFLAGS) $(B_OBJS) ./libft/libft.a -o $(NAME)
