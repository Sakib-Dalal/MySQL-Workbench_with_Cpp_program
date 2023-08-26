#include"my_library.h"
#include<string.h>

// Functions
void login();
void select();
int insert_data();
int update_data();
int read_data();
int delete_data();

int opt_in();
int opt_de();
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
	cout << "\033[32m<<Enter Input: \033[0m";
	cin >> i;

	//conditions

	if (i == 1 || i == 01)
	{
		system("cls");
		insert_data();
	}
	else if (i == 2 || i == 02)
	{
		system("cls");
		read_data();
	}
	else if (i == 3 || i == 03)
	{
		system("cls");
		update_data();
	}
	else if (i == 4 || i == 04)
	{
		system("cls");
		delete_data();
	}
	else if (i == 5 || i == 05)
	{
		system("cls");
		cout << "\033[31m<<Press '1' to 'yes' '0' to 'no': \033[0m";
		cin >> i;
		if (i == 1)
		{
			system("cls");
			main_ascii();
			login();
		}
		else if (i != 1)
		{
			system("cls");
			select();
		}
	}
	else if (i != 1 || i != 01 || i != 2 || i != 02 || i != 3 || i != 03 || i != 4 || i != 04|| i != 5||i!=05)
	{
		system("cls");
		cout << "\033[31m<<Error try again! \033[0m";
		select();
		
	}
}



//-01
int insert_data()
{
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;
	

	driver = get_driver_instance();
	con = driver->connect(server, name, password);
	
	
	 //
	cout << endl<<"\033[34m<<using database now: \n\033[0m"<< endl;
	insert_data_format(); // print format ascii
	con->setSchema("oop_project_db");
	//-----
	pstmt = con->prepareStatement("INSERT INTO my_data(id_no, type, Component_name, Description, price) VALUES(?,?,?,?,?)");
	//int sr_no = 0;
	//pstmt->setInt(1, 0);
	int id_no;
	cout<< "\n\033[32m<<Enter id_no: \033[0m";
	cin >> id_no;
	pstmt->setInt(1, id_no);
	string type;
	cout << "\n\033[32m<<Enter Type of Component: \033[0m";
	cin >> type;
	pstmt->setString(2, type);
	string Component_name;
	cout<< "\n\033[32m<<Enter component name: \033[0m";
	cin >> Component_name;
	pstmt->setString(3, Component_name);
	string Description;
	cout<< "\n\033[32m<<Enter Description (to add space use '_'): \033[0m";
	cin >> Description;
	pstmt->setString(4, Description);
	int price;
	cout<< "\n\033[32m<<Enter Price: \033[0m";
	cin >> price;
	pstmt->setInt(5, price);
	pstmt->execute();

	cout<<"\n\033[34m<<Insert Data Complete :)\n\033[0m";

	opt_in();

	delete pstmt;
	delete con;
	system("pause");
	return 0;
}


//--02
int read_data()
{
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;


	driver = get_driver_instance();
	con = driver->connect(server, name, password);

	con->setSchema("oop_project_db");
	pstmt = con->prepareStatement("SELECT* FROM my_data;");
	result = pstmt->executeQuery();
	char bspc[] = "          ";
	char spc[] = " ";
	cout << endl;

	cout <<"\t\033[0m------------------------------------------------------------------------\033[0m" << endl;
	cout <<"\t"<<bspc << "\033[0msr_no \033[31mid_no \033[32mtype \033[33mComponent_name \033[34mDescription \033[35mprice" << endl;
	cout <<"\t\033[0m------------------------------------------------------------------------\033[0m" << endl;
	while (result->next())
	{
		cout << "\t" << bspc <<"\033[0m"<< result->getInt(1) << spc << "\033[31m" << result->getInt(2) << spc << "\033[32m" << result->getString(3).c_str() <<spc<< "\033[33m"  << result->getString(4).c_str() << spc <<"\033[34m" << result->getString(5).c_str() << spc<<"\033[35m" << result->getInt(6) <<"\033[0m" << endl;
		cout << "\t\033[36m------------------------------------------------------------------------\033[0m" << endl;
	}

	cout << "<<Press 1 to exit: ";
	int i;
	cin >> i;
	if (i==1)
	{
		system("cls");
		select();
	}
	else
	{
		system("cls");
		read_data();
	}
	delete result;
	delete pstmt;
	delete con;
	return 0;
}


