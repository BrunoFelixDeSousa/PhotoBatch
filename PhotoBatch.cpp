#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>

std::string ToLower(std::string str)
{
	std::transform(std::begin(str), std::end(str), std::begin(str),
		[](unsigned char c) { return std::tolower(c); });

	return str;
}

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
			if (flagIt != std::end(m_Flags))
			{
				return flagIt->second;
			}
			
		}
		return false;
	}

	void Parse(int argc, char* argv[])
	{
		if (argc > 1)
		{
			for (int i = 0; i < argc; ++i)
			{
				std::string arg = ToLower(argv[i]);

				if (arg.length() >= 3)
				{
					// argumento tem que ter pelo menos 3 caracteres
					// os "--" iniciais e pelo menos um terceiro caracter
					if (arg[0] == '-' && arg[1] == '-')
					{
						// remover os "--" iniciais. ex: --rename
						arg = arg.substr(2); // final rename

						if (arg.find_first_of('=') != std::string::npos)
						{
							// isso é uma opção
						}
						else
						{
							// é uma flag
							auto flagIt = m_Flags.find(arg);
							if (flagIt != std::end(m_Flags))
							{
								//achamos uma flag registrada
								flagIt->second = true;
							}
						}
					}
				}
			}
		}
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