#ifndef SQLITE_DB_H
#define SQLITE_DB_H
#include <sqlite3.h>
#include <string>
using namespace std;

struct sql_line_result{
      int num_rows;
      string col_result[10];
};

class dbs {

    private: static sqlite3 *handle;
            int query(string data,  bool mode);
    public: int init();
           int insert(string data);
           int update(string data);
           struct sql_line_result retrieve(string data);
};

#endif // SQLITE_DB_H
