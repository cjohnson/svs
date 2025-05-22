svsc: src/main.cpp
	mkdir -p build
	g++ -o build/svsc src/main.cpp src/Lexer.cpp

.PHONY: clean
clean:
	rm -r build
