.PHONY: new run make clean

new:
	cp ./Template/template.cpp . && mv ./template.cpp solution.cpp

run:
	make make && ./a.out && make clean

make:
	g++ -std=c++20 -Ofast solution.cpp

clean:
	rm -r -f *.out