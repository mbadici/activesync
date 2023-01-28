#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED
#include <string>
using namespace std;
class state {
    public:
            int pull(string device,string type);
            int push (string device, string type, int key );


};


#endif // STATE_H_INCLUDED
