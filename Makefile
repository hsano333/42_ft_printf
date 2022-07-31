CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I ${HEAD}
NAME 	= libftprintf.a
LIBFT = ./libft
PRE		= ./srcs/
HEAD	= ./include
SRC		= ft_printf.c 
SRCS	= ${addprefix ${PRE}, ${SRC}}
OBJS	= $(SRCS:.c=.o)
LIBFTNAME = libft.a
LIBFTOBJS = ${LIBFT}/${LIBFTNAME}

all:	${NAME}

${NAME}	:	${OBJS} ${LIBFTOBJS}
			ar rcs ${NAME} ${OBJS} ${LIBFTOBJS}

${LIBFTOBJS}	:
			make -C $(LIBFT)
clean	:
			${RM} ${OBJS}
			${RM} ${OBJS}
			make clean -C $(LIBFT)

fclean	:	clean
			${RM} ${NAME}
			${RM} ${LIBFTOBJS}

re		:	fclean all
