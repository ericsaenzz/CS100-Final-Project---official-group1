// Task Manager System
#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include <string>
#include <vector>
#include <iostream>
#include "Task.h"

using namespace std;

class TaskManager{

private:
// stores all of the tasks in 1 list (dynamic array) that grows
   vector <Task> tasks;
public:
    //create the task : add task function
    void createTask(Task task);

    //read the task : display
    void viewTask();
    
    // task status
    void taskStatus(int id, string newStatus);

    //update the task : change info on task
    void updateTask(int task_id, string task_newTitle, string task_newDesc, string task_newDueDate);
    
    //undo system :copy the current task list and creates copies (data integrity)
    vector<Task> getTask();

    //update entire task with new data
    void updateTaskFull(Task updatedTask);

    //delete the task
    void deleteTask(int task_id);

    //restore the old task :
    void restoreTask(vector<Task> oldTask);
};
#endif