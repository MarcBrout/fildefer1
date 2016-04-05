##
## Makefile for bistro in /home/bougon_p/rendu/Piscine_C_bistromathique
## 
## Made by Pierre Bougon
## Login   <bougon_p@epitech.net>
## 
## Started on  Thu Oct 29 14:45:48 2015 Pierre Bougon
## Last update Tue Feb 23 18:10:13 2016 
##

SRCP	= ./src/

SRC     = $(SRCP)fdf.c \
	$(SRCP)tekline.c \
	$(SRCP)tekllproject.c \
	$(SRCP)tekpixel.c \
	$(SRCP)aff_fdf.c \
	$(SRCP)set_fdf.c \
	$(SRCP)my_getnbr.c \
	$(SRCP)my_putstr_err.c \
	$(SRCP)my_strcmp.c \
	$(SRCP)fdf_loop.c

OBJS    = $(SRC:.c=.o)

NAME    = fdf1

CC      = gcc

CFLAGS  = -W -Wall -Werror -ansi -pedantic

CFLAGS	+= -I/home/${USER}/.froot/include

LDFLAGS = -L/usr/local/lib \
	-L/home/${USER}/.froot/lib \
	-llapin \
	-lsfml-audio \
	-lsfml-graphics \
	-lsfml-window \
	-lsfml-system \
	-lstdc++ -ldl \
	-lm \
	-L./lib/ \

RM      = rm -f

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