int update_data()
{
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;

	driver = get_driver_instance();
	con = driver->connect(server, name, password);

	con->setSchema("oop_project_db");
	pstmt = con->prepareStatement("SELECT* FROM my_data;");
	result = pstmt->executeQuery();

	char bspc[] = "          ";
	char spc[] = " ";
	cout << endl;

	cout << "\t\033[0m------------------------------------------------------------------------\033[0m" << endl;
	cout << "\t" << bspc << "\033[0msr_no \033[31mid_no \033[32mtype \033[33mComponent_name \033[34mDescription \033[35mprice" << endl;
	cout << "\t\033[0m------------------------------------------------------------------------\033[0m" << endl;
	while (result->next())
	{
		//printf("Reading from table=(%d, %d, %s, %s, %s, %d)\n", result->getInt(1), result->getInt(2), result->getString(3).c_str(), result->getString(4).c_str(), result->getString(5).c_str(), result->getInt(6));
		cout << "\t" << bspc << "\033[0m" << result->getInt(1) << spc << "\033[31m" << result->getInt(2) << spc << "\033[32m" << result->getString(3).c_str() << spc << "\033[33m" << result->getString(4).c_str() << spc << "\033[34m" << result->getString(5).c_str() << spc << "\033[35m" << result->getInt(6) << "\033[0m" << endl;
		cout << "\t\033[36m------------------------------------------------------------------------\033[0m" << endl;
	}

	cout << "\n<<Select ID to Update: ";

	return 0;
}

int delete_data()
{
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;


	driver = get_driver_instance();
	con = driver->connect(server, name, password);

	con->setSchema("oop_project_db");
	pstmt = con->prepareStatement("SELECT* FROM my_data;");
	result = pstmt->executeQuery();

	char bspc[] = "          ";
	char spc[] = " ";
	cout << endl;

	cout << "\t\033[0m------------------------------------------------------------------------\033[0m" << endl;
	cout << "\t" << bspc << "\033[0msr_no \033[31mid_no \033[32mtype \033[33mComponent_name \033[34mDescription \033[35mprice" << endl;
	cout << "\t\033[0m------------------------------------------------------------------------\033[0m" << endl;
	while (result->next())
	{
		//printf("Reading from table=(%d, %d, %s, %s, %s, %d)\n", result->getInt(1), result->getInt(2), result->getString(3).c_str(), result->getString(4).c_str(), result->getString(5).c_str(), result->getInt(6));
		cout << "\t" << bspc << "\033[0m" << result->getInt(1) << spc << "\033[31m" << result->getInt(2) << spc << "\033[32m" << result->getString(3).c_str() << spc << "\033[33m" << result->getString(4).c_str() << spc << "\033[34m" << result->getString(5).c_str() << spc << "\033[35m" << result->getInt(6) << "\033[0m" << endl;
		cout << "\t\033[36m------------------------------------------------------------------------\033[0m" << endl;
	}

	cout << "\n<<Enter data sr_no to delete: ";
	int sr_no;
	cin >> sr_no;
	


	pstmt = con->prepareStatement("DELETE FROM my_data WHERE sr_no = ?");
	pstmt->setInt(1, sr_no);
	result = pstmt->executeQuery();
	cout << "<<Row Deleted\n";
	
	opt_de();

	delete result;
	delete pstmt;
	delete con;
	return 0;
}

int opt_in()
{
	cout << "\n\033[34m<<Enter '0' to add more data or '1' to exit: \033[0m";
	int opt;
	cin >> opt;
	if (opt == 0)
	{
		system("cls");
		insert_data();
	}
	else if (opt == 1)
	{
		system("cls");
		select();
	}
	else
	{
		system("cls");
		cout << "\n\033[31m<<Error input try again\n\033[0m";
		opt_in();
	}
	return 0;
}

int opt_de()
{
	cout << "\033[34m<<Enter 1 to continue 0 to exit: \033[0m";
	int opt;
	cin >> opt;
	if (opt == 1)
	{
		system("cls");
		delete_data();
	}
	else if (opt == 0)
	{
		system("cls");
		select();
	}
	else
	{
		system("cls");
		cout << "\n\033[31m<<Error input try again\n\033[0m";
		opt_de();
	}
	return 0;
}