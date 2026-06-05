#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include "TaskManager.h"
#include "Scheduler.h"
#include "DateHelper.h"
#include "FileManager.h"
#include "UndoSystem.h"
#include "Task.h"
#include "UserInterface.h"
using namespace std;

extern TaskManager taskManager;
extern Scheduler scheduler;
extern FileManager fileManager;
extern UndoSystem undoSystem;
extern int nextTaskId;
extern int nextSubtaskId;
extern string lastActionDescription;

int getValidInteger(int min, int max, const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore();
            if (value >= min && value <= max) {
                return value;
            } else {
                cout << "Sorry, please enter a number between " << min << " and " << max << ".\n";
            }
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Sorry, please enter a valid number.\n";
        }
    }
}

char getValidYesNo(const string& prompt) {
    char response;
    while (true) {
        cout << prompt;
        cin >> response;
        cin.ignore();
        if (response == 'y' || response == 'Y' || response == 'n' || response == 'N') {
            return response;
        } else {
            cout << "Sorry, please enter 'y' or 'n'.\n";
        }
    }
}

string getValidString(const string& prompt, bool canBeEmpty) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (input.empty() && !canBeEmpty) {
            cout << "Sorry, this field cannot be empty.\n";
        } else {
            return input;
        }
    }
}

void pauseForReturn() {
    cout << "Press Enter to return.\n";
    string dummy;
    getline(cin, dummy);
}

void displayMainMenu() {
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
    cout << "====================================\n";
    cout << "Enter your choice: ";
}

void createTask() {
    cout << "\n========== CREATE TASK ==========\n";
    string title = getValidString("Task Title: ");
    string desc = getValidString("Description: ", true);
    string category = getValidString("Category: ");

    string dueDate;
    bool validDate = false;
    while (!validDate) {
        cout << "Deadline (MM/DD/YYYY): ";
        cin >> dueDate;
        cin.ignore();
        if (!DateHelper::isValidDate(dueDate)) {
            cout << "Sorry, invalid date format. Please use MM/DD/YYYY.\n";
        } else {
            validDate = true;
        }
    }

    int priority = getValidInteger(1, 5, "Priority Level (1-5): ");

    int duration;
    bool validDuration = false;
    while (!validDuration) {
        cout << "Estimated Completion Time (minutes): ";
        if (cin >> duration) {
            cin.ignore();
            if (duration >= 0) {
                validDuration = true;
            } else {
                cout << "Sorry, time cannot be negative. Please enter a positive number.\n";
            }
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Sorry, please enter a valid number.\n";
        }
    }

    char confirm = getValidYesNo("\nCreate this task? (y/n): ");
    if (confirm == 'y' || confirm == 'Y') {
        undoSystem.saveState(taskManager.getTask());
        Task newTask(nextTaskId++, title, desc, dueDate, "incomplete", priority, duration, category);
        taskManager.createTask(newTask);
        lastActionDescription = "Created task \"" + title + "\"";
        cout << "Task created successfully!\n";
        pauseForReturn();
    }
}

