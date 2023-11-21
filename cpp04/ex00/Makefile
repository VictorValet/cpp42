# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 16:10:39 by vvalet            #+#    #+#              #
#    Updated: 2023/11/08 13:28:36 by vvalet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	test

#------------------------------------PATH--------------------------------------

OBJ_PATH	=	objs/

#---------------------------------COMPILATION----------------------------------

CC			= 	c++

FLAGS		=	-Wall -Wextra -Werror -std=c++98

#---------------------------------SOURCE FILES---------------------------------

SRCS		=	test.cpp\
				Animal.cpp\
				Cat.cpp\
				Dog.cpp\
				WrongAnimal.cpp\
				WrongCat.cpp

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
