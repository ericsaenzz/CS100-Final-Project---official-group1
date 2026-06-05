#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    int id;
    std::string title;
    std::string deadline;      // YYYY-MM-DD HH:MM
    int priority;              // 1 = highest, 5 = lowest
    int estimatedMinutes;
    bool completed;

public:
    Task();
    Task(int id, const std::string& title, const std::string& deadline,
         int priority, int estimatedMinutes, bool completed = false);

    int getId() const;
    std::string getTitle() const;
    std::string getDeadline() const;
    int getPriority() const;
    int getEstimatedMinutes() const;
    bool isCompleted() const;

    void setTitle(const std::string& title);
    void setDeadline(const std::string& deadline);
    void setPriority(int priority);
    void setEstimatedMinutes(int minutes);
    void markCompleted();

    std::string toFileString() const;
    static Task fromFileString(const std::string& line);
    void display() const;
};

#endif