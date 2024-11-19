#ifndef TASK_H
#define TASK_H

#include <functional>

class Task {
public:
    Task(std::function<void()> func);
    void execute();

private:
    std::function<void()> func_;
};

#endif // TASK_H
