CXXFLAGS = -g -Wall -Werror -pedantic

src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

all : suba

suba : $(obj)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean :
	rm suba *~ *.o
