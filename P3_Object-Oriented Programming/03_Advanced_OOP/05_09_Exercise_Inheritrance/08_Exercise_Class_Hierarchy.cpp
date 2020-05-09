/*
Exercise: Class Hierarchy
Multi-level inheritance is term used for chained classes in an inheritance tree.
Have a look at the example in the notebook below to get a feel for multi-level inheritance.

基本上就是在說
最後一個人, 可以像 chain rule 一樣, 一直往回, 用到最一開始base class的成員

ex:
    A (base class) -> B 繼承A, --> C 繼承B,
    只要合法的情況之下, C是可以使用A裡面的東西
*/


#include <iostream>

// Base class : class A 
class A
{
    private:
        int a_attr;

    public:
        void set_a(int);
        int get_a() const;
};

void A::set_a(int a) { A::a_attr = a; }
int A::get_a() const { return A::a_attr; }

// Base class: class A ; Derived class: class B
class B : public A
{
    private:
        int b_attr;

    public:
        void set_ab(int, int);
        int get_b() const;
};

void B::set_ab(int a, int b) { 
    B::set_a(a); 
    B::b_attr = b;
}

int B::get_b() const { return B::b_attr; }

// base class: class B ; Derived class C
class C : public B
{
    private:
        int c_attr;
    
    public:
        void set_abc(int, int, int);
        int get_c() const;
        void print_abc(void);
};

void C::set_abc(int a, int b, int c) {
    C::set_ab(a, b);
    C::c_attr = c;
}

int C::get_c() const { return C::c_attr; }

void C::print_abc(void) {
    std::cout << C::get_a() << ", " << C::get_b() << ", " << C::get_c() << "\n";
}

int main() {
    C c;
    c.set_abc(1, 2, 3);
    c.print_abc();
}