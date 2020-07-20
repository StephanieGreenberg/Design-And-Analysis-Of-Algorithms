bfs = BestFirstSearch
all: ${bfs}

${bfs}: ${bfs}.o
	g++ -g -Wall -Werror ${bfs}.o -o ${bfs}

${bfs}.o: ${bfs}.cpp
	g++ -c -g -Wall -Werror ${bfs}.cpp -o ${bfs}.o

.PHONY: clean all

clean:
	rm -rf ${bfs} *.o


