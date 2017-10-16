CC= g++ -std=c++11
CFLAGS=-I.
CXXFLAGS += -std=c++11
DEPS = utils.h ArrayQueue.h array.h PriorityQueueSort.h PriorityQueueSearch.h Shopper.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

project0: main.o
	$(CC) -o project0 main.o -I.

# --- remove binary and executable files
clean:
	rm -f main.o project0
