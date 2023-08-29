program: derle bagla calistir
derle:
	g++ -I "./include" -c ./src/dugum.cpp -o ./lib/dugum.o
	g++ -I "./include" -c ./src/bagliListe.cpp -o ./lib/bagliListe.o
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/bagliListe.o  ./lib/dugum.o   ./lib/main.o -o ./bin/program
calistir:
	./bin/program