#include <iostream>
#include <template/template.h>

using namespace arosen::Template;

int main(int argc, char **argv) {
    MyVeryOwnClass foo(1, 4);

    std::cout << "The sum is: " << foo.sum() << std::endl;

    return 0;
}
