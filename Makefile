CC=g++
CFLAGS=--std=c++17 -Wall -Werror -Wextra -lm
CFLAGS2=-fprofile-arcs -ftest-coverage
WASH=rm -rf *.o *.out *css *gcno *gcda *.html .clang-format man_ru *.tgz build MyCalc



OS=$(shell uname)
ifeq ($(OS), Linux)
	LFLAGS = -lgtest -pthread -lgmock --coverage
	LEAKS=CK_FORK=no valgrind --leak-check=full --track-origins=yes -s ./test.out
else
	LFLAGS = -fsanitize=address -lgtest -pthread -lgcov --coverage
	LEAKS=CK_FORK=no leaks --atExit -- ./test.out
endif



all: clean uninstall dvi dist install gcov_report



install: clean uninstall build



uninstall:
	rm -rf $(HOME)/Desktop/SmartCalc_v2_0/



build:
	mkdir build
	cd build; cmake ..
	make -C build
	mkdir -p $(HOME)/Desktop/SmartCalc_v2_0
ifeq ($(OS), Linux)
	mv build/SmartCalc_v2_0 $(HOME)/Desktop/SmartCalc_v2_0/
else
	mv build/SmartCalc_v2_0.app $(HOME)/Desktop/SmartCalc_v2_0/
endif



gcov_report: test
	gcovr -r . --html --html-details -o gcov_report.html
	open gcov_report.html

test: test.o test_valid_user_input.o test_modify_input.o test_reverse_polish_notation.o test_model.o
	$(CC) $^ -o test.out $(LFLAGS) && ./test.out

test.o: src/tests/test.cc
	$(CC) $(CFLAGS2) -c $^ -o $@

test_valid_user_input.o: src/backend/validator/valid_user_input.cc
	$(CC) $(CFLAGS) $(CFLAGS2) -c $^ -o $@

test_modify_input.o: src/backend/back/modify_input.cc
	$(CC) $(CFLAGS) $(CFLAGS2) -c $^ -o $@

test_reverse_polish_notation.o: src/backend/back/reverse_polish_notation.cc
	$(CC) $(CFLAGS) $(CFLAGS2) -c $^ -o $@

test_model.o: src/backend/back/model_calculator.cc
	$(CC) $(CFLAGS) $(CFLAGS2) -c $^ -o $@



dvi:
	makeinfo --html --no-warn --no-validate --force src/man_ru.texi



dist:
	rm -rf MyCalc
	mkdir MyCalc
	cp -r Makefile src/ man_ru/ MyCalc
	tar -czvf ./MyCalc.tar.tgz ./MyCalc
	rm -rf ../MyCalc/



check_clang: *.h *.cc
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n $^
	clang-format -i $^



check_leaks:
	$(LEAKS)



check_cppcheck: *.cc *.h
	cppcheck --language=c++ --std=c++17 --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction $^



clean:
	$(WASH)
