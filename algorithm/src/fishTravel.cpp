#include <iostream>
#include <string.h>

namespace algorithm{

static int miniFishSpan(int n, int* fishPrice, int* savePrice)
{
    int* DP = (int*)malloc(n * sizeof(int));
    memset(DP, 0, n * sizeof(int));

    DP[0] = fishPrice[0];

    int minVal;
    for (int i = 1; i < n; i++)
    {
        minVal = fishPrice[i];
        int tmpPrice;
        for (int j = 0; i < i; j++)
        {
            tmpPrice = fishPrice[j] + savePrice[j] * (i - j);
            minVal = tmpPrice < minVal ? tmpPrice : minVal;
        }
        DP[i] = DP[i - 1] + minVal;
    }
    return DP[n - 1];
}

static int miniFishSpan2(int n, int* fishPrice, int* savePrice)
{
    int cost = fishPrice[0];

    int minVal;
    for (int i = 1; i < n; i++)
    {
        minVal = fishPrice[i];
        int tmpPrice;
        for (int j = 0; j < i; j++)
        {
            tmpPrice = fishPrice[j] + savePrice[j] * (i - j);
            minVal = tmpPrice < minVal ? tmpPrice : minVal;
        }
        cost += minVal;
    }
    return cost;
}

static int miniFishSpan3(int n, int* fishPrice, int* savePrice) {
    int min=100000,t=0;
    for(int i=0;i<n;i++){
        if(min> fishPrice[i])
        {
            min= fishPrice[i];
        }
        t=t+min;
        min=min+ savePrice[i];
    }
    return t;
}


void runMiniFishSpan()
{
    int n = 5;
    int fishPrice[5] = { 6,7,3,8,9 };
    int savePrice[5] = { 3,1,2,3,5 };
    int ans = miniFishSpan2(5, fishPrice, savePrice);
    std::cout << "miniFishSpan: " << ans << std::endl;
}

}