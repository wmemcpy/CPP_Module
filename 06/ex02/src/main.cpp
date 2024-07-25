#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main()
{
    srand(time(NULL));

    for (int i = 0; i < 10; ++i)
    {
        std:: cout << "Test " << i + 1 << ":\n";
        Base *ptr = generate();
        std::cout << "Ptr type: ";
        identify(ptr);
        std::cout << "Ref type: ";
        identify(*ptr);
        delete ptr;
        std::cout << std::endl;
    }

    return 0;
}
