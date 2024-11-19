#include "TaskQueue.h"

void TaskQueue::push(std::shared_ptr<Task> task) {
    std::unique_lock<std::mutex> lock(mutex_);
    tasks_.push(task);
    cond_var_.notify_one();
}

std::shared_ptr<Task> TaskQueue::pop() {
    std::unique_lock<std::mutex> lock(mutex_);
    cond_var_.wait(lock, [this] { return !tasks_.empty() || stop_; });

    if (stop_ && tasks_.empty()) return nullptr;
    auto task = tasks_.front();
    tasks_.pop();
    return task;
}

void TaskQueue::stop() {
    std::unique_lock<std::mutex> lock(mutex_);
    stop_ = true;
    cond_var_.notify_all();
}
