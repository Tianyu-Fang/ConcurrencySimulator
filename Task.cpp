#include "Task.h"

// Constructor that initializes the task with a given function
Task::Task(std::function<void()> func) : func_(func) {}

// Executes the stored function
void Task::execute() {
    func_();
}
