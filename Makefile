NAME = libft.a

COMMON = \
	ft_printf.c \
	ft_printf_chr.c \
	ft_printf_hex.c \
	ft_printf_int.c \
	ft_printf_pct.c \
	ft_printf_ptr.c \
	ft_printf_str.c \
	ft_printf_uint.c \

BONUS = \

OCOMMON = ${COMMON:.c=.o}

OBONUS = ${BONUS:.c=.o}

all:	${NAME}

.c.o:
	gcc -Wall -Wextra -Werror -I . -c $< -o ${<:.c=.o}

$(NAME): ${OCOMMON}
	ar rcs ${NAME} ${OCOMMON}

bonus:	${OCOMMON} ${OBONUS}
	ar rcs ${NAME} ${OCOMMON} ${OBONUS}

clean:
		rm -f ${OCOMMON} ${OBONUS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all