# Description

In the main function, the parameters for the application are obtained from the user and used to initialize the Espera object. Then the start() function of Espera is called.

In the Espera object, the PackageQueue, PackageProducer and PackageConsumer objects are initialized with the corresponding parameters. The PackageQueue is passed as a reference to the PackageProducer and PackageConsumer. In the start() function the threads are created.

The PackageQueue has a push and pop function to add or take packages from the queue. A mutex and a condition variable are used to ensure safe, synchronized access to the underlying queue. 

The PackageProducer periodically creates packages with random dimensions based on normal distributions which are parameterised by the user when starting the program. The packages are pushed onto the PackageQueue. An atomic counter is used for assigning ids, in case we plan on introducing more producers, although further modification is required as the counter is not a static member and would not be shared across multiple instances.

The PackageConsumer tries to pop packages from the queue as fast as possible although it is limited by speed of package creation and spends most of the time waiting for the condition variable to become true. Once a package is obtained, the dimensions are checked for the user-specified tolerance and the package is either labeled or discarded.

Build and run with:
```
cmake . && make && ./EsperaProject
```
