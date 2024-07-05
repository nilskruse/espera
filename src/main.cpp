#include "Espera.hpp"
#include <iostream>

int main()
{
    float targetWidth;
    float targetHeight;
    float targetLength;

    float tolerancePercent;
    float standardDeviationPercent;

    int packageDelaySeconds;

    auto readFloat = [](const std::string &parameterName, float &value) {
        std::cout << "Enter " << parameterName << ":";
        std::cin >> value;
        return !std::cin.fail();
    };

    auto readInt = [](const std::string &parameterName, int &value) {
        std::cout << "Enter " << parameterName << ":";
        std::cin >> value;
        return !std::cin.fail();
    };

    // read the parameters
    if (readFloat("Target width", targetWidth) && 
        readFloat("Target height", targetHeight) &&
        readFloat("Target length", targetLength) && 
        readFloat("Tolerance (in percent)", tolerancePercent) &&
        readFloat("Standard deviaton of package dimensions (in percent)", standardDeviationPercent) &&
        readInt("How long does it take to process a package (in seconds)", packageDelaySeconds))
    {
        Espera espera(targetWidth, 
                      targetHeight, 
                      targetLength, 
                      tolerancePercent,
                      standardDeviationPercent,
                      packageDelaySeconds);
        espera.start();
    }
    else
    {
        std::cout << "Invalid input!\n";
    }

    return 0;
}
