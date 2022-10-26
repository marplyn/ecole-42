#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4 || std::strlen(argv[1]) == 0 || std::strlen(argv[2]) == 0)
	{
		std::cout << "Wrong input!\n";
		return (1);
	}
	std::string filename = argv[1];
	std::ifstream file;
	file.open(filename);
	if (!file.is_open())
	{
		std::cout << "Failed to open file!\n";
		return (1);
	}
	std::ofstream outputFile;
	outputFile.open(filename.append(".replace"));
	if (!outputFile.is_open())
	{
		file.close();
		std::cout << "Failed to create file!\n";
		return (1);
	}
	std::string line;
	size_t		pos;
	size_t		rPos;
	size_t		rSize = std::strlen(argv[2]);
	while (std::getline(file, line))
	{
		rPos = 0;
		while (true)
		{
			pos = line.find(argv[2], rPos);
			if (pos == std::string::npos)
			{
				outputFile << line.substr(rPos, line.length() - rPos) << '\n';
				break;
			}
			outputFile << line.substr(rPos, pos - rPos) << argv[3];
			rPos = pos + rSize;
		}
	}
	file.close();
	outputFile.close();
	return (0);
}
