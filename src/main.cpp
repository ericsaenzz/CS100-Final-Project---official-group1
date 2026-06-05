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
            continue;
        }

        switch (choice) {
            case 1:
                createTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                editTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                manageSubtasks();
                break;
            case 6:
                markTaskComplete();
                break;
            case 7:
                sortTasks();
                break;
            case 8:
                viewOverdueTasks();
                break;
            case 9:
                generateSchedule();
                break;
            case 10:
                saveTasks();
                break;
            case 11:
                loadTasks();
                break;
            case 12:
                undoLastAction();
                break;
            case 13:
                cout << "Thank you for using Task Scheduler!\n";
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
