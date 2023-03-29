################################################################################
#								COLORS										   #
################################################################################

GREY=\033[30m
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
NAME = PhoneBook

#DIRECTORIES
SRC_DIR  = ./
BUILD_DIR  = ./objs

#SOURCES
S_EXT = .cpp
SRC_FILES =	main.cpp \
			PhoneBook.cpp \
			Contact.cpp
SRCS = ${addprefix ${SRC_DIR}/, ${SRC_FILES}}

#DEPS
D_EXT = .d
DEPS = ${subst ${SRC_DIR}/, ${BUILD_DIR}/, ${SRCS:%${S_EXT}=%${D_EXT}}}

#OBJS
O_EXT = .o
OBJS = ${subst ${SRC_DIR}/, ${BUILD_DIR}/, ${SRCS:%${S_EXT}=%${O_EXT}}}

#COMPILING
CXX = c++
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

-include ${DEPS}

${BUILD_DIR}/%${O_EXT}: ${SRC_DIR}/%${S_EXT}
	@mkdir -p ${dir $@}
	@${ECHO} "${UNDER}${PURPLE}created${END}${PURPLE}: ${@:%=%}${END}"
	@${CC} ${CXXFLAGS} -MMD -o $@ -c $<

################################################################################
#                              ADDITIONAL RULES								   #
################################################################################

val: ${NAME}
	valgrind ./${NAME}

clean:
	@${RM} ${BUILD_DIR}
	@${ECHO} "${UNDER}${RED}deleted${END}${RED}: objs & deps${END}"

fclean: clean
	@${RM} ${NAME}
	@${ECHO} "${UNDER}${RED}deleted${END}${RED}: program${END}\n"

gitm:
	git add .
	git commit
	git push

re: fclean all

.PHONY: all val clean fclean gitm re