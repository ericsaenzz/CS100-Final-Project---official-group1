#include "TaskManager.h"
#include "FileManager.h"
#include "Scheduler.h"
#include "NotificationSystem.h"
#include "SortingFiltering.h"

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    TaskManager taskManager;
    FileManager fileManager("tasks.txt");
    Scheduler scheduler;
    NotificationSystem notifications;
    SortingFiltering sortingFiltering;

    taskManager.setTasks(fileManager.loadTasks());

    int choice = 0;

    do {
        cout << endl;
        cout << "===== Task Manager =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View All Tasks" << endl;
        cout << "3. Show Today's Agenda" << endl;
        cout << "4. Show Overdue Tasks" << endl;
        cout << "5. Mark Task Completed" << endl;
        cout << "6. Save Tasks" << endl;
        cout << "7. Load Tasks" << endl;
        cout << "8. Sort/Filter Tasks" << endl;
        cout << "9. Exit" << endl;
        cout << "Choose an option: ";

        cin >> choice;

        if (cin.fail()) {
            clearInput();
            cout << "Invalid input." << endl;
            continue;
        }

        clearInput();

        if (choice == 1) {
            string title;
            string deadline;
            int priority;
            int estimatedMinutes;

            cout << "Enter task title: ";
            getline(cin, title);

            cout << "Enter deadline (YYYY-MM-DD HH:MM): ";
            getline(cin, deadline);

            cout << "Enter priority (1 = highest, 5 = lowest): ";
            cin >> priority;

            cout << "Enter estimated time in minutes: ";
            cin >> estimatedMinutes;

            clearInput();

            taskManager.addTask(title, deadline, priority, estimatedMinutes);
        }
        else if (choice == 2) {
            taskManager.viewTasks();
        }
        else if (choice == 3) {
            vector<Task> agenda = scheduler.generateTodayAgenda(taskManager.getTasks());

            cout << endl;
            cout << "===== Today's Agenda =====" << endl;

            if (agenda.empty()) {
                cout << "No unfinished tasks." << endl;
            }

            for (const Task& task : agenda) {
                task.display();
                cout << "--------------------------" << endl;
            }
        }
        else if (choice == 4) {
            notifications.showOverdueTasks(taskManager.getTasks());
        }
        else if (choice == 5) {
            int id;

            cout << "Enter task ID to complete: ";
            cin >> id;

            clearInput();

            taskManager.markTaskCompleted(id);
        }
        else if (choice == 6) {
            fileManager.saveTasks(taskManager.getTasks());
        }
        else if (choice == 7) {
            taskManager.setTasks(fileManager.loadTasks());
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
            cout << "Choose an option: ";

            cin >> sortChoice;

            if (cin.fail()) {
                clearInput();
                cout << "Invalid input." << endl;
                continue;
            }

            clearInput();

            if (sortChoice == 1) {
                result = sortingFiltering.sortByDeadline(taskManager.getTasks());
            }
            else if (sortChoice == 2) {
                result = sortingFiltering.sortByPriority(taskManager.getTasks());
            }
            else if (sortChoice == 3) {
                result = sortingFiltering.sortByEstimatedTime(taskManager.getTasks());
            }
            else if (sortChoice == 4) {
                result = sortingFiltering.sortByStatus(taskManager.getTasks());
            }
            else if (sortChoice == 5) {
                result = sortingFiltering.filterCompleted(taskManager.getTasks());
            }
            else if (sortChoice == 6) {
                result = sortingFiltering.filterIncomplete(taskManager.getTasks());
            }
            else {
                cout << "Invalid option." << endl;
                continue;
            }

            cout << endl;
            cout << "===== Results =====" << endl;

            if (result.empty()) {
                cout << "No matching tasks." << endl;
            }

            for (const Task& task : result) {
                task.display();
                cout << "---------------------" << endl;
            }
        }
        else if (choice == 9) {
            fileManager.saveTasks(taskManager.getTasks());
            cout << "Goodbye." << endl;
        }
        else {
            cout << "Invalid option." << endl;
        }

    } while (choice != 9);

    return 0;
}