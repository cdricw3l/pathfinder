CC=clang
GFLAGS=-Wall -Werror -Wextra
NAME=pathfinder
SRCS=${wildcard *.c}
SRCS_OBJS= ${SRCS:.c=.o}
COM="pathfinder"

%.o:%.c 
	${CC} ${GFLAGS} -c $^ -o $@

${NAME}: ${SRCS_OBJS}
	${CC} ${GFLAGS} ${SRCS_OBJS} -o ${NAME}

run: ${NAME}
	./${NAME}

clean:
	rm -rf ${SRCS_OBJS}

fclean: clean
	rm -rf ${NAME}

git: fclean
	git add .
	git commit -m ${COM}
	git push origin ${shell git branch --show-current}