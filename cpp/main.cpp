#include <iostream>
#include "ossie/ossieSupport.h"

#include "CustomSink.h"
int main(int argc, char* argv[])
{
    CustomSink_i* CustomSink_servant;
    Component::start_component(CustomSink_servant, argc, argv);
    return 0;
}

