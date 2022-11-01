#include <stdint.h>
#include <string>
#include <iostream>

struct Data
{
	std::string str;
	int num;
};

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main(void)
{
	Data data;

	data.str = "Hello World!";
	data.num = 1337;

	std::cout << "Before serialization:--------\n";
	std::cout << "Memory address: " << &data << "\nString: " << data.str << "\nInt: " << data.num << "\n";

	uintptr_t dataToCast = serialize(&data);
	Data *recastedData = deserialize(dataToCast);

	std::cout << "After serialization:---------\n";
	std::cout << "Memory address: " << recastedData << "\nString: " << recastedData->str << "\nInt: " << recastedData->num << "\n";

	return (0);
}