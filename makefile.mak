all: cTrace

cTrace: main.o Tree.o Session.o Graph.o Agent.o
	gcc -g -m32 -Wall -o cTrace main.o Tree.o Session.o Graph.o Agent.o

main.o: main.cpp
	gcc -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o main.o main.cpp

Tree.o: Tree.cpp Tree.h
	gcc -g Wall -Weffc++ -std=c++11 -ansi -c -Iinclude -o Tree.o Tree.cpp

Session.o: Session.cpp Session.h
	gcc -g Wall -Weffc++ -std=c++11 -ansi -c -Iinclude -o Session.o Session.cpp

Graph.o: Graph.cpp Graph.h
	gcc -g Wall -Weffc++ -std=c++11 -ansi -c -Iinclude -o Graph.o Graph.cpp

Agent.o: Agent.cpp Agent.h
	gcc -g Wall -Weffc++ -std=c++11 -ansi -c -Iinclude -o Agent.o Agent.cpp

clean:
	rm -f *.o cTrace

