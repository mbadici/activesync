#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void as_log(char* logstring)
{
    ofstream logfile;
  logfile.open ("/home/mihai/projects/activesync/activesync/log", std::ios::out | std::ios::app);
if(logstring !=NULL)
    {

    logfile<< logstring;
     }
else{ logfile <<"null string"; }
  logfile <<"\n";

}




void as_log_data(char* logstring, int len)
//log to "log" file for debugging purposes
{
    int i;
ofstream logfile;
  logfile.open ("/home/mihai/projects/activesync/activesync/datalog", std::ios::app);

  if(logstring !=NULL)
    {
    //count=strlen(logstring);

   for(i=0;i<=len;i++){
    logfile.write(&logstring[i],sizeof(char));
    }
  }
  else{ logfile <<"null string";}


  logfile.close();

}
