CXXFLAGS = -g -Wall -Werror -pedantic -std=c++11

src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

all : suba

suba : $(obj)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean :
	rm suba *~ *.o
