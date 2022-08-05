

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I ${HEAD}
#CFLAGS	= -I ${HEAD}
NAME 	= libftprintf.a
LIBFT = ./libft
PRE		= ./srcs/
HEAD	= ./include
SRC		= parse.c parse_utils.c ft_atoi_base.c print.c ft_strnbr_base.c print_digit.c print_str.c print_utils.c
ifdef WITH_BONUS
SRC += ft_printf_bonus.c
else
SRC += ft_printf.c 
endif
SRCS	= ${addprefix ${PRE}, ${SRC}}
OBJS	= $(SRCS:.c=.o)
LIBFTNAME = libft.a
LIBFTOBJS = ${LIBFT}/${LIBFTNAME}

all:	
		make bonus -C $(LIBFT)
		make ${NAME}

${NAME}	:	${OBJS} ${LIBFTOBJS}
			echo "test"
			cp ${LIBFTOBJS} ${NAME}
			ar rcs ${NAME} ${OBJS} 

clean	:
			${RM} ${OBJS}
			${RM} ${OBJS}
			make clean -C $(LIBFT)

fclean	:	clean
			${RM} ${NAME}
			${RM} ${LIBFTOBJS}

re		:	fclean all

bonus	:	
			make WITH_BONUS=1

