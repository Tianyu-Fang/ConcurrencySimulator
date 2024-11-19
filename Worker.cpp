#include "Worker.h"

Worker::Worker(TaskQueue& queue) : task_queue_(queue), worker_thread_(&Worker::run, this) {}

void Worker::run() {
    while (true) {
        auto task = task_queue_.pop();
        if (!task) break;
        task->execute();
    }
}

void Worker::join() {
    if (worker_thread_.joinable()) {
        worker_thread_.join();
    }
}
