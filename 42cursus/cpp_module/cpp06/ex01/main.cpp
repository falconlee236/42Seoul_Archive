#include "Serializer.hpp"

int main()
{
    Data ptr;
    Data *convertPtr = NULL;

    ptr.name = "original data";
    convertPtr = Serializer::deserialize(Serializer::serialize(&ptr));

    std::cout << "ptr.name: " << ptr.name << std::endl
              << "convertPtr.name: " << convertPtr->name << std::endl;
    return 0;
}