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

    for (size_t i = 0; i < tasks.size(); i++) {
        cout << "----------------------------------" << endl;
        cout << "Task ID: " << tasks[i].task_id << endl;
        cout << "Title: " << tasks[i].task_title << endl;
        cout << "Description: " << tasks[i].task_desc << endl;
        cout << "Due Date: " << tasks[i].task_dueDate << endl;
        cout << "Status: " << tasks[i].task_status << endl;
        cout << "Priority: " << tasks[i].task_priority << endl;
        cout << "Duration: " << tasks[i].task_duration << " minutes" << endl;
        cout << "Category: " << tasks[i].task_category << endl;
        cout << "Subtasks: " << tasks[i].subtasks.size() << endl;

        if (tasks[i].subtasks.size() > 0) {
            cout << "Subtask List:" << endl;

            for (size_t j = 0; j < tasks[i].subtasks.size(); j++) {
                cout << "  Subtask ID: " << tasks[i].subtasks[j].subtask_id << endl;
                cout << "  Title: " << tasks[i].subtasks[j].subtask_title << endl;
                cout << "  Description: " << tasks[i].subtasks[j].subtask_desc << endl;
                cout << "  Status: " << tasks[i].subtasks[j].subtask_status << endl;
                cout << "  ----------------" << endl;
            }
        }

        cout << "----------------------------------" << endl;
    }
}

void TaskManager::taskStatus(int id, string newStatus) {
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].task_id == id) {
            tasks[i].task_status = newStatus;
            cout << "Task status updated" << endl;
            return;
        }
    }

    cout << "Task not found." << endl;
}

void TaskManager::updateTask(int task_id, string newTitle, string newDescription, string task_newDueDate) {
    for (size_t i = 0; i < tasks.size(); i++) {
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

void TaskManager::updateTaskFull(Task updatedTask) {
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].task_id == updatedTask.task_id) {
            tasks[i] = updatedTask;
            cout << "Task has been fully updated." << endl;
            return;
        }
    }

    cout << "Task not found." << endl;
}

void TaskManager::restoreTask(vector<Task> oldTasks) {
    tasks = oldTasks;
}

void TaskManager::deleteTask(int task_id) {
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].task_id == task_id) {
            tasks.erase(tasks.begin() + i);
            cout << "Task successfully deleted." << endl;
            return;
        }
    }

    cout << "Task not found" << endl;
}