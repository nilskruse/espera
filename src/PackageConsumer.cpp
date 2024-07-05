#include "PackageConsumer.hpp"

#include <cassert>
#include <iostream>

#include "PackageQueue.hpp"

PackageConsumer::PackageConsumer(PackageQueue &packageQueue, float targetWidth, float targetHeight, float targetLength,
                                 float tolerancePercent)
    : m_packageQueue(packageQueue), m_tolerancePercent(tolerancePercent), m_targetWidth(targetWidth),
      m_targetHeight(targetHeight), m_targetLength(targetLength)
{
    assert(m_targetWidth > 0.0f);
    assert(m_targetHeight > 0.0f);
    assert(m_targetLength > 0.0f);
    assert(m_tolerancePercent >= 0.0);
}

void PackageConsumer::run()
{
    while (true)
    {
        Package package = m_packageQueue.pop();

        auto isWithinTolerance = [this](const float value, const float target) {
            return std::abs(value - target) <= target * m_tolerancePercent;
        };

        if (isWithinTolerance(package.width, m_targetWidth) && 
            isWithinTolerance(package.height, m_targetHeight) &&
            isWithinTolerance(package.height, m_targetLength))
        {
            std::cout << "labeled package with id: " << package.id << "\n";
        }
        else
        {
            std::cout << "discarded package with id: " << package.id << "\n";
        }
    }
}
