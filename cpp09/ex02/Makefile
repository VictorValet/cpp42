# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 16:10:39 by vvalet            #+#    #+#              #
#    Updated: 2024/01/08 11:54:25 by vvalet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	PmergeMe

#------------------------------------PATH--------------------------------------

OBJ_PATH	=	objs/

#---------------------------------COMPILATION----------------------------------

CC			= 	c++

FLAGS		=	-Wall -Wextra -Werror -std=c++98

#---------------------------------SOURCE FILES---------------------------------

SRCS		=	main.cpp\
				PmergeMe.cpp

#-----------------------------------OBJECTS------------------------------------

OBJS_FILES	=	${SRCS:.cpp=.o}

OBJS		=	${addprefix ${OBJ_PATH}, ${OBJS_FILES}} 

#------------------------------------RULES-------------------------------------

all: ${NAME}

${OBJ_PATH}:
	mkdir -p ${OBJ_PATH}

${OBJ_PATH}%.o: %.cpp
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ_PATH} ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}
	rm -Rf ${OBJ_PATH}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
