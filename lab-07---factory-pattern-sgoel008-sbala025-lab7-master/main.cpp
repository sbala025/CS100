#include "BaseFactory.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cerr << "Please enter a valid expression!" << endl;
        return 1;
    }

    BaseFactory factory = BaseFactory();
    Base * result = factory.parse(argv, argc);

    cout << "Result: " << result->evaluate() << endl;
}