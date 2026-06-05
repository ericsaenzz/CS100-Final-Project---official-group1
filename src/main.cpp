#include "TaskManager.h"
#include "FileManager.h"
#include "Scheduler.h"
#include "NotificationSystem.h"
#include "SortingFiltering.h"

#include <iostream>
#include <limits>
#include <vector>
#include <string>

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void displayTaskList(vector<Task> tasks) {
    if (tasks.size() == 0) {
        cout << "No tasks to display." << endl;
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

int main() {
    TaskManager taskManager;
    FileManager fileManager("tasks.txt");
    Scheduler scheduler;
    NotificationSystem notifications;
    SortingFiltering sorter;

    // Load saved tasks into Eric's TaskManager
    taskManager.restoreTask(fileManager.loadTasks());

    int choice = 0;

    do {
        cout << endl;
        cout << "===== Task Manager =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View All Tasks" << endl;
        cout << "3. Show Today's Agenda" << endl;
        cout << "4. Show Overdue Tasks" << endl;
        cout << "5. Update Task Status" << endl;
        cout << "6. Save Tasks" << endl;
        cout << "7. Load Tasks" << endl;
        cout << "8. Sort/Filter Tasks" << endl;
        cout << "9. Delete Task" << endl;
        cout << "10. Exit" << endl;
        cout << "Choose an option: ";

        cin >> choice;

        if (cin.fail()) {
            clearInput();
            cout << "Invalid input." << endl;
            continue;
        }

        clearInput();

        if (choice == 1) {
            int id;
            string title;
            string desc;
            string dueDate;
            string status;
            int priority;
            int estimatedTime;

            cout << "Enter task ID: ";
            cin >> id;
            clearInput();

            cout << "Enter task title: ";
            getline(cin, title);

            cout << "Enter task description: ";
            getline(cin, desc);

            cout << "Enter due date (YYYY-MM-DD HH:MM): ";
            getline(cin, dueDate);

            cout << "Enter status (incomplete, in progress, complete): ";
            getline(cin, status);

            cout << "Enter priority (1 = highest, 5 = lowest): ";
            cin >> priority;

            cout << "Enter estimated time in minutes: ";
            cin >> estimatedTime;

            clearInput();

            Task newTask(id, title, desc, dueDate, status, priority, estimatedTime);
            taskManager.createTask(newTask);

            cout << "Task added successfully." << endl;
        }
        else if (choice == 2) {
            taskManager.viewTask();
        }
        else if (choice == 3) {
            vector<Task> agenda = scheduler.generateTodayAgenda(taskManager.getTask());

            cout << endl;
            cout << "===== Today's Agenda =====" << endl;
            displayTaskList(agenda);
        }
        else if (choice == 4) {
            notifications.showOverdueTasks(taskManager.getTask());
        }
        else if (choice == 5) {
            int id;
            string newStatus;

            cout << "Enter task ID: ";
            cin >> id;
            clearInput();

            cout << "Enter new status (incomplete, in progress, complete): ";
            getline(cin, newStatus);

            taskManager.taskStatus(id, newStatus);
        }
        else if (choice == 6) {
            fileManager.saveTasks(taskManager.getTask());
        }
        else if (choice == 7) {
            vector<Task> loadedTasks = fileManager.loadTasks();
            taskManager.restoreTask(loadedTasks);
        }
        else if (choice == 8) {
            int sortChoice;
            vector<Task> result;

            cout << endl;
            cout << "===== Sort/Filter Tasks =====" << endl;
            cout << "1. Sort by Deadline" << endl;
            cout << "2. Sort by Priority" << endl;
            cout << "3. Sort by Estimated Time" << endl;
            cout << "4. Sort by Status" << endl;
            cout << "5. Show Completed Tasks Only" << endl;
            cout << "6. Show Incomplete Tasks Only" << endl;
            cout << "7. Show In Progress Tasks Only" << endl;
            cout << "Choose an option: ";

            cin >> sortChoice;

            if (cin.fail()) {
                clearInput();
                cout << "Invalid input." << endl;
                continue;
            }

            clearInput();

            if (sortChoice == 1) {
                result = sorter.sortByDeadline(taskManager.getTask());
            }
            else if (sortChoice == 2) {
                result = sorter.sortByPriority(taskManager.getTask());
            }
            else if (sortChoice == 3) {
                result = sorter.sortByEstimatedTime(taskManager.getTask());
            }
            else if (sortChoice == 4) {
                result = sorter.sortByStatus(taskManager.getTask());
            }
            else if (sortChoice == 5) {
                result = sorter.filterCompleted(taskManager.getTask());
            }
            else if (sortChoice == 6) {
                result = sorter.filterIncomplete(taskManager.getTask());
            }
            else if (sortChoice == 7) {
                result = sorter.filterInProgress(taskManager.getTask());
            }
            else {
                cout << "Invalid option." << endl;
                continue;
            }

            cout << endl;
            cout << "===== Results =====" << endl;
            displayTaskList(result);
        }
        else if (choice == 9) {
            int id;

            cout << "Enter task ID to delete: ";
            cin >> id;
            clearInput();

            taskManager.deleteTask(id);
        }
        else if (choice == 10) {
            fileManager.saveTasks(taskManager.getTask());
            cout << "Goodbye." << endl;
        }
        else {
            cout << "Invalid option." << endl;
        }

    } while (choice != 10);

    return 0;
}