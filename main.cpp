#include <iostream>
#include <string>
#include <fstream>
#include <curl/curl.h>
#include <string.h>
#include <stdio.h>
#include "auth.h"
#include "xml2wb.h"
#include "wb2xml.h"
#include "command.h"
#include <wbxml.h>

#define DEBUGLOG
using namespace std;
void as_log(char* logstring)
{
    ofstream logfile;
  logfile.open ("/home/mihai/projects/activesync/activesync/log", std::ios::app);
if(logstring !=NULL)
    {

    logfile<< logstring;
     }
else{ logfile <<"null string"; }
  logfile <<"\n";

}

void as_log_data(char* logstring)
//log to "log" file for debugging purposes
{
    int i,count;
ofstream logfile;
  logfile.open ("/home/mihai/projects/activesync/activesync/datalog", std::ios::app);

  if(logstring !=NULL)
    {
    //count=strlen(logstring);
   count=200;
   for(i=0;i<count;i++){
    logfile.write(&logstring[i],sizeof(char));
    }
  }
  else{ logfile <<"null string";}
  logfile.write("\n",2);

  logfile.close();

}

char *answ( char *cmd)

//try to implement a switch/case to invoke the comand

{


    command req;
    if(!strcmp(cmd,"FolderSync")) return req.FolderSync();
     if(!strcmp(cmd,"Search")) return req.Search();
     if(!strcmp(cmd,"Settings")) return req.Settings();
     if(!strcmp(cmd,"Options")) return req.Options();

     return "no";
}



extern char **environ;
int main()
{
char *len_;
int len,count;
char *postdata;
char *cmd;
char *deviceid;
char *username;
cmd=(char*)malloc(sizeof(char*));
char *amethod, *response;
WB_UTINY* poststring;
const string ENV[ 24 ] = {
   "COMSPEC", "DOCUMENT_ROOT", "GATEWAY_INTERFACE",
   "HTTP_ACCEPT", "HTTP_ACCEPT_ENCODING",
   "HTTP_ACCEPT_LANGUAGE", "HTTP_CONNECTION",
   "HTTP_HOST", "HTTP_USER_AGENT", "PATH",
   "QUERY_STRING", "REMOTE_ADDR", "REMOTE_PORT",
   "REQUEST_METHOD", "REQUEST_URI", "SCRIPT_FILENAME",
   "SCRIPT_NAME", "SERVER_ADDR", "SERVER_ADMIN",
   "SERVER_NAME","SERVER_PORT","SERVER_PROTOCOL",
   "SERVER_SIGNATURE","SERVER_SOFTWARE" };
postdata=getenv("HTTP_AUTHORIZATION");

/*if(postdata == NULL)
{
    cout << "Status:401 Unauthorized\n" ;
    cout << "WWW-Authenticate: Basic realm=\"activesync\"\n" ;
    cout << "Content-type: text/html\n" ;
    cout << "\n";
}

else
*/

{


 postdata=getenv("HTTP_AUTHORIZATION");
 #ifdef DEBUGLOG
 as_log(postdata);
 #endif
 imap_auth(postdata);


amethod=getenv("REQUEST_METHOD");
if(amethod==NULL) amethod="OPTIONS";
#ifdef DEBUGLOG
as_log(amethod);
#endif // DEBUGLOG
if( !strcmp(amethod,"OPTIONS"))
{
    postdata=getenv("QUERY_STRING");
#ifdef DEBUGLOG
    as_log(postdata);
#endif // DEBUGLOG

        for ( int i = 0; i < 24; i++ ) {
         as_log( getenv(ENV[i ].c_str()) );
        }

// there are only headers here, no body
cout << "Content-type: text/html\r\n" ;
cout << answ("Options");
cout <<"\r\n";
}

else{
if( !strcmp(amethod,"POST"))
{
         for ( int i = 0; i < 24; i++ ) {
                as_log( getenv(ENV[i ].c_str()) );
         }

         len_ = getenv("CONTENT_LENGTH");
         if(len_){
                as_log(len_);
                len = strtol(len_, NULL, 10);
         }

 poststring= (WB_UTINY*) malloc(len+1);


 for(count=0;count<len;count++){

 poststring[count]=fgetc(stdin);
 }
 count++;
poststring[count]='\0';


 as_log_data((char*) poststring);

as_log((char*)wb2xml(poststring,count));
//strcpy(postdata,"j-//AIRSYNC//DTD AirSync//ENVN1K2NW1\0");
//as_log((char*)wb2xml((unsigned char*)postdata));

 postdata=getenv("QUERY_STRING");
#ifdef DEBUGLOG
    as_log(postdata);
#endif // DEBUGLOG
  char *tokenname,*tokenvalue;
//parse POST string
    while ((tokenname = strtok_r(postdata, "=", &postdata)))
    {
#ifdef DEBUGLOG
//     as_log(tokenname);
#endif
     tokenvalue = strtok_r(postdata, "&", &postdata);
        if(!strcmp(tokenname,"Cmd")) {cmd=tokenvalue; }
        if(!strcmp(tokenname,"User")) username=tokenvalue;
        if(!strcmp(tokenname,"DeviceId")) deviceid=tokenvalue;
    }
#ifdef DEBUGLOG
as_log(deviceid);
as_log(username);
as_log(cmd);
#endif // DEBUGLOG

//cout << "Status:200 OK\n" ;
cout << "Content-type: text/vnd.ms-sync.wbxml\n" ;
cout <<"\r\n";
response=answ(cmd);
as_log(response);
cout << xml2wb(response);
cout <<"\n";
}
}
}

}
