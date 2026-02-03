CC = g++
CFLAGS = -std=c++23 -Wall -Wextra -Wpedantic
TARGET = main
SRCS = main.cpp tokenizer.cpp parser.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)