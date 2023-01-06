NAME := libftprintf.a

CC := gcc

CFLAGS := -Wall -Werror -Wextra

BUILDDIR := obj

SRC :=	ft_printf.c	\


OBJ := ${addprefix ${BUILDDIR}/, ${SRC:.c=.o}}

all: ${NAME}

${NAME}: ${OBJ}
	@ar rc ${NAME} $^

${BUILDDIR}:
	@mkdir ${BUILDDIR}

${BUILDDIR}/%.o: %.c | ${BUILDDIR}
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf ${BUILDDIR}
	@rm -f a.out

fclean: clean
	@rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re