#include <iostream>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "pt_BR");
	
	//std::cout << "Bruno Félix" << std::endl;
	for ( int i=0; i < argc; i++ ) {
		std::cout << argc << " " << argv[i] << '\n';
	}

	return 0;
}