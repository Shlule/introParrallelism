// parrallelism.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include<vector>

using std::cout;
using std::endl;
using std::vector;


struct Mat1 {
    int a{ 1 };
    int b{ 3 };
    int c{ 6 };
    int d{ 3 };
    int e{ 8 };
    int f{ 9 };
    int g{ 14 };
    int h{ 12 };
    int i{ 4 };
};

struct Mat2 {
    int a{ 3 };
    int b{ 1 };
    int c{ 4 };
    int d{ 12 };
    int e{ 5};
    int f{ 6 };
    int g{ 11 };
    int h{ 12 };
    int i{ 4 };
};

Mat1 mat1;
Mat2 mat2;






Mat2 matrixProduct(Mat1 mat1P, Mat2 mat2P) {
    Mat2 result;
    result.a = mat1P.a * mat2P.a + mat1P.b * mat2P.d + mat1P.c * mat2P.g;
    result.b = mat1P.a * mat2P.b + mat1P.b * mat2P.e + mat1P.c * mat2P.h;
    result.c = mat1P.a * mat2P.c + mat1P.b * mat2P.f + mat1P.c * mat2P.i;
    result.d = mat1P.d * mat2P.a + mat1P.e * mat2P.d + mat1P.f * mat2P.g;
    result.e = mat1P.d * mat2P.b + mat1P.e * mat2P.e + mat1P.f * mat2P.h;
    result.f = mat1P.d * mat2P.c + mat1P.e * mat2P.f + mat1P.f * mat2P.i;
    result.g= mat1P.g * mat2P.a + mat1P.h * mat2P.d + mat1P.i * mat2P.g;
    result.h = mat1P.g * mat2P.b + mat1P.h * mat2P.e + mat1P.i * mat2P.h;
    result.i = mat1P.g * mat2P.c + mat1P.h * mat2P.f + mat1P.i * mat2P.i;

    return result;
}
int getCoef(int index, Mat1 mat1P, Mat2 mat2P) {
    int result;
    switch (index) {

    case 0:result = mat1P.a * mat2P.a + mat1P.b * mat2P.d + mat1P.c * mat2P.g;
        return result;
    case 1:result = mat1P.a * mat2P.b + mat1P.b * mat2P.e + mat1P.c * mat2P.h;
        return result;
    case 2:result = mat1P.a * mat2P.c + mat1P.b * mat2P.f + mat1P.c * mat2P.i;
        return result;
    case 3:result = mat1P.d * mat2P.a + mat1P.e * mat2P.d + mat1P.f * mat2P.g;
        return result;
    case 4:result = mat1P.d * mat2P.b + mat1P.e * mat2P.e + mat1P.f * mat2P.h;
        return result;
    case 5:result = mat1P.d * mat2P.c + mat1P.e * mat2P.f + mat1P.f * mat2P.i;
        return result;
    case 6:result = mat1P.g * mat2P.a + mat1P.h * mat2P.d + mat1P.i * mat2P.g;
        return result;
    case 7:result = mat1P.g * mat2P.b + mat1P.h * mat2P.e + mat1P.i * mat2P.h;
        return result;
    case 8:result = mat1P.g * mat2P.c + mat1P.h * mat2P.f + mat1P.i * mat2P.i;
        return result;

    }
    
}


class Task {
public:
    void operator()()const {
        doSomething();
        doSomethingElse();
    }
private:
    void doSomething() const {
        cout << "Something" << endl;
    }

    void doSomethingElse() const {
        cout << "Something Else" << endl;
    }
};





int main() {
    Mat2 result;
    Mat2 MultiResult;
    std::vector<std::thread> threadVector;
    result = matrixProduct(mat1, mat2);
    std::cout << result.a <<' '<< result.b << ' ' << result.c << '\n';
    std::cout << result.d <<' '<< result.e << ' ' << result.f << '\n';
    std::cout << result.g <<' '<< result.h << ' ' << result.i << '\n';

    for (int i = 0; i < 9; i++) {
        std::thread t([&]() { MultiResult.a = getCoef(i, mat1, mat2); });
    }

    std::thread t0([&]() { MultiResult.a = getCoef(0, mat1, mat2);});
    std::thread t1([&]() { MultiResult.b = getCoef(1, mat1, mat2); });
    std::thread t2([&]() { MultiResult.c = getCoef(2, mat1, mat2); });
    std::thread t3([&]() { MultiResult.d = getCoef(3, mat1, mat2); });
    std::thread t4([&]() { MultiResult.e = getCoef(4, mat1, mat2); });
    std::thread t5([&]() { MultiResult.f = getCoef(5, mat1, mat2); });
    std::thread t6([&]() { MultiResult.g = getCoef(6, mat1, mat2); });
    std::thread t7([&]() { MultiResult.h = getCoef(7, mat1, mat2); });
    std::thread t8([&]() { MultiResult.i = getCoef(8, mat1, mat2); });

    t0.join();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();

    std::cout << MultiResult.a << ' ' << MultiResult.b << ' ' << MultiResult.c << '\n';
    std::cout << MultiResult.d << ' ' << MultiResult.e << ' ' << MultiResult.f << '\n';
    std::cout << MultiResult.g << ' ' << MultiResult.h << ' ' << MultiResult.i << '\n';

    




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
