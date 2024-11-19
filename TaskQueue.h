#ifndef TASKQUEUE_H
#define TASKQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>
#include "Task.h"

class TaskQueue {
public:
    void push(std::shared_ptr<Task> task);
    std::shared_ptr<Task> pop();
    void stop();

private:
    std::queue<std::shared_ptr<Task>> tasks_;
    std::mutex mutex_;
    std::condition_variable cond_var_;
    bool stop_ = false;
};

#endif // TASKQUEUE_H
