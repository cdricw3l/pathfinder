CC=clang
GFLAGS=-Wall -Werror -Wextra
NAME=pathfinder
NAME_PERF=cost_and_perf/cost_and_perf
SRCS=${wildcard *.c}
SRCS_PERF=${wildcard cost_and_perf/*.c}
SRCS_OBJS= ${SRCS:.c=.o}
PERF_OBJS= ${SRCS_PERF:.c=.o}
COM="pathfinder"

%.o:%.c 
	${CC} ${GFLAGS} -c $^ -o $@

${NAME}: ${SRCS_OBJS}
	${CC} ${GFLAGS} ${SRCS_OBJS} -o ${NAME}

perf: ${SRCS_OBJS} ${PERF_OBJS}
	${CC} ${GFLAGS} ${SRCS_OBJS} ${PERF_OBJS} -o ${NAME_PERF}
	./${NAME_PERF}

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