#include "Espera.hpp"
#include "PackageProducer.hpp"

Espera::Espera(float targetWidth, float targetHeight, float targetLength, float tolerancePercent,
               float standardDeviationPercent, int packageDelaySeconds)
    : m_packageQueue(packageDelaySeconds),
      m_packageConsumer(m_packageQueue, targetWidth, targetHeight, targetLength, tolerancePercent),
      m_packageProducer(m_packageQueue, targetWidth, targetHeight, targetLength, standardDeviationPercent)
{
}

void Espera::start()
{
    std::thread producerThread(&PackageProducer::run, &m_packageProducer);
    std::thread consumerThread(&PackageConsumer::run, &m_packageConsumer);

    producerThread.join();
    consumerThread.join();
}
