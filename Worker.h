#ifndef WORKER_H
#define WORKER_H

#include <thread>
#include "TaskQueue.h"

class Worker {
public:
    Worker(TaskQueue& queue);
    void run();
    void join();

private:
    TaskQueue& task_queue_;
    std::thread worker_thread_;
};

#endif // WORKER_H
