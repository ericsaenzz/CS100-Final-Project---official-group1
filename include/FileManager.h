#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "Task.h"
#include <vector>
#include <string>

class FileManager {
private:
    std::string filename;

public:
    FileManager(const std::string& filename = "tasks.txt");
    void saveTasks(const std::vector<Task>& tasks) const;
    std::vector<Task> loadTasks() const;
};

#endif