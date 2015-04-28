# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/25 19:58:06 by ncoden            #+#    #+#              #
#    Updated: 2015/04/28 13:05:08 by ncoden           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
#CFLAGS = 
CFLAGS = -Wall -Werror -Wextra

LIBDIR = .
SRCDIR = src
OBJDIR = obj
INCDIR = \
	includes\
	libft/includes

LIB = libft/libft.a
SRC =\
	ft_printf.c\
	arg.c\
	print.c

DEVNAME = ft_printf
DEVMAIN = main.c

LIBS = $(addprefix $(LIBDIR)/, $(LIB))
LIBS_DIRS = $(sort $(dir $(LIBS)))

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(patsubst %.c, %.o,$(SRC)))
OBJS_DIRS = $(sort $(dir $(OBJS)))

INCDIR += $(LIBS_DIRS)
INCS = $(addprefix -I , $(INCDIR))

TEMPNAME = $(addprefix $(OBJDIR)/, $(NAME))
DEVMAIN_OBJ = $(addprefix $(OBJDIR)/, $(patsubst %.c, %.o,$(DEVMAIN)))

all: $(NAME)
$(NAME): build $(LIBS) $(OBJS)
	@ar rc $(TEMPNAME) $(OBJS)
	@libtool -static -o $(NAME) $(TEMPNAME) $(LIBS)
	@ranlib $(NAME)
build:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJS_DIRS)
clean:
	@rm -f $(TEMPNAME)
	@rm -f $(LIBS)
	@rm -f $(OBJS)
fclean: clean
	@rm -f $(NAME)
re: fclean all

dev: fclean build $(LIBS) $(OBJS) $(DEVMAIN_OBJ)
	@gcc -o $(DEVNAME) $(LIBS) $(OBJS) $(DEVMAIN_OBJ) $(INCS) $(CFLAGS)
	@./$(DEVNAME)

$(LIBDIR)/%.a:
	@make -s -C $(@D)
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -c -o $@ $< $(INCS) $(CFLAGS)