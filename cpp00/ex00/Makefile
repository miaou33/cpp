
################################################################################
#                                VARIABLES									   #
################################################################################

#PROGRAM
NAME = megaphone

#DIRECTORIES
SRC_DIR  = ./srcs
BUILD_DIR  = ./objs

#SOURCES
S_EXT = .cpp
SRC_FILES =	megaphone.cpp
SRCS = ${addprefix ${SRC_DIR}/, ${SRC_FILES}}

#DEPS
D_EXT = .d
DEPS = ${subst ${SRC_DIR}/, ${BUILD_DIR}/, ${SRCS:%${S_EXT}=%${D_EXT}}}

#OBJS
O_EXT = .o
OBJS = ${subst ${SRC_DIR}/, ${BUILD_DIR}/, ${SRCS:%${S_EXT}=%${O_EXT}}}

#COMPILING
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

################################################################################
#                                MAIN RULES								       #
################################################################################
all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

-include ${DEPS}

${BUILD_DIR}/%${O_EXT}: ${SRC_DIR}/%${S_EXT}
	@mkdir -p ${dir $@}
	@echo create: ${@:%=%}
	@${CC} ${CFLAGS} -MMD -o $@ -c $<

################################################################################
#                              ADDITIONAL RULES								   #
################################################################################

val: ${NAME}
	valgrind ./${NAME}

clean:
	@${RM} ${BUILD_DIR}
	@echo "objs deleted"

fclean: clean
	@${RM} ${NAME}
	@echo "program deleted"

gitm:
	git add .
	git commit
	git push

re: fclean all

.PHONY: all val clean fclean gitm re