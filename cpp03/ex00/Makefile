UNDER=\033[4m
END=\033[0m

################################################################################
#                               VARIABLES									   #
################################################################################

#PROGRAM
NAME = a.out

#DIRECTORIES
SRC_DIR  = ./
BUILD_DIR  = ./objs

#SOURCES
S_EXT = .cpp
SRC_FILES =	main.cpp \
			ClapTrap.cpp 
			
SRCS = ${addprefix ${SRC_DIR}/, ${SRC_FILES}}

#DEPS
D_EXT = .d
DEPS = ${subst ${SRC_DIR}/, ${BUILD_DIR}/, ${SRCS:%${S_EXT}=%${D_EXT}}}

#OBJS
O_EXT = .o
OBJS = ${subst ${SRC_DIR}/, ${BUILD_DIR}/, ${SRCS:%${S_EXT}=%${O_EXT}}}

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 #-fsanitize=address
RM = rm -rf

#DISPLAY
ECHO = $(if $(filter -e,$(MAKEFLAGS)),echo, echo -e)

################################################################################
#                                MAIN RULES								       #
################################################################################
all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CXXFLAGS} ${OBJS} -o ${NAME}
	@${ECHO} "\n${UNDER}created${END}: ${NAME}"

-include ${DEPS}

${BUILD_DIR}/%${O_EXT}: ${SRC_DIR}/%${S_EXT}
	@mkdir -p ${dir $@}
	@${ECHO} "${UNDER}created${END}: ${@:%=%}"
	@${CC} ${CXXFLAGS} -MMD -o $@ -c $<

################################################################################
#                              ADDITIONAL RULES								   #
################################################################################

val: ${NAME}
	valgrind --leak-check=full --show-reachable=yes ./${NAME}

clean:
	@${RM} ${BUILD_DIR}
	@${ECHO} "${UNDER}deleted${END}: objs & deps"

fclean: clean
	@${RM} ${NAME}
	@${ECHO} "${UNDER}deleted${END}: ${NAME}\n"

gitm:
	git add .
	git commit
	git push

re: fclean all

.PHONY: all val clean fclean gitm re