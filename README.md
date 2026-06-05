# Task Scheduler

A comprehensive C++ command-line task management application with advanced features including CRUD operations, task sorting, intelligent scheduling, subtask management, and undo functionality.

## Features

- **Create Tasks** - Add tasks with title, description, category, deadline, priority, and estimated time
- **View Tasks** - Display all tasks in a formatted table with optional sorting
- **Edit Tasks** - Modify any task details (title, deadline, priority, duration, etc.)
- **Delete Tasks** - Remove tasks with confirmation prompt
- **Manage Subtasks** - Create hierarchical tasks with parent-child relationships
- **Mark Complete** - Track task completion status with subtask validation
- **Sort Tasks** - Sort by deadline, priority, time, or status
- **Generate Schedule** - Create optimized daily agenda using weighted algorithm
- **View Overdue Tasks** - Identify tasks past their deadline
- **Save/Load** - Persist tasks to file with automatic restoration
- **Undo System** - Revert the last action performed
- **Input Validation** - Comprehensive error messages for all invalid inputs

## Installation & Building

### Prerequisites
- C++17 compatible compiler (MSVC, GCC, or Clang)
- CMake 3.10 or higher
- Windows, Linux, or macOS

### Build Instructions

#### Option 1: Using CMake (Recommended)
```bash
cmake -S . -B build
cmake --build build --config Debug
```

#### Option 2: Using g++ (Direct Compilation)
```bash
g++ -std=c++17 -Wall -Iinclude -o task_scheduler.exe src/TaskManager.cpp src/UserInterface.cpp src/main.cpp
```

### Running the Application
```bash
# After CMake build:
.\build\Debug\task_scheduler.exe

# After direct g++ compilation:
.\task_scheduler.exe
```

## Project Structure

```
task_scheduler/
├── src/
│   ├── main.cpp              # Main event loop and program entry
│   ├── TaskManager.cpp       # CRUD operations implementation
│   └── UserInterface.cpp     # Menu navigation and input handling
├── include/
│   ├── Task.h                # Task and Subtask data structures
│   ├── TaskManager.h         # Task management interface
│   ├── Scheduler.h           # Sorting and schedule algorithms
│   ├── DateHelper.h          # Date validation utilities
│   ├── FileManager.h         # File I/O operations
│   ├── UndoSystem.h          # Undo/redo stack implementation
│   ├── Subtask.h             # Subtask data structure
│   └── UserInterface.h       # UI function declarations
├── tests/
│   ├── TaskTest.cpp          # Task and TaskManager unit tests
│   ├── SchedulerTest.cpp     # Sorting and scheduling tests
│   └── DateHelperTest.cpp    # Date validation tests
├── screenshots/              # Application screenshots
├── CMakeLists.txt            # CMake configuration
└── README.md                 # This file
```

## Unit Testing

The project includes 17 comprehensive unit tests using Google Test framework.

### Running Tests
```bash
.\build\Debug\task_scheduler_test.exe
```

### Test Results
✅ **17/17 tests passing**

**Test Coverage:**
- Task creation and data validation
- Task retrieval and listing
- Task deletion operations
- Task status updates
- Subtask management (add, edit, delete)
- Subtask completion checking
- Sorting by deadline (chronological)
- Sorting by priority (descending)
- Sorting by duration (ascending)
- Schedule generation algorithm
- Date format validation (MM/DD/YYYY)
- Date overdue detection
- Days until due calculation

## Usage Guide

### Main Menu
```
========== TASK SCHEDULER ==========
1. Create Task
2. View Tasks
3. Edit Task
4. Delete Task
5. Manage Subtasks
6. Mark Task Complete
7. Sort Tasks
8. View Overdue Tasks
9. Generate Schedule
10. Save Tasks
11. Load Tasks
12. Undo Last Action
13. Exit
====================================
```

### Creating a Task

1. Select **Option 1: Create Task**
2. Enter task **title** (required, cannot be empty)
3. Enter **description** (optional)
4. Enter **category** (required, cannot be empty)
5. Enter **deadline** in `MM/DD/YYYY` format (validated)
6. Enter **priority level** (1-5, where 5 is highest priority)
7. Enter **estimated completion time** in minutes (non-negative number)
8. Confirm creation with `y` or `n`

### Viewing & Sorting Tasks

1. Select **Option 2: View Tasks**
2. All tasks displayed in formatted table
3. Choose to sort by:
   - **1**: ID (numerical order)
   - **2**: Title (alphabetical order)
   - **3**: Deadline (chronological order)
   - **4**: Priority (highest to lowest)
   - **5**: Category (alphabetical order)
   - **6**: Status (complete to incomplete)
4. View details of specific task by entering its ID

### Editing a Task

1. Select **Option 3: Edit Task**
2. Select task ID to modify
3. Choose which field to edit:
   - Title, Description, Category, Deadline, Priority, or Duration
4. Enter new value
5. Changes saved immediately

### Scheduling Algorithm (Option 9)

