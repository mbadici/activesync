#include <sqlite3.h>
#include <iostream>
#include "dbs.h"
//#include <string>
using namespace std;


sqlite3 *dbs::handle;
int dbs::init()
{
   int exit;
   exit=sqlite3_open("state.db", &dbs::handle);
   std::string sql = "CREATE TABLE  IF NOT EXISTS devices("
                      "ID INTEGER PRIMARY KEY , "
                      "NAME           TEXT    NOT NULL, "
                      "SERIAL          TEXT     NOT NULL, "
                      "KEY            INT     NOT NULL);";

    char* messaggeError;
    sqlite3_open("state.db", &dbs::handle);
    exit = sqlite3_exec(dbs::handle, sql.c_str(), 0, 0, 0);

    if (exit != SQLITE_OK) {
        std::cout << sql.c_str() << std::endl;
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
     //   std::cout << "Table created Successfully" << std::endl;
    sqlite3_close(dbs::handle);

    if(exit!=0) std::cerr << "error open" << std::endl;

    return exit;
}

int dbs::query(string data)

{

/*

   if(mode){
            sql = "insert into devices( name,serial,key) values( '"+data+"','333','0');";
            }
   else
            {
             sql = "update devices set serial='444' where name= '"+data+"'";
            }
      cout << sql;
   */
    int exit = 0;
    char* messaggeError;
    sqlite3_open("state.db", &dbs::handle);
    exit = sqlite3_exec(dbs::handle, data.c_str(), 0, 0, 0);

    if (exit != SQLITE_OK) {
        std::cout << data.c_str() << std::endl;
        std::cout << messaggeError << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "values added" << std::endl;
    sqlite3_close(dbs::handle);

    return (0);
}

int dbs::insert(string data)
{

    string sql;
    sql = "insert into devices( name,serial,key) values( '"+data+"','333','0');";

    int exit = 0;
    char* messaggeError;
    sqlite3_open("state.db", &dbs::handle);
    exit = sqlite3_exec(dbs::handle, sql.c_str(), 0, 0, 0);

    if (exit != SQLITE_OK) {
        std::cout << sql.c_str() << std::endl;
        std::cout << messaggeError << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "values added" << std::endl;
    sqlite3_close(dbs::handle);

    return (0);

}

int dbs::update(string data)
{
   // string sql;
   // sql = "update devices set serial='444' where name= '"+data+"'";
    cout << data;
    int exit = 0;
    char* messaggeError;
    sqlite3_open("state.db", &dbs::handle);
    exit = sqlite3_exec(dbs::handle, data.c_str(), 0, 0, 0);

    if (exit != SQLITE_OK) {
        std::cout << messaggeError << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "values added" << std::endl;

    sqlite3_close(dbs::handle);

    return (0);


}

struct sql_line_result line;
 static int callback(void *dt, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)dt);
   line.num_rows=argc;
   line.col_result[0]=argv[0];
   printf("num %s\n","aaa");
   for(i = 0; i<argc; i++){
   line.col_result[i]=(argv[i] ? argv[i] : "NULL");
   }

 //  printf("\n");
   return 0;
}


struct sql_line_result dbs::retrieve(string data)
{


    const char* dat = "Callback function called";
    int exit = 0;
    char* messaggeError;

    sqlite3_open("state.db", &dbs::handle);
    exit = sqlite3_exec(dbs::handle, data.c_str(), callback, (void*)dat, 0);
    return line;
}
