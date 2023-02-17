// ParrallelismPage2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<thread>
#include<mutex>



std::vector<int> myVector{ 1,5,3,8,4,6,1,2 };

// this part is for sequential ============================================================================================================
int sumOfVector(std::vector<int> vectorP) {
    int result = 0;
    for (auto i = vectorP.begin(); i != vectorP.end(); i++) {
        result += *i;
    }
    return result;
}

// this part is for local thread =========================================================================================================

 const std::size_t computeHalfSize(std::vector<int> vectorP) {
    return vectorP.size() / 2;
}

 std::vector<int> vectorResult;
 int intResult;


void multiSumOfVector(std::vector<int> vectorP) {
    
    
    std::size_t halfSize = computeHalfSize(vectorP);
    if (halfSize > 1) {
        std::vector<int> lArray{ vectorP.begin(), vectorP.begin() + halfSize };
        std::vector<int> rArray{ vectorP.begin() + halfSize, vectorP.end() };
        std::thread t0 (multiSumOfVector, lArray);
        std::thread t1 (multiSumOfVector, rArray);
        t0.join();
        t1.join();
    }
    else {
        vectorResult.emplace_back(sumOfVector(vectorP));
    }
    
}

// this part is for global and mutex =======================================================================================================

// this part is for the even and odd part ==================================================================================================
std::mutex myMutex;

int i;

void oddNumbers(int limitP) {

    while (i < limitP) {
        if (limitP % 2 == 0) {
            std::lock_guard<std::mutex> guard(myMutex);

            i++;

            std::cout << i << '\n';

        }

    }
    
    
   
}
void evenNumbers(int limitP) {
    while (i < limitP) {
        if (limitP % 2 == 1) {
            std::lock_guard<std::mutex> lock(myMutex);
            i++;
            std::cout << i << '\n';
        }
    }
    
}

int main()
{
    /*std::cout << sumOfVector(myVector) << '\n';
    multiSumOfVector(myVector);
    
    while (computeHalfSize(vectorResult) > 1) {
        std::vector<int> vectorToSum = std::move(vectorResult);
        multiSumOfVector(vectorToSum);
    }
    intResult = sumOfVector(vectorResult);
    std::cout << intResult << '\n';*/
    
    //naive part of even odd exercice =====================================================================================================

    std::thread t0(oddNumbers, 1000);
    std::thread t1(evenNumbers, 1000);
    t0.join();
    t1.join();
    

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
