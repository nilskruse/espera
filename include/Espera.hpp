#pragma once

#include "PackageConsumer.hpp"
#include "PackageProducer.hpp"
#include "PackageQueue.hpp"

class Espera
{
  public:
    explicit Espera(float targetWidth, float targetHeight, float targetLength, float tolerancePercent,
                    float standardDeviationPercent, int packageDelaySeconds);
    virtual ~Espera() = default;

    void start();

  private:
    PackageQueue m_packageQueue;
    PackageProducer m_packageProducer;
    PackageConsumer m_packageConsumer;
};
