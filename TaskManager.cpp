#include "TaskManager.h"
using namespace std;

// Create the task using our h file, add task to the vector
void TaskManager :: createTask(Task task){
    tasks.push_back(task);
}

// View the task
void TaskManager::viewTask() {
    if (tasks.size() == 0) {
       cout << "No Tasks Avaliable. Please try again"<<endl;
        return;
    }
    // for loop to loop through the vector and print each task
    for (int i = 0; i < tasks.size(); i++) {
        cout<< "----------------------------------\n"<<endl;
        cout << "Task ID: " << tasks[i].task_id << endl;
        cout << "Title: " << tasks[i].task_title << endl;
        cout << "Description: " << tasks[i].task_desc << endl;
        cout << "Due Date: " << tasks[i].task_dueDate << endl;
        cout << "Status: " << tasks[i].task_status << endl;  
        cout << "\n---------------------------------\n" << endl;
    }
}


// UPDATE the task function 
void TaskManager::updateTask(int task_id, string newTitle, string newDescription, string task_newDueDate) {
    for (int i = 0; i < tasks.size(); i++) {
// if statement to find the task to update
        if (tasks[i].task_id == task_id) {
            tasks[i].task_title = newTitle;
            tasks[i].task_desc = newDescription;
            tasks[i].task_dueDate = task_newDueDate;
            cout << "Task has been successfully updated." << endl;
            return;
        }
    }
    cout << "Task not found." << endl;
}


// Return task list
vector<Task> TaskManager::getTask() {
    return tasks;
    //returns copy of vector
}


// Restore old task list
void TaskManager::restoreTask(vector<Task> oldTasks) {
    tasks = oldTasks;
    //copies old vector into tasks
}


// DELETE the selected task
void TaskManager::deleteTask(int task_id) {
    for (int i = 0; i < tasks.size(); i++) {
// if statement to identify task
        if (tasks[i].task_id == task_id) {
// removes tasks from the vector
            tasks.erase(tasks.begin() + i);
            cout << "Task successfully deleted." << endl;
            return;
        }
    }
    cout << "Task not found" << endl;
}