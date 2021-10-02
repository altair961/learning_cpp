#include <iostream>
#include "di.hpp"
#include "TanksGameAppInterfaces.h"
#include "TanksGameAppImplementations.h"

int main()
{
    namespace di = boost::di;
    auto injector = di::make_injector(
        di::bind<IAdd>().to<Adder>()
    );
    Adder adder = injector.create<Adder>();

    int sum = adder.Add(5, 9);
    
    std::cout << "Hello World! " << sum << std::endl;
}