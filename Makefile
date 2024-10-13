main:
	gcc main.c src/* 
test:
	gcc tests/lexer_test.c src/* tests/util.h tests/util.c
	./a.out
	gcc tests/parser_test.c src/* tests/util.h tests/util.c
	./a.out
	$(MAKE) clean
	rm tests/util.h.gch
clean:
	rm ./a.out
	rm src/generator.h.gch
	rm src/lexer.h.gch
	rm src/parser.h.gch
