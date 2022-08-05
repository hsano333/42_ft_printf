

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I ${HEAD}
NAME 	= libftprintf.a
LIBFT = ./libft
PRE		= ./srcs/
HEAD	= ./include
SRC		= ft_printf.c parse.c parse_utils.c utils.c ft_atoi_base.c print.c ft_strnbr_base.c print_digit.c print_str.c
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

