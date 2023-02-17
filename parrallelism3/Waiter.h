#pragma once
#include"Cooker.h"
#include<future>
#include<iostream>
#include<thread>
#include<Windows.h>
class Waiter
{
    Waiter(Cooker& cookerP);

    void takeOrder(std::future<std::vector<int>> orderP) {


    }

    void giveOrder();

    Cooker& cooker;
    std::promise<std::vector<int>> myList;
    std::future<std::vector<int>> command = Waiter::myList.get_future();
};

