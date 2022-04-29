CXX = g++
EXEC = prog
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
CFLAGS =-Wall -Wextra -Werror

all : $(EXEC)

%.o : %.cpp
	$(CXX) -o $@ -c $< $(CFLAGS)

$(EXEC) : $(OBJ)
	$(CXX) -o $@ $^
