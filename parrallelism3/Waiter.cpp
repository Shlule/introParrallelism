#include "Waiter.h"

Waiter::Waiter(Cooker& cookerP): cooker{cookerP}{}

void Waiter::giveOrder() {
        std::thread callCooker (&Cooker::listenOrder, &cooker, std::ref(command));
        std::cout << "message donner" << '\n';
}