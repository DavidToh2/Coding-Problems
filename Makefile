.PHONY: new run make clean

new:
	cp ./Template/template_contest.cpp . && mv ./template_contest.cpp solution.cpp

run:
	make make && ./a.out && make clean

make:
	g++ -std=c++20 -Ofast solution.cpp

clean:
	rm -r -f *.out