#include "Serializer.hpp"
#include <iostream>
#include <cassert>

#define VALUE 58949

int main() {
    Data data;
    data.value = VALUE;

    uintptr_t *raw = Serializer::serialize(&data);
    Data *ptr = Serializer::deserialize(raw);

    assert(ptr->value == VALUE);
    std::cout << "ptr->value: " << ptr->value << std::endl;
    assert(&data == ptr);
    std::cout << "&data: " << &data << std::endl;
    std::cout << "ptr: " << ptr << std::endl;

    std::cout << "Success!" << std::endl;
    return 0;
}
