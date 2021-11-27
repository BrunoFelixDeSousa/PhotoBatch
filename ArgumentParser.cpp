#include "ArgumentParser.h"
#include "Utils.h"

void ArgumentParser::RegisterFlag(const std::string& flag)
{
	if (!flag.empty())
	{
		m_Flags[flag] = false;
	}
}

void ArgumentParser::RegisterOption(const std::string& option)
{
	if (!option.empty())
	{
		m_Options[option] = "";
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

const std::string ArgumentParser::GetOption(const std::string& option) const
{
	if (!option.empty())
	{
		auto optionIt = m_Options.find(option);
		if (optionIt != std::end(m_Options))
		{
			return optionIt->second;
		}
	}

	static std::string EmptyOption = "";
	return EmptyOption;
}

void ArgumentParser::Parse(int argc, char* argv[])
{
	if (argc > 1)
	{
		for (int i = 0; i < argc; ++i)
		{
			std::string arg = Utils::ToLower(argv[i]);

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
						const size_t equalSingPos = arg.find('=');
						if (equalSingPos != std::string::npos)
						{
							std::string optionName = arg.substr(0, equalSingPos);
							std::string optionValue = arg.substr(equalSingPos + 1);

							auto optionIt = m_Options.find(optionName);
							if (optionIt != std::end(m_Options))
							{
								// achamos uma opção registrada
								optionIt->second = optionValue;
							}
						}
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