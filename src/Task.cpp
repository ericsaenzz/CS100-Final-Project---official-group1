#include "Task.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

Task::Task() : id(0), priority(3), estimatedMinutes(0), completed(false) {}

Task::Task(int id, const string& title, const string& deadline,
           int priority, int estimatedMinutes, bool completed)
    : id(id), title(title), deadline(deadline), priority(priority),
      estimatedMinutes(estimatedMinutes), completed(completed) {}

int Task::getId() const {
    return id;
}

string Task::getTitle() const {
    return title;
}

string Task::getDeadline() const {
    return deadline;
}

int Task::getPriority() const {
    return priority;
}

int Task::getEstimatedMinutes() const {
    return estimatedMinutes;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::setTitle(const string& title) {
    this->title = title;
}

void Task::setDeadline(const string& deadline) {
    this->deadline = deadline;
}

void Task::setPriority(int priority) {
    this->priority = priority;
}

void Task::setEstimatedMinutes(int minutes) {
    this->estimatedMinutes = minutes;
}

void Task::markCompleted() {
    completed = true;
}

string Task::toFileString() const {
    return to_string(id) + "|" + title + "|" + deadline + "|" +
           to_string(priority) + "|" + to_string(estimatedMinutes) +
           "|" + to_string(completed);
}

Task Task::fromFileString(const string& line) {
    stringstream ss(line);
    string part;
    vector<string> fields;

    while (getline(ss, part, '|')) {
        fields.push_back(part);
    }

    if (fields.size() != 6) {
        return Task();
    }

    return Task(
        stoi(fields[0]),
        fields[1],
        fields[2],
        stoi(fields[3]),
        stoi(fields[4]),
        stoi(fields[5]) == 1
    );
}

void Task::display() const {
    cout << "ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Deadline: " << deadline << endl;
    cout << "Priority: " << priority << endl;
    cout << "Estimated Time: " << estimatedMinutes << " minutes" << endl;
    cout << "Status: " << (completed ? "Completed" : "Not completed") << endl;
}