Adharsh Kamalakkannan: Logic & Algorithms

Task Hierarchy: Implement the core Task class and a recursive logic system where a parent task's completion status is automatically tied to its subtasks.

Scheduling Engine: Code the algorithm for "Generate Schedule" that sorts tasks by three layers: Deadline → Priority → Estimated Time.

Sorting Logic: Create custom comparator functions to power the "Sort Tasks" menu (sorting by highest priority, earliest deadline, etc.).

Date Handling: Develop a helper function to convert MM/DD/YYYY strings into sortable integers or objects so the scheduler can accurately compare dates.




John Tate: UI & Navigation

Menu Controller: Build the main execution loop and the logic for navigating between all 13 unique screens.

Visual Formatting: Use the <iomanip> library to create the table layouts for the "View Tasks" and "Overdue Tasks" screens, ensuring columns stay aligned regardless of text length.

Input Validation: Write "bulletproof" code to handle user input—preventing the program from crashing if a user enters a letter instead of a number or an invalid date.

Screen Flow: Manage the "Back" functionality (e.g., ensuring "Press Enter to return" actually takes the user back to the correct previous menu).




Eric Chang: Commands & Undo System

Command Pattern Architecture: Implement the Command interface with execute() and undo() methods to support the requirement for reversing actions.

Action Tracking: Create specific classes for AddTaskCommand, DeleteTaskCommand, and EditTaskCommand that store snapshots of data for the undo stack.

Task Management (CRUD): Write the logic for creating, editing, and deleting task objects within the Scheduler container.

Undo Stack: Maintain a std::stack of recent commands that allows the user to pop the last action and revert the task list to its previous state.




Soham Mohapatra: Data & Systems

File Persistence: Develop the Save and Load logic using std::fstream to write task data to tasks.txt and parse it back into objects when the program starts.

Notification System: Build the Notification class that compares the current system date against task deadlines to trigger "Overdue" alerts.

Build Environment: Create and maintain the Makefile to ensure all files compile correctly and manage the project folder structure.

System Integration: Implement the logic for the "View Overdue Tasks" screen by filtering the master task list against the real-time system clock.
