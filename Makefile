.PHONY: new run make clean

new:
	cp ./Template/template.cpp . && mv ./template.cpp new.cpp

run:
	make make && ./a.out && make clean

make:
	g++ new.cpp

clean:
	rm -rf *.out