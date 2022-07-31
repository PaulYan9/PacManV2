// PacManV2.cpp: определяет точку входа для приложения.
//

#include "PacManV2.h"
#include "Model/filereader.h"
#include "Model/modelexception.h"

#include <string> 

using namespace std;

int main()
{
	try
	{
		std::string file_name = "level12.txt";
		FileReader reader(file_name);
	}
	catch(WrongFileNameException e)
	{
		cout << e.what() << "\n";
	}
	catch (NoSuchFileException e)
	{
		cout << e.what() << "\n";
	}
	catch (FileOpenException e)
	{
		cout << e.what() << "\n";
	}

	return 0;
}
