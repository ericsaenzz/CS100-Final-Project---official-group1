#ifndef TASK_H
#define TASK_H
#include <string>
using namespace std;

class Task{
public: 
    //defined varibles id,title and description needed for task
    int task_id;
    string task_title;
    string task_desc;
    string task_dueDate;
    string task_status;

    // Constructor for task
    // creates the empty task
    Task() {
        task_id = 0;
        task_title = "";
        task_desc = "";
        task_dueDate = "";
        task_status = "incomplete"
    }
    // Constructor with our parameters
    // lets us create a full task with id,title and desc such as: Task(2, "phase iii checkin due", "finish this code")
    Task(int i, string t, string d, string due, string s) {
        task_id = i;
        task_title = t;
        task_desc = d;
        task_dueDate = due;
        task_status = s;
    }
};
#endif
