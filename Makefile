# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppipes <ppipes@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/03 16:22:35 by ppipes            #+#    #+#              #
#    Updated: 2020/11/11 23:22:55 by ppipes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s ft_read.s ft_write.s
OBJ = $(SRC:.s=.o)

.PHONY: all clean fclean re test

%.o: %.s
	nasm -felf64 $<
all: $(NAME)
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME) write.txt a.out
re: fclean all
test:
	gcc main.c -L. -lasm -no-pie && ./a.out
