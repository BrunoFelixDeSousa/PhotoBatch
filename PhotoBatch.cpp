#include <iostream>
#include <string>

#include "ArgumentParser.h"


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "pt_BR");
	
	ArgumentParser argParser;

	argParser.RegisterFlag("rename");
	argParser.RegisterFlag("convert");
	argParser.RegisterFlag("rezise");
	argParser.RegisterFlag("scale");

	argParser.Parse(argc, argv);

	std::cout << std::boolalpha << "Rename  : " << argParser.GetFlag("rename") << '\n';
	std::cout << std::boolalpha << "Convert : " << argParser.GetFlag("convert") << '\n';
	std::cout << std::boolalpha << "Rezise  : " << argParser.GetFlag("rezise") << '\n';
	std::cout << std::boolalpha << "Scale   : " << argParser.GetFlag("scale") << '\n';


	return 0;
}