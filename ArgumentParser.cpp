#include "ArgumentParser.h"


std::string ToLower(std::string str)
{
	std::transform(std::begin(str), std::end(str), std::begin(str),
		[](unsigned char c) { return std::tolower(c); });

	return str;
}

void ArgumentParser::RegisterFlag(const std::string& flag)
{
	if (!flag.empty())
	{
		m_Flags[flag] = false;
	}
}

bool ArgumentParser::GetFlag(const std::string& flag)
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

void ArgumentParser::Parse(int argc, char* argv[])
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