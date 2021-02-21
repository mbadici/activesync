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
#include "logging.h"
#define DEBUGLOG
using namespace std;



char *answ( char *cmd, char* deviceid,char* xml)

//try to implement a switch/case to invoke the comand

{



    command req;
    if(!strcmp(cmd,"FolderSync")) return req.FolderSync(deviceid, xml);
     if(!strcmp(cmd,"Search")) return req.Search();
     if(!strcmp(cmd,"Settings")) return req.Settings();
     if(!strcmp(cmd,"Options")) return req.Options();
     if(!strcmp(cmd,"Provision")) return req.Provision();
     if(!strcmp(cmd,"Header")) return req.Header();

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
char *xml;
cmd=(char*)malloc(sizeof(char*));
char *amethod;
wbpair response;
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

cout << answ("Options", deviceid,NULL)<<"\r\n";

as_log(answ("Options",deviceid,NULL));

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


// as_log_data((char*) poststring);
xml=(char*) wb2xml(poststring,count);
as_log(xml);

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

as_log("answer:");
//log the answer as xml
as_log(answ(cmd,deviceid,xml));
cout<< answ("Header",deviceid,xml);
response= xml2wb(answ(cmd,deviceid,xml));
cout << "Content-Length: " << response.len <<"\r\n";
cout << "Content-type: application/vnd.ms-sync.wbxml\r\n" ;
cout <<"\r\n";

fwrite(response.str, sizeof(WB_UTINY), response.len, stdout);
cout <<"\r\n";

//if(!strcmp(cmd,"FolderSync"))
    {
    as_log_data((char *)response.str,response.len);
    }
}
}
}

}
