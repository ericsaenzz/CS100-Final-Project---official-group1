#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "Task.h"
#include <vector>
#include <string>

using namespace std;

class FileManager {
private:
    string filename;

public:
    FileManager(string file = "tasks.txt");

    void saveTasks(vector<Task> tasks);
    vector<Task> loadTasks();
};

#endif
