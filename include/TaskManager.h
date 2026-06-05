#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include "Task.h"

using namespace std;

class TaskManager {
private:
    vector<Task> tasks;

public:
    void createTask(Task task);
    void viewTask();
    void viewTaskList(vector<Task> taskList);

    void taskStatus(int id, string newStatus);

    void updateTask(int task_id, string task_newTitle, string task_newDesc, string task_newDueDate);

    vector<Task> getTask();

    void deleteTask(int task_id);

    void restoreTask(vector<Task> oldTask);
};

#endif