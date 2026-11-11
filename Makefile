CXX ?= g++
CXXFLAGS ?= -std=c++11 -Wall -Wextra -pedantic
TARGET := attendance
SOURCE := attendance.cpp

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
