#pragma once

#include <string>
#include <iomanip>
#include <map>


/**
* classe usada para ler os argumentos da linha de comando
* 
* exemplo:
*	ArgumentParser argParser;
*	argParser.RegisterFlag("rename");
*	argParser.Parse(argc, argv);
*	std::cout << std::boolalpha << "Rename  : " << argParser.GetFlag("rename") << '\n';
*/
class ArgumentParser
{
public:
	// Registra uma flag usada durante o parse
	void RegisterFlag(const std::string& flag);

	// Registrar uma opção usada durante o parse
	void RegisterOption(const std::string& option);

	// Obtem o valor de uma flag obtida durante o parse
	bool GetFlag(const std::string& flag);

	//Obter o valor de uma flag obtida durante o parse
	const std::string ArgumentParser::GetOption(const std::string& option) const;

	// Faz o parse da lista de argumentos em argv
	void Parse(int argc, char* argv[]);

private:
	std::map<std::string, bool> m_Flags;
	std::map<std::string, std::string> m_Options;
};
