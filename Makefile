CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC = src/main.cpp src/TaskManager.cpp src/FileManager.cpp src/Scheduler.cpp src/NotificationSystem.cpp src/SortingFiltering.cpp
TARGET = task_manager

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) tasks.txt