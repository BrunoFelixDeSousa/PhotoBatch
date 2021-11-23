#include <iostream>
#include <iomanip>
#include <map>

class ArgumentParser
{
public:
	void RegisterFlag(const std::string& flag)
	{
		if (!flag.empty())
		{
			m_Flags[flag] = false;
		}
	}

	bool GetFlag(const std::string& flag)
	{

		if (!flag.empty())
		{
			auto flagIt = m_Flags.find(flag);
			if (flagIt != std::(end(m_Flags)
			{
				return flagIt->second;
			}
			
		}
		return false;
	}

	void Parse(int argc, char* argv[])
	{

	}

private:
	std::map<std::string, bool> m_Flags;
};

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