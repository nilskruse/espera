#include "PackageProducer.hpp"
#include "PackageQueue.hpp"

#include <cassert>
#include <thread>

PackageProducer::PackageProducer(PackageQueue &packageQueue, float targetWidth, float targetHeight, float targetLength,
                                 float standardDeviationPercent)
    : m_packageQueue(packageQueue), m_idCounter(0), m_rng(m_randomDevice()),
      m_widthDistribution(targetWidth, targetWidth * standardDeviationPercent),
      m_heightDistribution(targetHeight, targetHeight * standardDeviationPercent),
      m_lengthDistribution(targetLength, targetLength * standardDeviationPercent)
{
    assert(targetWidth > 0.0f);
    assert(targetHeight > 0.0f);
    assert(targetLength > 0.0f);
    assert(standardDeviationPercent >= 0.0f);
}

void PackageProducer::run()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        Package package{
            ++m_idCounter,
            std::chrono::system_clock::now(),
            m_widthDistribution(m_rng),
            m_heightDistribution(m_rng),
            m_lengthDistribution(m_rng)
        };

        m_packageQueue.push(std::move(package));
    }
}
