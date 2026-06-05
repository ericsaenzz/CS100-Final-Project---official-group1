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

void showMenu() {
    cout << "\n========== TASK SCHEDULER ==========\n";
    cout << "1. Create Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Edit Task\n";
    cout << "4. Delete Task\n";
    cout << "5. Manage Subtasks\n";
    cout << "6. Mark Task Complete\n";
    cout << "7. Sort Tasks\n";
    cout << "8. View Overdue Tasks\n";
    cout << "9. Generate Schedule\n";
    cout << "10. Save Tasks\n";
    cout << "11. Load Tasks\n";
    cout << "12. Undo Last Action\n";
    cout << "13. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    bool running = true;

    cout << "\n========== TASK SCHEDULER ==========\n";
    cout << "Welcome to Task Scheduler!\n";
    cout << "====================================\n";

    while (running) {
        showMenu();
        
        cin >> choice;
        
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
            case 1:  createTask();        break;
            case 2:  viewTasks();         break;
            case 3:  editTask();          break;
            case 4:  deleteTask();        break;
            case 5:  manageSubtasks();    break;
            case 6:  markTaskComplete();  break;
            case 7:  sortTasks();         break;
            case 8:  viewOverdueTasks();  break;
            case 9:  generateSchedule();  break;
            case 10: saveTasks();         break;
            case 11: loadTasks();         break;
            case 12: undoLastAction();    break;
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
