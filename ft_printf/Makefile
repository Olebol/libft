NAME := libftprintf.a

CC := gcc

CFLAGS := -Wall -Werror -Wextra

BUILDDIR := obj

SRC :=	ft_printf.c					\
		ft_printf_conversions.c		\
		ft_jumptable_functions.c	\
		ft_jumptable_functions_two.c\


OBJ := ${addprefix ${BUILDDIR}/, ${SRC:.c=.o}}

all: ${NAME}

${NAME}: ${OBJ}
	@ar rc ${NAME} $^
#	@gcc $@ -o program

${BUILDDIR}:
	@mkdir ${BUILDDIR}

${BUILDDIR}/%.o: %.c | ${BUILDDIR}
	@$(CC) $(CFLAGS) -g -c $< -o $@

norminette:
	@norminette $(SRC) ft_printf.h

clean:
	@rm -rf ${BUILDDIR}
#	@rm -f a.out

fclean: clean
	@rm -f ${NAME}
	@rm -f program

re: fclean ${NAME}

.PHONY: all norminette clean fclean re 