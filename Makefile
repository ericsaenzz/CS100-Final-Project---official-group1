CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = task_scheduler
SOURCES = TaskManager.cpp main.cpp
HEADERS = Task.h TaskManager.h UndoSystem.h Scheduler.h DateHelper.h FileManager.h Subtask.h
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run