
#include <string>
using namespace std;
class gen_db{


 public:
    gen_db();
    int insert(string data, string serial);
    int update(string data,string type,int key);
    int push(string data,string type,int key);
    int pull(string data,string type);
    struct sql_line_result retrieve(string data);



};
