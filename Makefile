_GUI = $(if $(NOGUI),,-D GUI -Werror)
_DEBUG = $(if $(DEBUG),-D DEBUG,)
_OPT = $(if $(OPT),-O3 -flto,)
CC = gcc
CFLAGS = -g -std=c99 -Wall $(_OPT) $(_GUI) $(_DEBUG) -I./include
LDFLAGS = -lSDL -lm

.PHONY: clean doc check-syntax compile-all launch-tests

# rule to generate the doxygen documentation
doc:
	doxygen conf/doxygen.conf

# rule to remove all .o files and all executables
clean:
	- rm -f *.o
	- find . -maxdepth 1 -executable -type f \( ! -name "Makefile" \) -delete

# compile rules
%.o: ./src/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

%.o: ./tests/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

# you should put all the .o files corresponding to your .c files as prerequisites of
# this rule (see examples)
# \ allows to go on the next line
check-syntax: example-main.o  \
	 loader.o test-loader.o particle.o test-particle.o event.o test-event.o test-simulation.o clash-of-particles-naive-file.o clash-of-particles-naive-random.o

# put all the rules to build your applications and tests here (see examples)
example-main: example-main.o
	$(CC) $(CFLACS) -o example-main example-main.o

example-string: example-string.o
	$(CC) $(CFLACS) -o example-string example-string.o

read-file-formatted: read-file-formatted.o
	$(CC) $(CFLACS) -o read-file-formatted read-file-formatted.o

read-file-text: read-file-text.o
	$(CC) $(CFLACS) -o read-file-text read-file-text.o

write-fact: write-fact.o
	$(CC) $(CFLAGS) -o write-fact write-fact.o
	
practice-readfile: practice-readfile.o
	$(CC) $(CFLAGS) -o practice-readfile practice-readfile.o

test-dummy: test-dummy.o
	$(CC) $(CFLACS) -o test-dummy test-dummy.o
	
test-particle: test-particle.o particle.o
	$(CC) $(CFLACS) -o test-particle test-particle.o particle.o $(LDFLAGS)
	
test-loader: test-loader.o loader.o particle.o
	$(CC) $(CFLAGS) -o test-loader test-loader.o loader.o particle.o $(LDFLAGS)
	
test-event: test-event.o event.o particle.o
	$(CC) $(CFLAGS) -o test-event test-event.o event.o particle.o $(LDFLAGS)
	
test-simulation: test-simulation.o loader.o particle.o event.o disc.o
	$(CC) $(CFLAGS) -o test-simulation test-simulation.o loader.o particle.o event.o disc.o $(LDFLAGS)
	
test-correctness-heap: test-correctness-heap.o heap.o event.o particle.o
	$(CC) $(CFLAGS) -o test-correctness-heap test-correctness-heap.o heap.o event.o particle.o $(LDFLAGS)

clash-of-particles-naive-file: clash-of-particles-naive-file.o simulation-naive.o loader.o particle.o event.o disc.o
	$(CC) $(CFLAGS) -o clash-of-particles-naive-file clash-of-particles-naive-file.o simulation-naive.o loader.o particle.o event.o disc.o $(LDFLAGS)

clash-of-particles-naive-random: clash-of-particles-naive-random.o simulation-naive.o loader.o particle.o event.o disc.o
	$(CC) $(CFLAGS) -o clash-of-particles-naive-random clash-of-particles-naive-random.o simulation-naive.o loader.o particle.o event.o disc.o $(LDFLAGS)

# the snow app. Beware, for graphical applications, you MUST add $(LDFLAGS)!
snow: snow.o disc.o ./include/disc.h
	$(CC) $(CFLAGS) -o snow snow.o disc.o $(LDFLAGS)
	
	
	
valgrind: clash-of-particles-naive-file
	valgrind --leak-check=full ./clash-of-particle-naive-file

# put all your applications and tests executables as prerequisite of this rule
# \ allows to go to the next line
compile-all: clash-of-particles-naive-random clash-of-particles-naive-file

# add all your test executables in the following variable. You should respect
# the order given in the project text
# \ allows to go to the next line
ALL_TESTS = test-dummy test-particle test-event

launch-tests: $(ALL_TESTS)
	for x in $(ALL_TESTS); do ./$$x --all; done

# add all .c, .h and .txt files in repository	
#svn add --force test/*c src/*.c include/*.h data/*.txt --auto-props --parents --depth infinity -q
