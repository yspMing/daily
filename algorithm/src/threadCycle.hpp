#pragma once

#include <thread>
#include <iostream>
#include <cstdio>
#include <mutex>
#include <condition_variable>
#include <stdexcept>
#include <deque>

#ifdef WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif // WIN32

#define childFlag 1
#define mainFlag 0

int flag = childFlag;
int flag2 = 0;
std::mutex mu;
std::condition_variable cond;

void childThreadFunc(int cycle_time, char ch)
{
    //Create unique_lock
    std::unique_lock<std::mutex> lock(mu);
    for (int i = 0; i < 10; i++)
    {
        cond.wait(lock, []() {return flag == childFlag; });
        for (int j = 0; j < cycle_time; j++)
            std::cout << ch << ":" << j << "  ";
        std::cout << "\n";
        flag = mainFlag;
        cond.notify_all();
    }
}

void mainThreadFunc(int cycle_time, char ch)
{
    //Create unique_lock
    std::unique_lock<std::mutex> lock(mu);
    for (int i = 0; i < 10; i++)
    {
        cond.wait(lock, []() {return flag == mainFlag; });
        for (int j = 0; j < cycle_time; j++)
            std::cout << ch << ":" << j << "  ";
        std::cout << "\n";
        flag = childFlag;
        cond.notify_all();
    }
}

int mainThreadCycleFun()
{ 
    std::thread t1(childThreadFunc, 3, 'A');
    mainThreadFunc(5, 'B');
    t1.join(); 
    return 0;
}

void fun2(int x)
{
    for (int i = 0; i < 10; i++)
    {
        std::unique_lock<std::mutex>lock(mu);
        while (x != flag2)
            cond.wait(lock);
        std::cout << static_cast<char>('A' + x) << " ";
        flag2 = (flag2 + 1) % 3;
        cond.notify_all();
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

#define TRY_MUTEX 1
#define MY_MUTEX 0

volatile int counter(0); // non-atomic counter

void increases10K()
{
    for (int i = 0; i < 10000; i++)
    {
#if TRY_MUTEX
        if (mu.try_lock())
        {
            ++counter;
            mu.unlock();
        }
#elif MY_MUTEX
        mu.lock();
        ++counter;
        mu.unlock();
#endif
    }

}

void runIncreases10K()
{
    std::thread threads[10];
    for (int i = 0; i < 10; i++)
    {
        threads[i] = std::thread(increases10K);
    }
    for (auto& th : threads)
    {
        th.join();
    }
    std::cout << " successful increases of the counter " << counter << std::endl;
}

void printEvent(int x)
{
    if (x % 2 == 0)
        std::cout << x << " is even\n";
    else
        throw (std::logic_error("not even"));

}

void printThreadId(int id)
{
    try {
        std::unique_lock<std::mutex> lck(mu);
        printEvent(id);
    }
    catch (std::logic_error&)
    {
        std::cout << "[exception caught]\n";
    }
}

void runPrintThreadId()
{
    std::thread threads[10];
    for (int i = 0; i < 10; i++)
    {
        threads[i] = std::thread(printThreadId,i+1);
    }
    for (auto& th : threads)
    {
        th.join();
    }
}

std::deque<int> q;
int count = 0;

void dequeFunc1()
{
    while (true)
    {
        std::unique_lock<std::mutex> locker(mu);
        std::cout << "thread1 push value : " << count << std::endl;
        q.push_front(count++);
        locker.unlock();//如果是lock_guard，不支持手动解锁
        cond.notify_one();
#ifdef WIN32
        Sleep(1);
#else
        sleep(1);
#endif // WIN32
        
    }
}

void dequeFunc2()
{
    while (true)
    {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, []() {return !q.empty(); });
        auto data = q.back();
        q.pop_back();
        std::cout << "thread2 get value form thread1: " << data << std::endl;
    }
}

void runDequeThread()
{
    std::thread t1(dequeFunc1);
    std::thread t2(dequeFunc2);
    t1.join();
    t2.join();
}