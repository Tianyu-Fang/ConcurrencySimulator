#include "TaskScheduler.h"

TaskScheduler::TaskScheduler(int num_workers) : task_queue_() {
    for (int i = 0; i < num_workers; ++i) {
        workers_.emplace_back(std::make_shared<Worker>(task_queue_));
    }
}

void TaskScheduler::add_task(std::shared_ptr<Task> task) {
    task_queue_.push(task);
}

void TaskScheduler::stop() {
    task_queue_.stop();
    for (auto& worker : workers_) {
        worker->join();
    }
}