void viewTasks() {
    cout << "\n========== VIEW TASKS ==========\n";
    vector<Task> tasks = taskManager.getTask();

    if (tasks.empty()) {
        cout << "No tasks available.\n";
        pauseForReturn();
        return;
    }

    vector<Task> displayTasks = tasks;

    cout << left
         << setw(4) << "ID" << "|"
         << setw(21) << "Title" << "|"
         << setw(15) << "Category" << "|"
         << setw(20) << "Description" << "|"
         << setw(12) << "Deadline" << "|"
         << "Priority\n";
    cout << string(85, '-') << "\n";

    for (const Task& task : displayTasks) {
        cout << left
             << setw(4) << task.task_id << "|"
             << setw(21) << task.task_title << "|"
             << setw(15) << task.task_category << "|"
             << setw(20) << task.task_desc << "|"
             << setw(12) << task.task_dueDate << "|"
             << task.task_priority << "\n";
    }

    char sortChoice = getValidYesNo("\nWould you like to sort these tasks? (y/n): ");

    if (sortChoice == 'y' || sortChoice == 'Y') {
        cout << "\nSort by:\n";
        cout << "1. ID\n";
        cout << "2. Title\n";
        cout << "3. Deadline\n";
        cout << "4. Priority\n";
        cout << "5. Category\n";
        cout << "6. Status\n";

        int choice = getValidInteger(1, 6, "Enter choice (1-6): ");

        if (choice == 1) {
            sort(displayTasks.begin(), displayTasks.end(), [](const Task& a, const Task& b) {
                return a.task_id < b.task_id;
            });
        } else if (choice == 2) {
            sort(displayTasks.begin(), displayTasks.end(), [](const Task& a, const Task& b) {
                return a.task_title < b.task_title;
            });
        } else if (choice == 3) {
            sort(displayTasks.begin(), displayTasks.end(), [](const Task& a, const Task& b) {
                return a.task_dueDate < b.task_dueDate;
            });
        } else if (choice == 4) {
            sort(displayTasks.begin(), displayTasks.end(), [](const Task& a, const Task& b) {
                return a.task_priority > b.task_priority;
            });
        } else if (choice == 5) {
            sort(displayTasks.begin(), displayTasks.end(), [](const Task& a, const Task& b) {
                return a.task_category < b.task_category;
            });
        } else if (choice == 6) {
            sort(displayTasks.begin(), displayTasks.end(), [](const Task& a, const Task& b) {
                return a.task_status < b.task_status;
            });
        }

        cout << "\n========== SORTED TASKS ==========\n";
        cout << left
             << setw(4) << "ID" << "|"
             << setw(21) << "Title" << "|"
             << setw(15) << "Category" << "|"
             << setw(20) << "Description" << "|"
             << setw(12) << "Deadline" << "|"
             << "Priority\n";
        cout << string(85, '-') << "\n";

        for (const Task& task : displayTasks) {
            cout << left
                 << setw(4) << task.task_id << "|"
                 << setw(21) << " " + task.task_title << "|"
                 << setw(15) << task.task_category << "|"
                 << setw(20) << task.task_desc << "|"
                 << setw(12) << task.task_dueDate << "|"
                 << task.task_priority << "\n";
        }
    }

    cout << "\nEnter task ID to view details (or press Enter to return): ";
    string input;
    getline(cin, input);

    if (input.empty()) {
        return;
    }

    int id;
    try {
        id = stoi(input);
        if (id <= 0) {
            cout << "Sorry, please enter a valid task ID (must be positive).\n";
            pauseForReturn();
            return;
        }
    } catch (...) {
        cout << "Sorry, please enter a valid number for task ID.\n";
        pauseForReturn();
        return;
    }

    bool found = false;
    for (const Task& task : displayTasks) {
        if (task.task_id == id) {
            cout << "\n========== TASK DETAILS ==========\n";
            cout << "Task ID: " << task.task_id << "\n";
            cout << "Title: " << task.task_title << "\n";
            cout << "Description: " << task.task_desc << "\n";
            cout << "Category: " << task.task_category << "\n";
            cout << "Deadline: " << task.task_dueDate << "\n";
            cout << "Priority Level: " << task.task_priority << "\n";
            cout << "Estimated Time: " << task.task_duration << " minutes\n";
            cout << "Status: " << task.task_status << "\n";

            if (!task.subtasks.empty()) {
                cout << "\nSubtasks:\n";
                for (size_t i = 0; i < task.subtasks.size(); i++) {
                    cout << "  " << (i + 1) << ". " << task.subtasks[i].subtask_title
                         << " [" << task.subtasks[i].subtask_status << "]\n";
                }
            }

            cout << "\n================================\n";
            pauseForReturn();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Sorry, task ID not found.\n";
        pauseForReturn();
    }
}

void editTask() {
    cout << "\n========== EDIT TASK ==========\n";
    vector<Task> tasks = taskManager.getTask();

    if (tasks.empty()) {
        cout << "No tasks available to edit.\n";
        pauseForReturn();
        return;
    }

    cout << "Select a task to edit:\n\n";
    cout << left
         << setw(2) << "ID" << " | "
         << setw(12) << "Title" << "| "
         << setw(11) << "Category" << "| "
         << setw(15) << "Description" << "| "
         << setw(11) << "Deadline" << "| "
         << "Status\n";
    cout << string(95, '-') << "\n";

    for (const Task& task : tasks) {
        string title = task.task_title.length() > 12 ? task.task_title.substr(0, 9) + "..." : task.task_title;
        string category = task.task_category.length() > 11 ? task.task_category.substr(0, 8) + "..." : task.task_category;
        string desc = task.task_desc.length() > 15 ? task.task_desc.substr(0, 12) + "..." : task.task_desc;

        cout << left
             << setw(2) << task.task_id << " | "
             << setw(12) << title << "| "
             << setw(11) << category << "| "
             << setw(15) << desc << "| "
             << setw(11) << task.task_dueDate << "| "
             << task.task_status << "\n";
    }

    cout << "\nEnter task ID to edit (or just press Enter to return): ";
    string input;
    getline(cin, input);

    if (input.empty()) {
        return;
    }

    int id;
    try {
        id = stoi(input);
        if (id <= 0) {
            cout << "Sorry, please enter a valid task ID (must be positive).\n";
            cout << "Press Enter to return.\n";
            cin.get();
            return;
        }
    } catch (...) {
        cout << "Sorry, please enter a valid number for task ID.\n";
        cout << "Press Enter to return.\n";
        cin.get();
        return;
    }

    Task taskToEdit;
    bool found = false;

    for (const Task& task : tasks) {
        if (task.task_id == id) {
            taskToEdit = task;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Sorry, task ID " << id << " not found. Please enter a valid ID.\n";
        cout << "Press Enter to return to Main Menu.\n";
        cin.get();
        return;
    }

    bool edited = false;
    cout << "\nCurrent Task: " << taskToEdit.task_title << "\n\n";
    cout << "1. Edit Title\n";
    cout << "2. Edit Description\n";
    cout << "3. Edit Category\n";
    cout << "4. Edit Deadline\n";
    cout << "5. Edit Priority Level\n";
    cout << "6. Edit Estimated Time\n";
    cout << "7. Return to Main Menu\n";

    int choice = getValidInteger(1, 7, "Enter your choice (1-7): ");

    undoSystem.saveState(taskManager.getTask());

    if (choice == 1) {
        string newTitle = getValidString("New Title: ");
        taskToEdit.task_title = newTitle;
        lastActionDescription = "Edited task title";
        edited = true;
    }
    else if (choice == 2) {
        string newDesc = getValidString("New Description: ", true);
        taskToEdit.task_desc = newDesc;
        lastActionDescription = "Edited task description";
        edited = true;
    }
    else if (choice == 3) {
        string newCat = getValidString("New Category: ");
        taskToEdit.task_category = newCat;
        lastActionDescription = "Edited task category";
        edited = true;
    }
    else if (choice == 4) {
        bool validDate = false;
        while (!validDate) {
            cout << "New Deadline (MM/DD/YYYY): ";
            string newDate;
            cin >> newDate;
            cin.ignore();
            if (!DateHelper::isValidDate(newDate)) {
                cout << "Sorry, invalid date format. Please use MM/DD/YYYY.\n";
            } else {
                taskToEdit.task_dueDate = newDate;
                lastActionDescription = "Edited task deadline";
                edited = true;
                validDate = true;
            }
        }
    }
    else if (choice == 5) {
        int newPriority = getValidInteger(1, 5, "New Priority (1-5): ");
        taskToEdit.task_priority = newPriority;
        lastActionDescription = "Edited task priority";
        edited = true;
    }
    else if (choice == 6) {
        int newTime;
        bool validTime = false;
        while (!validTime) {
            cout << "New Estimated Time (minutes): ";
            if (cin >> newTime) {
                cin.ignore();
                if (newTime >= 0) {
                    taskToEdit.task_duration = newTime;
                    lastActionDescription = "Edited task time";
                    edited = true;
                    validTime = true;
                } else {
                    cout << "Sorry, please enter a positive number.\n";
                }
            } else {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Sorry, please enter a valid number.\n";
            }
        }
    }
    else if (choice == 7) {
        return;
    }

    if (edited) {
        taskManager.updateTaskFull(taskToEdit);
        cout << "\n========== CHANGE TRACKING DASHBOARD ==========\n";
        cout << "TASK UPDATED SUCCESSFULLY\n";
        cout << "Last Change: " << lastActionDescription << "\n";
        cout << "\nUpdated Task Details:\n";
        cout << "ID: " << taskToEdit.task_id << "\n";
        cout << "Title: " << taskToEdit.task_title << "\n";
        cout << "Description: " << taskToEdit.task_desc << "\n";
        cout << "Category: " << taskToEdit.task_category << "\n";
        cout << "Deadline: " << taskToEdit.task_dueDate << "\n";
        cout << "Priority: " << taskToEdit.task_priority << "\n";
        cout << "Duration: " << taskToEdit.task_duration << " minutes\n";
        cout << "=============================================\n";
    } else {
        cout << "No changes were made.\n";
    }

    cout << "\nPress Enter to return to Main Menu.\n";
    cin.get();
}

void deleteTask() {
    cout << "\n========== DELETE TASK ==========\n";
    vector<Task> tasks = taskManager.getTask();

    if (tasks.empty()) {
        cout << "No tasks available to delete.\n";
        pauseForReturn();
        return;
    }

    cout << "Select a task to delete:\n\n";
    cout << left
         << setw(2) << "ID" << " | "
         << setw(12) << "Title" << "| "
         << setw(11) << "Category" << "| "
         << setw(15) << "Description" << "| "
         << setw(11) << "Deadline" << "| "
         << "Status\n";
    cout << string(95, '-') << "\n";

    for (const Task& task : tasks) {
        string title = task.task_title.length() > 12 ? task.task_title.substr(0, 9) + "..." : task.task_title;
        string category = task.task_category.length() > 11 ? task.task_category.substr(0, 8) + "..." : task.task_category;
        string desc = task.task_desc.length() > 15 ? task.task_desc.substr(0, 12) + "..." : task.task_desc;

        cout << left
             << setw(2) << task.task_id << " | "
             << setw(12) << title << "| "
             << setw(11) << category << "| "
             << setw(15) << desc << "| "
             << setw(11) << task.task_dueDate << "| "
             << task.task_status << "\n";
    }

    cout << "\nEnter task ID to delete (or just press Enter to return): ";
    string input;
    getline(cin, input);

    if (input.empty()) {
        return;
    }

    int id;
    try {
        id = stoi(input);
        if (id <= 0) {
            cout << "Sorry, please enter a valid task ID (must be positive).\n";
            cout << "Press Enter to return.\n";
            cin.get();
            return;
        }
    } catch (...) {
        cout << "Sorry, please enter a valid number for task ID.\n";
        cout << "Press Enter to return.\n";
        cin.get();
        return;
    }

    Task taskToDel;
    bool found = false;

    for (const Task& task : tasks) {
        if (task.task_id == id) {
            taskToDel = task;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Sorry, task ID " << id << " not found.\n";
        cout << "Press Enter to return to Main Menu.\n";
        cin.get();
        return;
    }

    cout << "\n========== TASK TO DELETE ==========\n";
    cout << "Task ID: " << taskToDel.task_id << "\n";
    cout << "Title: " << taskToDel.task_title << "\n";
    cout << "Description: " << taskToDel.task_desc << "\n";
    cout << "Category: " << taskToDel.task_category << "\n";
    cout << "Deadline: " << taskToDel.task_dueDate << "\n";
    cout << "Priority Level: " << taskToDel.task_priority << "\n";
    cout << "Estimated Time: " << taskToDel.task_duration << " minutes\n";
    cout << "Status: " << taskToDel.task_status << "\n";
    cout << "====================================\n";

    char confirm = getValidYesNo("\nAre you sure you want to delete this task? (y/n): ");

    if (confirm == 'y' || confirm == 'Y') {
        undoSystem.saveState(taskManager.getTask());
        lastActionDescription = "Deleted task \"" + taskToDel.task_title + "\"";
        taskManager.deleteTask(id);
        cout << "Task deleted successfully.\n";
        cout << "Press Enter to return to Main Menu.\n";
        cin.get();
    } else {
        cout << "Deletion cancelled.\n";
        cout << "Press Enter to return to Main Menu.\n";
        cin.get();
    }
}

void manageSubtasks() {
    cout << "\n========== MANAGE SUBTASKS ==========\n";
    int parentId = getValidInteger(1, 999999, "Enter parent task ID: ");

    vector<Task> tasks = taskManager.getTask();
    Task* parentTask = nullptr;

    for (Task& task : tasks) {
        if (task.task_id == parentId) {
            parentTask = &task;
            break;
        }
    }

    if (!parentTask) {
        cout << "Parent task not found.\n";
        pauseForReturn();
        return;
    }

    bool managingSubtasks = true;
    while (managingSubtasks) {
        cout << "\n========== MANAGE SUBTASKS ==========\n";
        cout << "Parent Task: " << parentTask->task_title << "\n\n";

        if (!parentTask->subtasks.empty()) {
            cout << "Current Subtasks:\n";
            for (size_t i = 0; i < parentTask->subtasks.size(); i++) {
                cout << (i + 1) << ". " << parentTask->subtasks[i].subtask_title
                     << " [" << parentTask->subtasks[i].subtask_status << "]\n";
            }
            cout << "\n";
        }

        cout << "1. Add Subtask\n";
        cout << "2. Edit Subtask\n";
        cout << "3. Delete Subtask\n";
        cout << "4. Mark Subtask Complete\n";
        cout << "5. Return to Main Menu\n";

        int choice = getValidInteger(1, 5, "Enter your choice: ");

        switch (choice) {
            case 1: {
                cout << "Subtask Title: ";
                string subTitle;
                getline(cin, subTitle);
                cout << "Subtask Description: ";
                string subDesc;
                getline(cin, subDesc);

                undoSystem.saveState(taskManager.getTask());
                Subtask newSubtask(nextSubtaskId++, subTitle, subDesc, "incomplete");
                parentTask->subtasks.push_back(newSubtask);
                lastActionDescription = "Added subtask \"" + subTitle + "\"";
                cout << "Subtask added successfully!\n";
                break;
            }
            case 2: {
                if (parentTask->subtasks.empty()) {
                    cout << "No subtasks to edit.\n";
                    break;
                }
                cout << "Select subtask number to edit: ";
                int subNum;
                cin >> subNum;
                cin.ignore();

                if (subNum < 1 || subNum > (int)parentTask->subtasks.size()) {
                    cout << "Invalid subtask number.\n";
                    break;
                }

                Subtask& subToEdit = parentTask->subtasks[subNum - 1];
                cout << "New Title: ";
                getline(cin, subToEdit.subtask_title);
                cout << "New Description: ";
                getline(cin, subToEdit.subtask_desc);

                undoSystem.saveState(taskManager.getTask());
                lastActionDescription = "Edited subtask";
                cout << "Subtask updated!\n";
                break;
            }
            case 3: {
                if (parentTask->subtasks.empty()) {
                    cout << "No subtasks to delete.\n";
                    break;
                }
                cout << "Select subtask number to delete: ";
                int subNum;
                cin >> subNum;

                if (subNum < 1 || subNum > (int)parentTask->subtasks.size()) {
                    cout << "Invalid subtask number.\n";
                    break;
                }

                undoSystem.saveState(taskManager.getTask());
                lastActionDescription = "Deleted subtask \"" + parentTask->subtasks[subNum - 1].subtask_title + "\"";
                parentTask->subtasks.erase(parentTask->subtasks.begin() + subNum - 1);
                cout << "Subtask deleted!\n";
                break;
            }
            case 4: {
                if (parentTask->subtasks.empty()) {
                    cout << "No subtasks to mark complete.\n";
                    break;
                }
                cout << "Select subtask number to mark complete: ";
                int subNum;
                cin >> subNum;

                if (subNum < 1 || subNum > (int)parentTask->subtasks.size()) {
                    cout << "Invalid subtask number.\n";
                    break;
                }

                undoSystem.saveState(taskManager.getTask());
                parentTask->subtasks[subNum - 1].subtask_status = "complete";
                lastActionDescription = "Marked subtask complete";
                cout << "Subtask marked complete!\n";
                break;
            }
            case 5:
                managingSubtasks = false;
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }
}

void markTaskComplete() {
    cout << "\n========== MARK TASK COMPLETE ==========\n";
    vector<Task> tasks = taskManager.getTask();

    if (tasks.empty()) {
        cout << "No tasks available.\n";
        cout << "Press Enter to return.\n";
        cin.get();
        return;
    }

    cout << "Select a task to mark complete:\n\n";
    cout << left
         << setw(2) << "ID" << " | "
         << setw(12) << "Title" << "| "
         << setw(11) << "Category" << "| "
         << setw(11) << "Deadline" << "| "
         << setw(8) << "Priority" << "| "
         << "Status\n";
    cout << string(80, '-') << "\n";

    for (const Task& task : tasks) {
        if (task.task_status != "complete") {
            string title = task.task_title.length() > 12 ? task.task_title.substr(0, 9) + "..." : task.task_title;
            string category = task.task_category.length() > 11 ? task.task_category.substr(0, 8) + "..." : task.task_category;
            cout << left
                 << setw(2) << task.task_id << " | "
                 << setw(12) << title << "| "
                 << setw(11) << category << "| "
                 << setw(11) << task.task_dueDate << "| "
                 << setw(8) << task.task_priority << "| "
                 << task.task_status << "\n";
        }
    }

    cout << "\nEnter task ID to mark complete (or just press Enter to return): ";
    string input;
    getline(cin, input);

    if (input.empty()) {
        return;
    }

    int id;
    try {
        id = stoi(input);
        if (id <= 0) {
            cout << "Sorry, please enter a valid task ID (must be positive).\n";
            cout << "Press Enter to return.\n";
            cin.get();
            return;
        }
    } catch (...) {
        cout << "Sorry, please enter a valid number for task ID.\n";
        cout << "Press Enter to return.\n";
        cin.get();
        return;
    }

    Task foundTask;
    bool found = false;

    for (const Task& task : tasks) {
        if (task.task_id == id) {
            foundTask = task;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Sorry, task ID " << id << " not found.\n";
        cout << "Press Enter to return.\n";
        cin.get();
        return;
    }

    if (!foundTask.subtasks.empty()) {
        bool allComplete = foundTask.allSubtasksComplete();
        cout << "\nAll subtasks completed? " << (allComplete ? "Yes" : "No") << "\n";

        if (!allComplete) {
            cout << "\nThis task cannot be marked complete until all subtasks are finished.\n";
            cout << "Press Enter to return.\n";
            cin.get();
            return;
        }
    }

    cout << "\n========== CONFIRM COMPLETION ==========\n";
    cout << "Task ID: " << foundTask.task_id << "\n";
    cout << "Title: " << foundTask.task_title << "\n";
    cout << "Category: " << foundTask.task_category << "\n";
    cout << "Deadline: " << foundTask.task_dueDate << "\n";
    cout << "Priority: " << foundTask.task_priority << "\n";
    cout << "Estimated Time: " << foundTask.task_duration << " minutes\n";
    char confirm = getValidYesNo("\nMark this task as complete? (y/n): ");

    if (confirm == 'y' || confirm == 'Y') {
        undoSystem.saveState(taskManager.getTask());
        taskManager.taskStatus(id, "complete");
        lastActionDescription = "Marked task \"" + foundTask.task_title + "\" complete";
        cout << "Task marked as complete successfully!\n";
        cout << "Press Enter to return.\n";
        cin.get();
    } else {
        cout << "Cancelled.\n";
        cout << "Press Enter to return.\n";
        cin.get();
    }
}

void sortTasks() {
    cout << "\n========== SORT TASKS ==========\n";
    cout << "1. Sort by Earliest Deadline\n";
    cout << "2. Sort by Highest Priority\n";
    cout << "3. Sort by Estimated Completion Time\n";
    cout << "4. Sort by Completion Status\n";
    cout << "5. Return to Main Menu\n";

    int choice = getValidInteger(1, 5, "Enter your choice: ");

    vector<Task> tasks = taskManager.getTask();
    vector<Task> sorted;

    switch (choice) {
        case 1:
            sorted = scheduler.sortByDeadline(tasks);
            cout << "\nTasks sorted by earliest deadline.\n\n";
            break;
        case 2:
            sorted = scheduler.sortByPriority(tasks);
            cout << "\nTasks sorted by highest priority.\n\n";
            break;
        case 3:
            sorted = scheduler.sortByTime(tasks);
            cout << "\nTasks sorted by shortest time.\n\n";
            break;
        case 4:
            sorted = scheduler.sortByStatus(tasks);
            cout << "\nTasks sorted by status.\n\n";
            break;
        default:
            return;
    }

    cout << left << setw(5) << "ID" << setw(25) << "Title" << setw(12) << "Deadline"
         << setw(10) << "Priority" << setw(8) << "Time" << setw(12) << "Status" << endl;
    cout << string(72, '-') << endl;

    for (const Task& task : sorted) {
        string taskTitle = task.task_title;
        if (taskTitle.length() > 24) taskTitle = taskTitle.substr(0, 21) + "...";

        cout << left << setw(5) << task.task_id
             << setw(25) << taskTitle
             << setw(12) << task.task_dueDate
             << setw(10) << task.task_priority
             << setw(8) << (to_string(task.task_duration) + "m")
             << setw(12) << task.task_status << endl;
    }

    cout << "\nPress Enter to return to Main Menu.\n";
    cin.ignore();
    cin.get();
}

void viewOverdueTasks() {
    cout << "\n========== OVERDUE TASKS ==========\n";
    cout << "Current Date: " << DateHelper::getCurrentDate() << "\n\n";

    vector<Task> tasks = taskManager.getTask();
    vector<Task> overdue = scheduler.getOverdueTasks(tasks);

    if (overdue.empty()) {
        cout << "No overdue tasks!\n";
        cout << "Press Enter to return to Main Menu.\n";
        cin.ignore();
        cin.get();
        return;
    }

    cout << left << setw(5) << "ID" << setw(25) << "Title" << setw(12) << "Deadline"
         << setw(10) << "Priority" << setw(12) << "Status" << endl;
    cout << string(64, '-') << endl;

    for (const Task& task : overdue) {
        string taskTitle = task.task_title;
        if (taskTitle.length() > 24) taskTitle = taskTitle.substr(0, 21) + "...";

        cout << left << setw(5) << task.task_id
             << setw(25) << taskTitle
             << setw(12) << task.task_dueDate
             << setw(10) << task.task_priority
             << setw(12) << task.task_status << endl;
    }

    cout << "\nPress Enter to return to Main Menu.\n";
    cin.ignore();
    cin.get();
}

void generateSchedule() {
    cout << "\n========== GENERATED SCHEDULE ==========\n";
    cout << "Scheduling Method:\n";
    cout << "1. Earliest deadline first\n";
    cout << "2. Higher priority first if deadlines are equal\n";
    cout << "3. Shorter estimated time first if deadline and priority are equal\n\n";

    vector<Task> tasks = taskManager.getTask();

    if (tasks.empty()) {
        cout << "No tasks available. Create some tasks first!\n";
        cout << "\nPress Enter to return to Main Menu.\n";
        cin.ignore();
        cin.get();
        return;
    }

    vector<Task> scheduled = scheduler.generateSchedule(tasks);

    cout << "Today's Agenda:\n";
    int count = 1;
    int incompleteCount = 0;

    for (const Task& task : scheduled) {
        if (task.task_status != "complete") {
            incompleteCount++;
            cout << count++ << ". " << task.task_title << " - Due: " << task.task_dueDate
                 << " - Priority: " << task.task_priority << " - Time: " << task.task_duration << "m\n";
        }
    }

    if (incompleteCount == 0) {
        cout << "All tasks are complete! Great job!\n";
    }

    cout << "\nPress Enter to return to Main Menu.\n";
    cin.ignore();
    cin.get();
}

void saveTasks() {
    cout << "\n========== SAVE TASKS ==========\n";
    cout << "Saving task data to file...\n\n";
    fileManager.saveTasks(taskManager.getTask());
    cout << "File name: tasks.txt\n";
    cout << "\nTasks saved successfully.\n";
    cout << "Press Enter to return to Main Menu.\n";
    cin.ignore();
    cin.get();
}

void loadTasks() {
    cout << "\n========== LOAD TASKS ==========\n";
    cout << "Loading task data from file...\n\n";
    vector<Task> loadedTasks = fileManager.loadTasks();
    undoSystem.saveState(taskManager.getTask());

    for (const Task& task : loadedTasks) {
        taskManager.createTask(task);
        if (task.task_id >= nextTaskId) {
            nextTaskId = task.task_id + 1;
        }
    }
    cout << "File name: tasks.txt\n";
    cout << "\nTasks loaded successfully.\n";
    cout << "Press Enter to return to Main Menu.\n";
    cin.ignore();
    cin.get();
}

void undoLastAction() {
    cout << "\n========== UNDO LAST ACTION ==========\n";
    if (!undoSystem.canUndo()) {
        cout << "No actions to undo.\n";
        return;
    }

    if (!lastActionDescription.empty()) {
        cout << "Last Action: " << lastActionDescription << "\n\n";
    }

    cout << "Undo this action? (y/n): ";
    char confirm;
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        vector<Task> previousState = undoSystem.undo();
        taskManager.restoreTask(previousState);
        cout << "Action undone successfully.\n";
        lastActionDescription = "";
    }
}
