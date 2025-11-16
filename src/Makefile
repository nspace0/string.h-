CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LIBFLAGS = -lm -lpthread

ifeq ($(shell uname), Darwin)
    CFLAGS += -I/opt/homebrew/Cellar/check/0.15.2/include
    LIBFLAGS += -L/opt/homebrew/Cellar/check/0.15.2/lib -lcheck
endif

ifeq ($(shell uname), Linux)
    CFLAGS += -I/usr/include/check
    LIBFLAGS += -L/usr/lib -lcheck -lsubunit -lm
endif

CFILES = $(wildcard s21_*.c)
OFILES = $(patsubst %.c, %.o, $(CFILES))

TEST_DIR = tests
TEST_CFILES = $(wildcard $(TEST_DIR)/*_test.c)
TEST_OFILES = $(patsubst %.c, %.o, $(TEST_CFILES))

all : s21_string.a

s21_string.a : $(CFILES)
	$(CC) -c $(CFLAGS) $(CFILES)
	ar rcs $@ $(OFILES)
	ranlib $@

test : clean $(TEST_CFILES) s21_string.a
	$(CC) $(CFLAGS) $(TEST_CFILES) s21_string.a -o test.out $(LIBFLAGS)
	./test.out

gcov_report : CFLAGS += -coverage
gcov_report : clean test
	gcov -f $(CFILES)
	mkdir report
	./test.out
	lcov --directory . --capture --output-file coverage.info
	genhtml coverage.info --output-directory ./report
	
	
check :
	clang-format -style='{BasedOnStyle: Google}' -n *.c */*.c
	clang-format -style='{BasedOnStyle: Google}' -n *.h */*.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h	

clang :
	clang-format -style='{BasedOnStyle: Google}' -i *.c */*.c
	clang-format -style='{BasedOnStyle: Google}' -i *.h */*.h

clean :
	rm -f *.o *.a
	rm -f ./test.out
	rm -f *.gcno *.gcov *.gcda
	rm -f *.info
	rm -fr ./report

.PHONY : all clean test s21_string.a  gcov_report check 
