LIBRARY = libprotect.so
TEST = testprotect
SRC_LIB = libprotect.c
SRC_TEST = testprotect.c
CC = cc
CFLAGS_LIB = -fPIC
CFLAGS_TEST = 
LDFLAGS = -shared
.PHONY: all clean run
all: $(LIBRARY) $(TEST)
$(LIBRARY): $(SRC_LIB)
	$(CC) $(LDFLAGS) $(CFLAGS_LIB) -o $@ $^ -ldl
$(TEST): $(SRC_TEST)
	$(CC) $(CFLAGS_TEST) -o $@ $^
run: all
	LD_PRELOAD=./$(LIBRARY) ./$(TEST)
clean:
	rm -f $(LIBRARY) $(TEST) PROTECT_me.txt
