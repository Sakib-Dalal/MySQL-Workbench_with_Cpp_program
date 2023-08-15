#include"my_functions.h"

int main()
{
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;

	main_ascii(); // calling the function main_ascii from ASCIIART.h file
	login(); //calling the login function from my_functions.h file

	//-------------------
	try
	{
		driver = get_driver_instance();
		con = driver->connect(server_for, name, password);
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}
	//-------------------

	return 0;
}
