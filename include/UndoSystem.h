#ifndef UNDOSYSTEM_H
#define UNDOSYSTEM_H
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "Task.h"
#include "TaskManager.h"

using namespace std;
//undo system that will store old versions of the tasks in the case user needs to restore them (Deep Copies)
class UndoSystem {
private:
//stack that stores the tasks list
    stack<vector<Task>> history;
public:
    // Save current state
    void saveState(vector<Task> tasks) {
        history.push(tasks); //copies current task list, push adds
    }
    // Undo previous state 
    vector<Task> undo() {
        if (!history.empty()) {
            vector<Task> previousState =history.top(); // gets the newsest saved tasks
            history.pop(); //pop removes from stack
            return previousState; //gives back to TaskManager 
        }
        return {}; //returns empty list if empty
    }
    // canUndo Checks to see if there is anything avaliable to undo
    bool canUndo() {
        return !history.empty();
    }
};
#endif