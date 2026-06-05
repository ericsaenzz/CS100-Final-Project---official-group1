#include "TaskManager.h"
#include <iostream>

using namespace std;

TaskManager::TaskManager() : nextId(1) {}

void TaskManager::setTasks(const vector<Task>& loadedTasks) {
    tasks = loadedTasks;
    nextId = 1;

    for (const Task& task : tasks) {
        if (task.getId() >= nextId) {
            nextId = task.getId() + 1;
        }
    }
}

vector<Task> TaskManager::getTasks() const {
    return tasks;
}

void TaskManager::addTask(const string& title, const string& deadline,
                          int priority, int estimatedMinutes) {
    tasks.push_back(Task(nextId, title, deadline, priority, estimatedMinutes));
    nextId++;

    cout << "Task added." << endl;
}

void TaskManager::viewTasks() const {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    cout << endl;
    cout << "===== All Tasks =====" << endl;

    for (const Task& task : tasks) {
        task.display();
        cout << "---------------------" << endl;
    }
}

void TaskManager::markTaskCompleted(int id) {
    int index = findTaskIndexById(id);

    if (index == -1) {
        cout << "Task not found." << endl;
        return;
    }

    tasks[index].markCompleted();
    cout << "Task marked as completed." << endl;
}

int TaskManager::findTaskIndexById(int id) const {
    for (int i = 0; i < static_cast<int>(tasks.size()); i++) {
        if (tasks[i].getId() == id) {
            return i;
        }
    }

    return -1;
}