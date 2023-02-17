#pragma once
#include<future>
#include<Windows.h>
#include<iostream>
class Cooker
{
public:
    Cooker(){}

    void listenOrder(std::future<std::vector<int>> orderP);

    void cook(std::future<int> ingredientP) {
        int ingredient = ingredientP.get();
        // this sleep is the time for cooking ingredient
        Sleep(1000);

    }

private:
    std::vector<int> myQueue;
};

