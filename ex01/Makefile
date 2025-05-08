# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjorge-l < tjorge-l@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 17:18:15 by asafrono          #+#    #+#              #
#    Updated: 2025/05/08 15:33:00 by tjorge-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = registry

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
RM = rm -rf

DEBUG_FLAGS = -g
VFLAGS = -s --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes

SRCS = main.cpp PhoneBook.cpp Contact.cpp

OBJS = $(SRCS:%.cpp=%.o)


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	valgrind $(VFLAGS) ./$(NAME)

debug: CFLAGS = -g -Wall -Wextra -Werror
debug: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

rdebug: debug
	valgrind $(VFLAGS) ./$(NAME)

.PHONY: all clean fclean re
