#include"my_library.h"

// Functions
void login();
void select();
void input_table();
void delete_table();
void read_table();


// Function implimentation

// 01-----
void login()
{
	cout << "\n\n";
	cout << "\033[34m<< Enter server name, user name\033[0m" << endl; //cahnge color to blue
	cout << "\033[34m>> \033[0m";
	cin >> server;
	cout << "\033[34m>> \033[0m";
	cin >> name;

	server_for = "tcp://" + server + ":3306";

	if (server == "localhost" && name == "root")
	{
		system("cls"); //cmd command to clear screen
		//cout<< system("ipconfig") << endl;
		cout << "\033[32mSuccesfully connected to: "<<"\033[31m" << server_for <<" MySQL Database " << "\033[0m" << endl;
		select();
	}

	else
	{
		cout << "\033[34m>> \033[31mAn error occurs while login! Please retry\n" << endl;
		//_getch(); //take any key input
		login(); //retry the current function
	}
}

// 02-----
void select()
{
	int i;
	cout << endl;
	select_ascii();
	cout << endl;
	cin >> i;
	//conditions
	if (i == 1 || i == 01)
	{
		input_table();
	}
	else if (i == 4 || i == 04)
	{
		delete_table();
	}
}


void input_table()
{
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;

	driver = get_driver_instance();
	con = driver->connect(server, name, password);

	stmt = con->createStatement();
	//cout << stmt->execute("SHOW DATABASES") << endl;
	stmt->execute("USE oop_project_db");
	stmt->execute("DROP TABLE IF EXISTS petrol_pump");
	stmt->execute("CREATE TABLE petrol_pump(id INT, fuel VARCHAR(15), price INT);");
}

void delete_table()
{
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;

	driver = get_driver_instance();
	con = driver->connect(server, name, password);

	stmt = con->createStatement();
	stmt->execute("USE oop_project_db");
	stmt->execute("DROP TABLE IF EXISTS petrol_pump");
}

void read_table()
{
}