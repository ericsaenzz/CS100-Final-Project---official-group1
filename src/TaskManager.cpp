#include "TaskManager.h"
using namespace std;

void TaskManager::createTask(Task task) {
    tasks.push_back(task);
}

void TaskManager::viewTask() {
    if (tasks.size() == 0) {
        cout << "No Tasks Available. Please try again" << endl;
        return;
    }

    for (int i = 0; i < tasks.size(); i++) {
        cout << "----------------------------------" << endl;
        cout << "Task ID: " << tasks[i].task_id << endl;
        cout << "Title: " << tasks[i].task_title << endl;
        cout << "Description: " << tasks[i].task_desc << endl;
        cout << "Due Date: " << tasks[i].task_dueDate << endl;
        cout << "Status: " << tasks[i].task_status << endl;
        cout << "Priority: " << tasks[i].task_priority << endl;
        cout << "Estimated Time: " << tasks[i].task_estimatedTime << " minutes" << endl;
        cout << "----------------------------------" << endl;
    }
}

void TaskManager::viewTaskList(vector<Task> taskList) {
    if (taskList.size() == 0) {
        cout << "No tasks to display." << endl;
        return;
    }

    for (int i = 0; i < taskList.size(); i++) {
        cout << "----------------------------------" << endl;
        cout << "Task ID: " << taskList[i].task_id << endl;
        cout << "Title: " << taskList[i].task_title << endl;
        cout << "Description: " << taskList[i].task_desc << endl;
        cout << "Due Date: " << taskList[i].task_dueDate << endl;
        cout << "Status: " << taskList[i].task_status << endl;
        cout << "Priority: " << taskList[i].task_priority << endl;
        cout << "Estimated Time: " << taskList[i].task_estimatedTime << " minutes" << endl;
        cout << "----------------------------------" << endl;
    }
}

void TaskManager::taskStatus(int id, string newStatus) {
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].task_id == id) {
            tasks[i].task_status = newStatus;
            cout << "Task status updated" << endl;
            return;
        }
    }

    cout << "Task not found." << endl;
}

void TaskManager::updateTask(int task_id, string newTitle, string newDescription, string task_newDueDate) {
    for (int i = 0; i < tasks.size(); i++) {
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


vector<Task> TaskManager::getTask() {
    return tasks;
}


void TaskManager::restoreTask(vector<Task> oldTasks) {
    tasks = oldTasks;
}


void TaskManager::deleteTask(int task_id) {
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].task_id == task_id) {
            tasks.erase(tasks.begin() + i);
            cout << "Task successfully deleted." << endl;
            return;
        }
    }

    cout << "Task not found" << endl;
}