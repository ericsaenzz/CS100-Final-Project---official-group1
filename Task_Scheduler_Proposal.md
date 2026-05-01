 
# Task Scheduler - Your Second Brain

> Authors: 
> Eric Chang (https://github.com/ericsaenzz)
> Soham Mohapatra (https://github.com/sohamsanket)
> John Tate (https://github.com/jtate009)
> Adharsh Kamalakkannan (https://github.com/akama031-lab)

## Project Description
Task Scheduler is a C++ program designed to assist you in organizing your daily activities by creating task objects based on name, description, and category attributes. 

Each task can be characterized by attributes such as priority level, time, and deadlines that will assist our logic engine in organizing the plan. We use classes to organize task lists where all subtasks or child nodes are combined into one container.

The key functions will be to display, edit, delete tasks, as well as implement an effective undo mechanism utilizing the command pattern. Furthermore, we need to add functionality for sorting tasks in terms of different criteria and a unique scheduling algorithm that will suggest an optimal sequence of execution of your daily activities. 

The program's user interface, as in the case of the Maze Runner project, will consist of menu navigation using keyboard inputs and displaying of the current task list, prioritization, and task completion status.

## Language and Tools
* Language: C++
* Compiler: g++
* Version Control: Git + GitHub
* Project Management: GitHub Projects Kanban Board
* Build Tools: Makefile 

## Software Features
> The Task Scheduler will have the following funcitionalities: 
- Create, edit, and delete tasks
- Assign priorities to tasks (1–5 scale)
- Add deadlines using MM/DD/YYYY format
- Create nested subtasks under parent tasks
- Mark tasks as completed
- Automatically generate a suggested work schedule
- Sort tasks based on:
    - earliest deadline
    - highest priority
    - estimated completion time
    - View overdue tasks
    - Save and load task data from files

## Scheduling Algorithm
> Main Tasks
   - The scheduling system prioritizes tasks using a weighted approach. Tasks with the earliest deadlines are prioritized first. If deadlines are equal, tasks with higher priority values are scheduled earlier. If both are equal, shorter estimated completion times are prioritized. The algorithm dynamically updates task order whenever tasks are added, edited, or completed.

> Sub Tasks
   - Subtasks can be nested up to one level beneath a parent task. Parent tasks are not considered complete until all subtasks are completed.

## Input and Output
> User input is displayed as follows:
   - Task title (string)
   - Task description (string)
   - Deadline in MM/DD/YYYY format
   - Priority level (integer from 1–5)
   - Estimated completion time (integer in minutes)
   - Subtask information

> Example of input interface:

    Task Name: Finish Project Phase 2
    Deadline: 05/06/2026
    Priority: 5
    Estimated Time: 90 Minutes 

> User output would be as follows: 
   - A sorted task schedule
   - Task status (completed/incomplete)
   - Overdue task warnings
   - Suggested order of completion

> Example of output interface:

    Todays Agenda:
    1. Finish Project Phase 2 - Due: 05/06/2026 - Priority: 5
    2. Midterm Exam - Due: 05/10/2026 - Priority: 5

## Development Workflow
The team uses a GitHub Projects Kanban board with the following workflow:

    1. Product Backlog 
    2. Sprint Backlog
    3. In Development
    4. In Testing
    5. Completion
