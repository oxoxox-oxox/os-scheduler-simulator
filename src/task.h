#pragma once
#include <string>

struct Task{
    int id;
    std::string name;
    double weight;
    double vruntime;
    double remainingTime;


    Task(int id_,
        const std::string name_,
        double weight_,
        double time_)
        : id(id_), 
        name(name_), 
        weight(weight_), 
        vruntime(0.0), 
        remainingTime(time_) {}
};


