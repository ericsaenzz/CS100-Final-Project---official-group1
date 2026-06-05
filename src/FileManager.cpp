#include "FileManager.h"
#include <fstream>
#include <iostream>

using namespace std;

FileManager::FileManager(const string& filename) : filename(filename) {}

void FileManager::saveTasks(const vector<Task>& tasks) const {
    ofstream outFile(filename);

    if (!outFile) {
        cout << "Error: Could not open " << filename << " for saving." << endl;
        return;
    }

    for (const Task& task : tasks) {
        outFile << task.toFileString() << endl;
    }

    outFile.close();

    cout << "Tasks saved to " << filename << "." << endl;
}

vector<Task> FileManager::loadTasks() const {
    vector<Task> tasks;
    ifstream inFile(filename);

    if (!inFile) {
        cout << "No existing " << filename << " found. Starting fresh." << endl;
        return tasks;
    }

    string line;

    while (getline(inFile, line)) {
        if (!line.empty()) {
            tasks.push_back(Task::fromFileString(line));
        }
    }

    inFile.close();

    cout << "Tasks loaded from " << filename << "." << endl;

    return tasks;
}