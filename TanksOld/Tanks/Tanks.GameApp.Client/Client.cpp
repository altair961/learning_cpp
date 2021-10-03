#include <iostream>
#include "di.hpp"
#include "TanksGameAppInterfaces.h"
#include "TanksGameAppImplementations.h"
#include "TanksGraphicsEngineInterfaces.h"
#include "TanksGraphicsEngineImplementations.h"


int main()
{
  /*  namespace di = boost::di;
    auto injector = di::make_injector(
        di::bind<IAdd>().to<Adder>()
    );
    Adder adder = injector.create<Adder>();

    int sum = adder.Add(5, 9);
    
    std::cout << "Hello World! " << sum << std::endl;*/


   /* namespace di = boost::di;
    auto injector = di::make_injector(
        di::bind<IGraphicsEngine>().to<GraphicsEngine>()
    );
    GraphicsEngine graphicsEngine = injector.create<GraphicsEngine>();*/
    GraphicsEngine graphicsEngine;

    

    graphicsEngine.ConstructEngine(256, 240, 4, 4, graphicsEngine);
   
    //int sum = adder.Add(5, 9);

   // std::cout << "Hello World! " << sum << std::endl;
}