################################################################################
#								COLORS										   #
################################################################################

#https://talyian.github.io/ansicolors/

GREY=\033[38;5;251m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
PURPLE=\033[35m
CYAN=\033[36m
WHITE=\033[37m

END=\033[0m
BOLD=\033[1m
UNDER=\033[4m
REV=\033[7m

################################################################################
#                                VARIABLES									   #
################################################################################

#PROGRAM
NAME = megaphone

#DIRECTORIES
SRC_DIR  = ./
BUILD_DIR  = ./objs

#SOURCES
S_EXT = .cpp
SRC_FILES =	megaphone.cpp
SRCS = ${addprefix ${SRC_DIR}/, ${SRC_FILES}}

#OBJS
O_EXT = .o
OBJS = ${subst ${SRC_DIR}/, ${BUILD_DIR}/, ${SRCS:%${S_EXT}=%${O_EXT}}}

#COMPILING
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

#DISPLAY
ECHO = echo #$(if $(filter -e,$(MAKEFLAGS)),echo, echo -e)

################################################################################
#                                MAIN RULES								       #
################################################################################
all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CXXFLAGS} ${OBJS} -o ${NAME}
	@${ECHO} "\n${UNDER}${PURPLE}created${END}${PURPLE}: ${NAME}${END}"

${BUILD_DIR}/%${O_EXT}: ${SRC_DIR}/%${S_EXT}
	@mkdir -p ${dir $@}
	@${ECHO} "${UNDER}${PURPLE}created${END}${PURPLE}: ${@:%=%}${END}"
	@${CC} ${CXXFLAGS} -o $@ -c $<

################################################################################
#                              ADDITIONAL RULES								   #
################################################################################

val: ${NAME}
	valgrind ./${NAME}

clean:
	@${RM} ${BUILD_DIR}
	@${ECHO} "${UNDER}${RED}deleted${END}${RED}: objs${END}"

fclean: clean
	@${RM} ${NAME}
	@${ECHO} "${UNDER}${RED}deleted${END}${RED}: ${NAME}${END}\n"

gitm:
	git add .
	git commit
	git push

re: fclean all

.PHONY: all val clean fclean gitm re