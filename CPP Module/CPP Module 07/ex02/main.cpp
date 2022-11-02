#include "Array.hpp"
#include <string>

int main(void)
{
    Array<float> arrOfFloats(10);
    int size = arrOfFloats.size();
    for (int i = 0; i < size; ++i)
        arrOfFloats[i] = static_cast<float>(i) * 3;
    std::cout << arrOfFloats << std::endl;

    Array<std::string> arrOfStrings(3);
    arrOfStrings[0] = "Hello";
    arrOfStrings[1] = " World";
    arrOfStrings[2] = " !";
    std::cout << arrOfStrings << std::endl;

	try
	{
        arrOfStrings[22] = " 42";
    }
	catch (std::exception &e)
	{
        std::cout << "Index is out of range" << std::endl;
    }

	Array<int> arrOfInt;
    try
	{
        arrOfInt[0] = 10;
    }
	catch (std::exception &e)
	{
        std::cout << "Index is out of range" << std::endl;
    }

    return (0);
}
