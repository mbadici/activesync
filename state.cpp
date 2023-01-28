#include "state.h"
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include "include/gen_db.h"
#include "logging.h"
//#include "include/sqlite_db.h"
using namespace std;

gen_db status;

int state::pull(string device,string keyname){


    int i;
    int res;
	res=status.pull(device,keyname);
 //   istringstream(res.col_result[1]) >>i;

    return res;

    }

int state::push(string device,string keyname, int key){
    string pSQL;

     status.push(device,keyname,key);

            return 0;


	}

