#include <iostream>
#include <vector>
#include <string>
#include "TaskManager.h"
#include "Scheduler.h"
#include "FileManager.h"
#include "UndoSystem.h"
#include "UserInterface.h"
using namespace std;

TaskManager taskManager;
Scheduler scheduler;
FileManager fileManager;
UndoSystem undoSystem;
int nextTaskId = 1;
int nextSubtaskId = 1;
string lastActionDescription = "";

int main() {
    int choice;
    bool running = true;

    cout << "\n========== TASK SCHEDULER ==========\n";
    cout << "Welcome to Task Scheduler!\n";
    cout << "====================================\n";

    while (running) {
        displayMainMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Sorry, please enter a valid number between 1 and 13.\n";
            continue;
        }
        cin.ignore();

        if (choice < 1 || choice > 13) {
            cout << "Sorry, please enter a number between 1 and 13.\n";
        } else if (choice == 1) {
            createTask();
        } else if (choice == 2) {
            viewTasks();
        } else if (choice == 3) {
            editTask();
        } else if (choice == 4) {
            deleteTask();
        } else if (choice == 5) {
            manageSubtasks();
        } else if (choice == 6) {
            markTaskComplete();
        } else if (choice == 7) {
            sortTasks();
        } else if (choice == 8) {
            viewOverdueTasks();
        } else if (choice == 9) {
            generateSchedule();
        } else if (choice == 10) {
            saveTasks();
        } else if (choice == 11) {
            loadTasks();
        } else if (choice == 12) {
            undoLastAction();
        } else if (choice == 13) {
            cout << "Thank you for using Task Scheduler!\n";
            running = false;
        }
    }

    return 0;
}