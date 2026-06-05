#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "Task.h"
#include <vector>
#include <string>

class TaskManager {
private:
    std::vector<Task> tasks;
    int nextId;

public:
    TaskManager();

    void setTasks(const std::vector<Task>& loadedTasks);
    std::vector<Task> getTasks() const;

    void addTask(const std::string& title, const std::string& deadline,
                 int priority, int estimatedMinutes);
    void viewTasks() const;
    void markTaskCompleted(int id);

private:
    int findTaskIndexById(int id) const;
};

#endif