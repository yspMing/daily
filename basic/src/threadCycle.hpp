#pragma once

#include<thread>
#include<iostream>
#include<cstdio>
#include<mutex>
#include<condition_variable>

int flag = 1;
int flag2 = 0;
std::mutex mu;
std::condition_variable cv;

void fun(int x, char c, int f) {
    std::unique_lock<std::mutex> lock(mu);
    for (int i = 0; i < 10; i++) {
        while (flag != f)
            cv.wait(lock);
        for (int j = 0; j < x; j++)
            std::cout << c << ":" << j << std::endl;
        flag = (f == 1) ? 0 : 1;
        cv.notify_one();
    }
}

int mainThreadCycleFun()
{ 
    std::thread t1(fun, 3, 'A', 1);
    fun(5, 'B', 0); 
    t1.join(); 
    return 0;
}

void fun2(int x)
{
    for (int i = 0; i < 10; i++)
    {
        std::unique_lock<std::mutex>lock(mu);
        while (x != flag2)
            cv.wait(lock);
        std::cout << static_cast<char>('A' + x) << " ";
        flag2 = (flag2 + 1) % 3;
        cv.notify_all();
    }
}

int mainThreadCycleFun2()
{
    std::thread t1(fun2, 1);
    std::thread t2(fun2, 2);
    fun2(0);
    t1.join();
    t2.join();
    return 0;
}