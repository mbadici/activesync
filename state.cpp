#include "state.h"
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;


int state::rd(char *device,char *key){
     ifstream file("/home/mihai/projects/activesync/activesync/state");
     if (file.is_open()) {
                            char devandkey[255];
                            strcpy(devandkey,device);
                            strcat(devandkey," ");
                            strcat(devandkey,key);
                            string line;
                            int i;
                            while (getline(file, line)) {
                            size_t found = line.find(device);
                            if (found != string::npos)
                            {
                                sscanf(line.c_str(),"%*s%*s%d", &i);
                                file.close();
                                return i;

                            }

                            file.close();
                            return -1;

                          }

     }
   return -2;
}

int state::wr(char *device,char *keyname, int key){

 fstream rfile("/home/mihai/projects/activesync/activesync/state",std::ios::out | std::ios::app);
 fstream tmpfile("/home/mihai/projects/activesync/activesync/state.tmp",std::ios::out | std::ios::app);
char devandkey[255];
strcpy(devandkey,device);
strcat(devandkey," ");
strcat(devandkey,keyname);
if (rfile.is_open()) {
                            string line;
                            int i=0;
                            while ( getline(rfile,line)) {
                            size_t found = line.find(devandkey);
                            if (found != string::npos) {

                            i=1;
                            line.assign(devandkey);
                            line = line+" "+std::to_string(key);

                            tmpfile << line << endl;
                            }
                            else {
                                    tmpfile << line <<endl;

                            }
                          }
                        if(i==0){
                                    line.assign(device);
                                    line.append(" ");
                                    line.append(keyname);
                                    line = line+" "+std::to_string(key);
                                    ofstream rfile("/home/mihai/projects/activesync/activesync/state",ios::app);
                                    rfile << line << endl;
                                    rfile.close(); tmpfile.close();
                        }
                        else {
                                rfile.close(); tmpfile.close();
                                rename("/home/mihai/projects/activesync/activesync/state.tmp","/home/mihai/projects/activesync/activesync/state");
     }                  }
   return -2;

}
