#ifndef TASK_H
#define TASK_H
#include <string>
#include <vector>
using namespace std;

class Subtask {
public:
    int subtask_id;
    string subtask_title;
    string subtask_desc;
    string subtask_status;

    Subtask() {
        subtask_id = 0;
        subtask_title = "";
        subtask_desc = "";
        subtask_status = "incomplete";
    }

    Subtask(int id, string title, string desc, string status) {
        subtask_id = id;
        subtask_title = title;
        subtask_desc = desc;
        subtask_status = status;
    }
};

class Task {
public:
    int task_id;
    string task_title;
    string task_desc;
    string task_dueDate;
    string task_status;
    int task_priority;
    int task_duration;
    string task_category;
    vector<Subtask> subtasks;

    Task() {
        task_id = 0;
        task_title = "";
        task_desc = "";
        task_dueDate = "";
        task_status = "incomplete";
        task_priority = 3;
        task_duration = 0;
        task_category = "";
        subtasks.clear();
    }

    Task(int i, string t, string d, string due, string s, int p, int dur, string cat) {
        task_id = i;
        task_title = t;
        task_desc = d;
        task_dueDate = due;
        task_status = s;
        task_priority = p;
        task_duration = dur;
        task_category = cat;
        subtasks.clear();
    }

    bool allSubtasksComplete() {
        if (subtasks.empty()) return true;
        for (const Subtask& st : subtasks) {
            if (st.subtask_status != "complete") return false;
        }
        return true;
    }
};
#endif
