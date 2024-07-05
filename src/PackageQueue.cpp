#include "PackageQueue.hpp"

#include <chrono>
#include <mutex>

#include "Package.hpp"

PackageQueue::PackageQueue(int packageDelaySeconds) : m_packageDelaySeconds(packageDelaySeconds)
{
}

void PackageQueue::push(const Package &&package)
{
    std::unique_lock<std::mutex> queueLock{m_queueMutex};
    m_packageQueue.push(std::move(package));
    m_conditionVariable.notify_one();
}

Package PackageQueue::pop()
{
    std::unique_lock<std::mutex> queueLock{m_queueMutex};

    m_conditionVariable.wait(queueLock, [this] {
        if (m_packageQueue.empty())
        {
            return false;
        }

        const auto entryTime = m_packageQueue.front().entry_time;
        const auto now = std::chrono::system_clock::now();
        const auto packageAgeSeconds = std::chrono::duration_cast<std::chrono::seconds>(now - entryTime);

        // only pop newest element if it's older than specified delay
        if (packageAgeSeconds.count() < m_packageDelaySeconds)
        {
            return false;
        }

        return true;
    });

    const Package package = m_packageQueue.front();
    m_packageQueue.pop();

    return package;
}
