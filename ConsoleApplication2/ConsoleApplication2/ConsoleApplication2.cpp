// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sqlite3.h>



int main()
{
    sqlite3* db;
    char* errorMessage = nullptr;
    int rc = sqlite3_open("mydb.db", &db);
    if (rc) {
        std::cerr<<"Not have database"<<sqlite3_errmsg(db)<<std::endl;
        return 1;
    }
    else {
        std::cout<<"Greate database is open / create" <<std::endl;
    }

    const char* createTableSQL =
        "CREATE TABLE IF NOT EXISTS students("
    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
    "name TEXT NOT NULL,"
    "grade INTEGER);";
    rc = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errorMessage);
    if (rc != SQLITE_OK) {
        std::cerr <<"Error"<< errorMessage << std::endl;
        sqlite3_free(errorMessage);
    }
    else {
        std::cout << "'students'; is created"<<std::endl;
    }
    sqlite3_close(db);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
