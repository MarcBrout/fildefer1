##
## Makefile for my Makefile in /home/brout_m/rendu/Piscine_C_J10/lib
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Fri Oct  9 09:57:50 2015 marc brout
## Last update Tue Nov 17 13:32:49 2015 marc brout
##

SRC	= my_find_prime_sup.c \
	my_getnbr.c \
	my_isneg.c \
	my_is_prime.c \
	my_power_rec.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_revstr.c \
	my_showmem.c \
	my_showstr.c \
	my_sort_int_tab.c \
	my_square_root.c \
	my_strcapitalize.c \
	my_strcat.c \
	my_strcmp.c \
	my_strcpy.c \
	my_str_isalpha.c \
	my_str_islower.c \
	my_str_isnum.c \
	my_str_isprintable.c \
	my_str_isupper.c \
	my_strlen.c \
	my_strlowcase.c \
	my_strncat.c \
	my_strcat.c \
	my_strncmp.c \
	my_strncpy.c \
	my_strstr.c \
	my_strupcase.c \
	my_swap.c \
	my_printf.c \
	my_printfcsspb.c \
	my_printfdiouxx.c \
	my_strdup.c \
	my_printfmetc.c

LIBPATH	= ../

HPATH	= ../../include/

OBJ	= $(SRC:.c=.o)

LIB	= libmy.a

HEAD	= my.h

CC	= cc

RM	= rm -f

NAME	= $(LIB)

all: $(LIB)

$(LIB): $(OBJ)
	@ar rc $(LIB) $(OBJ)
	@ranlib $(LIB)
	@cp $(LIB) $(LIBPATH)
	@cp $(HEAD) $(HPATH)

$(HEAD):
	cp $(HEAD) $(HPATH)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(LIB)
	@$(RM) $(LIBPATH)$(LIB)
	@$(RM) $(HPATH)$(HEAD)

re: fclean all clean
