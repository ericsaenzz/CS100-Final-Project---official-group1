#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

class Task {
public:
    int task_id;
    string task_title;
    string task_desc;
    string task_dueDate;        
    string task_status;        
    int task_priority;         
    int task_estimatedTime;


    Task() {
        task_id = 0;
        task_title = "";
        task_desc = "";
        task_dueDate = "";
        task_status = "incomplete";
        task_priority = 3;
        task_estimatedTime = 0;
    }


    Task(int i, string t, string d, string due, string s, int p, int e) {
        task_id = i;
        task_title = t;
        task_desc = d;
        task_dueDate = due;
        task_status = s;
        task_priority = p;
        task_estimatedTime = e;
    }
};

#endif