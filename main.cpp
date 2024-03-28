#include<iostream>
#include "basic.h"
#include "nodeRelated.h"
#include "algorithm.h"

int main()
{
    std::cout << "****************RUN_BASIC****************************" << std::endl;
    RUN_BASIC();

    std::cout << "****************RUN_SMART_POINTER********************" << std::endl;
    runSmartPointer();

    std::cout << "****************RUN_CLASSHEIR************************" << std::endl;
    runClassHeir();

    std::cout << "****************RUN_SMART_NODE_RELATED***************" << std::endl;
    RUN_NODE_RELATED();

    std::cout << "****************RUN_FILE_IN_OUT**********************" << std::endl;
    runFileInOut();

    std::cout << "****************RUN_ALGORITHM************************" << std::endl;
    RUN_ALGORITHM();

    return 0;
}
