NAME := libft.a

CC := gcc

CFLAGS := -Wall -Werror -Wextra

BUILDDIR := build

SRC :=	ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_memmove.c	\
		ft_strlcat.c	\
		ft_strlen.c		\
		ft_bzero.c		\
		ft_isalpha.c	\
		ft_isdigit.c	\
		ft_memcpy.c		\
		ft_memset.c		\
		ft_strlcpy.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strnstr.c	\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\

OBJ := ${addprefix ${BUILDDIR}/, ${SRC:.c=.o}}

all: ${NAME}

${NAME}: ${OBJ}
	@ar rc ${NAME} ${OBJ}

${BUILDDIR}:
	@mkdir ${BUILDDIR}

${BUILDDIR}/%.o: %.c ${BUILDDIR}/
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf ${BUILDDIR}
	@rm -f a.out

fclean: clean
	@rm -f ${NAME}

re:
	@${MAKE} fclean
	@${MAKE} ${NAME}