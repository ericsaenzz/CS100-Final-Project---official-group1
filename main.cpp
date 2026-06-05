#include <iostream>
#include "TaskManager.h"
#include "UndoSystem.h"
using namespace std;

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
int main(){
    int number = 0;
    int choice = 0;
    while (number != 13) {
        showMenu();
        
        cin >> number;
        
        if (number < 1) return 1;

        if (number > 13) return 1;

        if (choice == 1) {
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
        } else {
            cout << "Thank you for using Task Scheduler!\n";
        }
    }
    
    return 0;
} 
