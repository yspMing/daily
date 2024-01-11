#include<iostream>
#include "apple.h"
#include "basic.h"
#include "nodeRelated.h"

int main()
{
    std::cout << "****************RUN_BASIC***************" << std::endl;
    RUN_BASIC();

    std::cout << "****************RUN_SMART_POINTER***************" << std::endl;
    runSmartPointer();

    std::cout << "****************RUN_CLASSHEIR***************" << std::endl;
    runClassHeir();

    std::cout << "****************RUN_SMART_NODE_RELATED***************" << std::endl;
    RUN_NODE_RELATED();

    std::cout << "****************RUN_FILE_IN_OUT***************" << std::endl;
    runFileInOut();

    return 0;
}
