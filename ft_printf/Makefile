NAME := libftprintf.a

CC := gcc

CFLAGS := -Wall -Werror -Wextra

BUILDDIR := obj

SRC :=	ft_printf.c				\
#		printf_conversions.c	\
		


OBJ := ${addprefix ${BUILDDIR}/, ${SRC:.c=.o}}

all: ${NAME}

${NAME}: ${OBJ}
	@ar rc ${NAME} $^
	@gcc $@ -o program

${BUILDDIR}:
	@mkdir ${BUILDDIR}

${BUILDDIR}/%.o: %.c | ${BUILDDIR}
	@$(CC) $(CFLAGS) -g -c $< -o $@

clean:
	@rm -rf ${BUILDDIR}
	@rm -f a.out

fclean: clean
	@rm -f ${NAME}
	@rm -f program

re: fclean ${NAME}

.PHONY: all clean fclean re