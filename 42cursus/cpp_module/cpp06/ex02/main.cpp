#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base* generate(void){
    Base* bs;
    srand(time(NULL));
    if (rand() % 3 == 0)
        bs = new A();
    else if (rand() % 3 == 1)
        bs = new B();
    else
        bs = new C();
    return bs;
}

void identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "this is pointer A\n";
    else if (dynamic_cast<B *>(p))
        std::cout << "this is poinetr B\n";
    else if (dynamic_cast<C *>(p))
        std::cout << "this is poinetr C\n";
}
void identify(Base& p){
    try{
        A& a = dynamic_cast<A &>(p);
        std::cout << "this is ref A\n";
        static_cast<void>(a);
    } catch (...) {}
    try{
        B& b = dynamic_cast<B &>(p);
        std::cout << "this is ref B\n";
        static_cast<void>(b);
    }
    catch (...){}
    try{
        C& c = dynamic_cast<C &>(p);
        std::cout << "this is ref C\n";
        static_cast<void>(c);
    }
    catch (...){}
}

int main(){
    Base *a = new A();
    Base *b = new B();
    Base *c = new C();
    Base *base = new Base();

    Base *gen1 = generate();
    identify(gen1);
    identify(a);
    identify(b);
    identify(c);
    identify(base);
    identify(*a);
    identify(*b);
    identify(*c);
    identify(*base);
}