#include <template/template.h>

using namespace arosen::Template;

MyVeryOwnClass::MyVeryOwnClass(int a, int b)
: a_(a)
, b_(b)
{}

int MyVeryOwnClass::sum() const {
    return a_ + b_;
}
