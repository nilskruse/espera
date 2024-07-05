#pragma once

#include "Package.hpp"

#include <condition_variable>
#include <mutex>
#include <queue>

class PackageQueue {
public:
    explicit PackageQueue(int packageDelaySeconds);
    virtual ~PackageQueue() = default;

    void push(const Package&& package);
    Package pop();

private:
    std::queue<Package> m_packageQueue;
    std::mutex m_queueMutex;
    std::condition_variable m_conditionVariable; 

    int m_packageDelaySeconds;

};
