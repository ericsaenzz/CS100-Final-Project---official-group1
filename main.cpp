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
    while (number != 13) {
        showMenu();
        
        cin >> number;
        
        if (number < 1) return 1;

        if (number > 13) return 1;
    }
    
    return 0;
} 
