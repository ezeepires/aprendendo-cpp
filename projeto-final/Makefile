CXX      ?= g++
CXXFLAGS ?= -std=c++20 -Wall -Wextra -g
TARGET   := agenda
SRCS     := $(wildcard src/*.cpp)
OBJS     := $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

limpar:
	rm -f $(OBJS) $(TARGET)

.PHONY: run limpar
