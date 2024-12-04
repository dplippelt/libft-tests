# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 13:57:14 by dlippelt          #+#    #+#              #
#    Updated: 2024/12/04 13:04:01 by dlippelt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Change PDIR according the where the project folder is located
PDIR = $(HOME)/codam/main/libft
NAME = $(PDIR)/libft.a
MAIN = main.c

CC = cc
AR = ar

CFLAGS = -Wall -Werror -Wextra -c
ARFLAGS = rcs
TESTFLAGS = -Wall -Werror -Wextra
LBSD = -lbsd

SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c
FSRCS = $(addprefix $(PDIR)/, $(SRCS))
FOBJS = $(FSRCS:.c=.o)


BSRCS = ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c
FBSRCS = $(addprefix $(PDIR)/, $(BSRCS))
FBOBJS = $(FBSRCS:.c=.o)

all: $(NAME)

$(NAME): $(FOBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $<

bonus: $(FOBJS) $(FBOBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

test: $(FSRCS) $(FBSRCS) $(MAIN)
	$(CC) $(TESTFLAGS) $^ $(LBSD)

clean:
	rm -f $(FOBJS) $(FBOBJS)
	rm -f *.gch
	rm -f *.txt

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re test bonus
