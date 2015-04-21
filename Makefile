# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/25 19:58:06 by ncoden            #+#    #+#              #
#    Updated: 2015/03/31 19:54:41 by ncoden           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
CCLIB = -Llibft -lft
CCFLAGS = -Wall -Werror -Wextra

SRCDIR = src
OBJDIR = obj
INCDIR =\
	includes\
	libft/includes\

SRC =\
	main.c\
	ft_printf.c\
	arg.c\
	get.c\
	print.c

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCS = $(addprefix -I , $(INCDIR))

all: $(NAME)
$(NAME): build $(OBJS)
	@make -C libft
	@gcc $(CCLIB) -o $(NAME) $(OBJS)
build:
	@mkdir -p $(OBJDIR)
clean:
	@make -C libft clean
	@rm -f $(OBJS)
fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
re: fclean all

dev : all
	@./$(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@gcc -c $(CCFLAGS) $(INCS) -o $@ $<