Generates an optimized daily agenda using multi-level sorting:
1. **Primary:** Earliest deadline first
2. **Secondary:** Higher priority if deadlines equal
3. **Tertiary:** Shorter duration if deadline and priority equal

### Input Validation

Every input is validated with clear error messages:
- **Menu choices:** Must be 1-13
- **Task IDs:** Must be positive numbers
- **Deadlines:** Must be MM/DD/YYYY format
- **Priority:** Must be 1-5
- **Duration:** Must be non-negative number
- **Yes/No:** Accept only 'y', 'Y', 'n', or 'N'
- **Required fields:** Cannot be empty

Example error messages:
```
Sorry, please enter a number between 1 and 13.
Sorry, invalid date format. Please use MM/DD/YYYY.
Sorry, please enter a number between 1 and 5.
Sorry, this field cannot be empty.
```

## Screenshots

### 1. Main Menu
![Main Menu](screenshots/1_main_menu.png)

### 2. Create Task
![Create Task](screenshots/2_create_task.png)

### 3. View Tasks
![View Tasks](screenshots/3_view_tasks.png)

### 4. Sort Tasks
![Sort Tasks](screenshots/4_sort_tasks.png)

### 5. Task Details
![Task Details](screenshots/5_task_details.png)

### 6. Edit Task Menu
![Edit Task](screenshots/6_edit_task.png)

### 7. Delete Confirmation
![Delete Task](screenshots/7_delete_task.png)

### 8. Manage Subtasks
![Manage Subtasks](screenshots/8_manage_subtasks.png)

### 9. Mark Complete
![Mark Complete](screenshots/9_mark_complete.png)

### 10. Sort Options
![Sort Menu](screenshots/10_sort_menu.png)

### 11. View Overdue
![Overdue Tasks](screenshots/11_overdue_tasks.png)

### 12. Generate Schedule
![Generate Schedule](screenshots/12_generate_schedule.png)

## Data Persistence

Tasks are saved to `tasks.txt` in pipe-delimited format for easy parsing:
```
ID|Title|Description|Category|Deadline|Priority|Duration|Status|Subtasks...
```

**Auto-save features:**
- Save/Load via menu options
- Subtasks preserved with parent tasks
- All task properties retained

## Implementation Highlights

### Object-Oriented Design
- **Task.h:** Encapsulates task data and subtasks vector
- **TaskManager.h:** Manages task collection with CRUD operations
- **Scheduler.h:** Implements sorting and scheduling algorithms
- **DateHelper.h:** Provides date validation and calculations
- **FileManager.h:** Handles persistent storage
- **UndoSystem.h:** Stack-based action history

### Algorithms
- **Schedule Generation:** Weighted multi-level sort (deadline → priority → time)
- **Date Validation:** Regex-based MM/DD/YYYY format checking
- **Overdue Detection:** Date comparison with system date
- **Subtask Tracking:** Completion validation before parent task completion

### Input Handling
- Retry loops for invalid input
- Clear separation between numeric and string input
- Buffer management for mixed cin >> and getline() operations
- Comprehensive error messages

## Testing Procedure

### 1. Compile
```bash
cmake -S . -B build
cmake --build build --config Debug
```

### 2. Run Unit Tests
```bash
.\build\Debug\task_scheduler_test.exe
```
Expected: All 17 tests pass ✅

### 3. Run Application
```bash
.\build\Debug\task_scheduler.exe
```

### 4. Manual Testing Checklist
- [ ] Create 3+ tasks with different properties
- [ ] View tasks and verify table formatting
- [ ] Sort tasks by each criterion (5 ways)
- [ ] Generate schedule and verify order
- [ ] Edit a task field and confirm update
- [ ] Create subtasks for a task
- [ ] Mark subtask complete, then parent task
- [ ] Delete a task with confirmation
- [ ] Test invalid inputs (letters for numbers, bad dates, etc.)
- [ ] Save tasks to file
- [ ] Close and reopen application
- [ ] Load tasks and verify restoration
- [ ] Undo an action

## Code Quality

- **Memory Management:** Stack-allocated containers (vectors, strings)
- **No Memory Leaks:** Verified with appropriate cleanup
- **Error Handling:** Input validation with retry loops
- **Code Organization:** Separated UI, business logic, and data
- **Standards Compliance:** C++17 features used appropriately

## Future Enhancements

- Add task search functionality
- Implement recurring/recurring tasks
- Add task reminders and notifications
- Export to CSV or JSON formats
- Add priority color coding in terminal
- Implement task categories with filtering
- Add performance metrics dashboard
- Create time tracking functionality

## Known Limitations

- Command-line interface only (no GUI)
- Single user (no multi-user support)
- All tasks stored in single file
- No cloud synchronization
- Windows, Linux, macOS support (tested on Windows)

## Contributors

- Adharsh Kamalakkannan

## Course Information

**Course:** CS100 - Software Construction Lab  
**Project:** Task Scheduler - Final Project  
**Date:** Spring 2026

---

**Last Updated:** June 2026  
**Version:** 1.0 Final
