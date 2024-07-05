#pragma once

#include "PackageQueue.hpp"

class PackageConsumer {
   public:
    explicit PackageConsumer(PackageQueue& packageQueue, float targetWidth,
                             float targetHeight, float targetLength,
                             float tolerancePercent = 10.0f);
    virtual ~PackageConsumer() = default;

    void run();

   private:
    PackageQueue& m_packageQueue;

    float m_targetWidth;
    float m_targetHeight;
    float m_targetLength;

    float m_tolerancePercent;
};
