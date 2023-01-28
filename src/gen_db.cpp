#include "gen_db.h"
//#include "dbs.h"
#include <iostream>
#include "include/sqlite_db.h"
//#include <string>
using namespace std;
gen_db::gen_db(){



}



    int gen_db::insert(string data, string serial )
    {
        dbs database;
        database.init();
       //  sql = "insert into devices( name,serial,key) values( '"+data+"','333','0');";
        data="insert into devices ( name,serial,key) values ('"+data+"','"+serial+"',0)";

        database.insert(data);
        return 0;

}
    int gen_db::update(string data, string serial, int key)
    {
        dbs database;
        database.init();
        data="update devices set key='"+std::to_string(key)+"' where name='"+data+"'";

        database.update(data);
        return 0;
    }


    struct sql_line_result gen_db::retrieve(string data)
    {

        dbs database;
        database.init();
     //  data="select * from devices where name='"+data+"' limit 1";
     //   cout << data<< "\r\n";
        return database.retrieve(data);
    }


     int gen_db::pull(string data, string type)
     {
     dbs database;
     struct sql_line_result res;
     database.init();
     data="select key from devices where name='"+data+"' and serial='"+type+"' limit 1";
     //cout << "query" << endl;
     res=gen_db::retrieve(data);
     //   cout << data<< "\r\n";
        if (res.num_rows > 0)        return std::stoi(res.col_result[0]);
        else  return -1;
     }


     int gen_db::push(string data, string type,int key)
     {

     dbs database;
     database.init();
     if(gen_db::pull(data,type)<0)
        { gen_db::insert(data,type);}
     else{  gen_db::update(data,type,key); }
      return 0;
      }
