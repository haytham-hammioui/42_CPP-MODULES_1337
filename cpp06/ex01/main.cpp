#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;

    data.id = 42;
    data.name = "OMERTAAA";

    Data* original = &data;

    uintptr_t raw = Serializer::serialize(original);

    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original pointer : " << original << std::endl;
    std::cout << "Serialized value : " << raw << std::endl;
    std::cout << "Restored pointer : " << restored << std::endl;

    if (original == restored)
        std::cout << "Pointers are equal!" << std::endl;
    else
        std::cout << "Pointers are NOT equal!" << std::endl;

    std::cout << restored->id << std::endl;
    std::cout << restored->name << std::endl;
}