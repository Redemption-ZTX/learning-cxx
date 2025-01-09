#include "../exercise.h"
#include <iostream>

// READ: 静态字段 <https://zh.cppreference.com/w/cpp/language/static>
// READ: 虚析构函数 <https://zh.cppreference.com/w/cpp/language/destructor>

struct A {
    static int num_a;// Static field declaration

    A() {
        ++num_a;
    }
    virtual ~A() {// Virtual destructor for proper cleanup
        --num_a;
    }

    virtual char name() const {
        return 'A';
    }
};

struct B final : public A {
    static int num_b;// Static field declaration

    B() {
        ++num_b;
    }
    ~B() override {// Override to ensure correct destructor call
        --num_b;
    }

    char name() const final {
        return 'B';
    }
};

// Static field definitions
int A::num_a = 0;
int B::num_b = 0;

int main(int argc, char **argv) {
    auto a = new A;
    auto b = new B;
    ASSERT(A::num_a == 2, "Fill in the correct value for A::num_a");
    ASSERT(B::num_b == 1, "Fill in the correct value for B::num_b");
    ASSERT(a->name() == 'A', "Fill in the correct value for a->name()");
    ASSERT(b->name() == 'B', "Fill in the correct value for b->name()");

    delete a;
    delete b;
    ASSERT(A::num_a == 0, "Every A was destroyed");
    ASSERT(B::num_b == 0, "Every B was destroyed");

    A *ab = new B;// Derived class pointer can be assigned to base class pointer
    ASSERT(A::num_a == 1, "Fill in the correct value for A::num_a");
    ASSERT(B::num_b == 1, "Fill in the correct value for B::num_b");
    ASSERT(ab->name() == 'B', "Fill in the correct value for ab->name()");

    B &bb = dynamic_cast<B &>(*ab);// Safe downcasting
    ASSERT(bb.name() == 'B', "Fill in the correct value for bb->name()");

    delete ab;// Correctly deletes the derived object through base pointer due to virtual destructor
    ASSERT(A::num_a == 0, "Every A was destroyed");
    ASSERT(B::num_b == 0, "Every B was destroyed");

    return 0;
}
