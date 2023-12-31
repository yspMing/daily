#include<iostream>
#include "apple.h"
#include "basic.h"
#include "nodeRelated.h"

int main()
{
    std::cout<<"hello world"<<std::endl;
    APPLE_MAKE();
    APPLE_EAT();

    RUN_BASIC();

    runSmartPointer();

    runClassHeir();

    RUN_NODE_RELATED();

    return 0;
}
