#pragma once

#include <chrono>

struct Package {
    int id;

    std::chrono::system_clock::time_point entry_time;

    float height;
    float width;
    float length;
};
