P1 = program1
P2 = program2
P3 = program3

all: ${P1} ${P2} ${P3}

${P1}: ${P1}.o
	g++ -g -Wall -Werror ${P1}.o -o ${P1}

${P1}.o: ${P1}.cpp
	g++ -c -g -Wall -Werror ${P1}.cpp -o ${P1}.o

${P2}: ${P2}.o
	g++ -g -Wall -Werror ${P2}.o -o ${P2}

${P2}.o: ${P2}.cpp
	g++ -c -g -Wall -Werror ${P2}.cpp -o ${P2}.o

${P3}: ${P3}.o
	g++ -g -Wall -Werror ${P3}.o -o ${P3}

${P3}.o: ${P3}.cpp
	g++ -c -g -Wall -Werror ${P3}.cpp -o ${P3}.o


.PHONY: clean all

clean:
	rm -rf ${P1} ${P2} ${P3} *.o

