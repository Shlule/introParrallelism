#include "Cooker.h"

void Cooker::listenOrder(std::future<std::vector<int>> orderP) {
    std::vector<int> order = orderP.get();
    for (auto i = order.begin(); i != order.end(); i++) {
        myQueue.emplace_back(*i);
    }
    Sleep(3000);
    std::cout << "message recu" << '\n';
}
