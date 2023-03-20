all: main

main: main.cpp
	    g++ -std=c++2a -o material_util main.cpp

clean:
	    rm material_util
