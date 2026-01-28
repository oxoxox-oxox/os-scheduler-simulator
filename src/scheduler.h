#pragma once
#include "task.h"
#include <memory>
#include <vector>

class Scheduler{
public:
    virtual ~Scheduler() = default;

    //add task to the scheduler
    virtual void addTask(std::shared_ptr<Task> task) = 0;

    //schedual next task(return the pointer)
    virtual std::shared_ptr<Task> nextTask() = 0;

    /*update the vruntime(anounce the scheduler the task 
    has been done for a period of time: real_time)*/
    virtual void updateCurrentTask(double real_time) = 0;

    //check if there is any task to do
    virtual bool hasTasks() const = 0;
};