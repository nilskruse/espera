#pragma once

#include "PackageQueue.hpp"

#include <atomic>
#include <random>

class PackageProducer
{
  public:
    explicit PackageProducer(PackageQueue &packageQueue, float targetWidth, float targetHeight, float targetLength,
                             float standardDeviation);
    virtual ~PackageProducer() = default;

    void run();

  private:
    PackageQueue &m_packageQueue;

    std::atomic<int> m_idCounter;

    std::random_device m_randomDevice;
    std::mt19937 m_rng;

    std::normal_distribution<float> m_widthDistribution;
    std::normal_distribution<float> m_heightDistribution;
    std::normal_distribution<float> m_lengthDistribution;
};
