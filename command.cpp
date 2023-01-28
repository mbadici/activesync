#include "command.h"
#include <stdio.h>
#include <iostream>
#include <ctime>
#include "state.h"
#include "../rapidxml-1.13/rapidxml.hpp"
#include "logging.h"
//#include "../rapidxml/writer.h"
//#include "../rapidxml/stringbuffer.h"
using namespace std;
using namespace rapidxml;
unsigned   char* answer;

   string ans;
    state db;
    //ctor
unsigned char* command::Header(){
             answer=(unsigned char*) "Server: Apache\r\n"
             "MS-ASProtocolCommands: Sync,SendMail,SmartForward,SmartReply,GetAttachment,GetHierarchy,"
          "CreateCollection,DeleteCollection,MoveCollection,FolderSync,FolderCreate,"
          "FolderDelete,FolderUpdate,MoveItems,GetItemEstimate,MeetingResponse,Search,"
          "Settings,Ping,ItemOperations,ResolveRecipients,ValidateCert\r\n"
        "MS-Server-ActiveSync: 12.1\r\n";
 //       answer="";
           return answer;
}

unsigned char* command::Options(){

     time_t now = time(0);

   // convert now to string form
         string dt = ctime(&now);
         ans="";
         ans= "Server: Apache\r\n"
          "MS-Server-ActiveSync: 14.00.0536.000\r\n"
          "MS-ASProtocolVersions: 2.0,2.1,2.5,12.0,12.1\r\n"
          "MS-ASProtocolCommands: Sync,SendMail,SmartForward,SmartReply,GetAttachment,GetHierarchy,"
          "CreateCollection,DeleteCollection,MoveCollection,FolderSync,FolderCreate,"
          "FolderDelete,FolderUpdate,MoveItems,GetItemEstimate,MeetingResponse,Search,"
          "Settings,Ping,ItemOperations,ResolveRecipients,ValidateCert\r\n"
          "Public: OPTIONS,POST\r\n"
          "Content-type: text/html; charset=UTF-8\r\nDate:";
          ans=ans+dt+
          "Content-Length: 0\r\n";
           return((unsigned char *)ans.c_str());
          // return answer;
       }


unsigned char* command::Settings(){



          answer =(unsigned char*)"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
          "<!DOCTYPE AirSync PUBLIC \"-//AIRSYNC//DTD AirSync//EN\"  \"http://www.microsoft.com/\">"
          "<Settings xmlns=\"http://synce.org/formats/airsync_wm5/settings\">"
          "<Status>1</Status>"
          "<Oof>"
          "<Get>"
          "<OofState>0</OofState>"
          "</Get>"
          "</Oof>"
          "</Settings>";



      return answer;


}

   unsigned char* command::Provision(){



          answer =(unsigned char*)"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
          "<!DOCTYPE AirSync PUBLIC \"-//AIRSYNC//DTD AirSync//EN\"  \"http://www.microsoft.com/\">"
          "<Provision xmlns=\"uri:Provision\" xmlns:Settings=\"uri:Settings\">"
          "<DeviceInformation xmlns=\"uri:Settings\">"
           "<Set>"
           "<Model>SM-M215F</Model>"
           "<FriendlyName>SM-M215F</FriendlyName>"
           "<OS>Android 10</OS>"
           "<UserAgent>Android-Mail/2020.11.29.346182102.Release</UserAgent>"
           "</Set>"
           "</DeviceInformation>"
           "<Policies>"
           "<Policy>"
           "<PolicyType>MS-EAS-Provisioning-WBXML</PolicyType>"
           "</Policy>"
           "</Policies>"
           "</Provision>";
 as_log((char*)answer);

      return answer;


}



unsigned char* command::FolderSync(char* device, char* xml){
      int key=0;
      int count=3;
      as_log("passed xml:");
      as_log((char*)xml);
      as_log("end xml");
xml_document<>doc;    // character type defaults to char
doc.parse<0> (xml);    // 0 means default parse flags
    rapidxml::xml_node<> *root = doc.first_node("FolderSync");
   rapidxml::xml_node<> *child = root->first_node("SyncKey");
  as_log(child->value());
  key=atoi(child->value());
   string add="";


      if((key==0) )
       {
           //first sync


       //create the folder structure list (should be read from mailbox)

       add="<Add>"
      "<ServerId>Calendar</ServerId>"
      "<ParentId>0</ParentId>"
      "<DisplayName>Calendar</DisplayName>"
      "<Type>8</Type>"
      "</Add>"
       "<Add>"
      "<ServerId>Inbox</ServerId>"
      "<ParentId>0</ParentId>"
      "<DisplayName>Inbox</DisplayName>"
      "<Type>2</Type>"
    "</Add>"
    "<Add>"
      "<ServerId>Notes::Syncroton</ServerId>"
      "<ParentId>0</ParentId>"
      "<DisplayName>Notes</DisplayName>"
      "<Type>10</Type>"
      "</Add>";


           //already sinced
 //      if(key==0)


         //key++;
         db.push(device,"FolderSync",key);



           ans= "<?xml version=\"1.0\" encoding=\"utf-8\"?>"
           "<!DOCTYPE ActiveSync PUBLIC \"-//MICROSOFT//DTD ActiveSync//EN\" \"http://www.microsoft.com/\">"
       "<FolderSync xmlns=\"uri:FolderHierarchy\" >"
       "<Status>1</Status>"
       "<SyncKey>1</SyncKey>"
       "<Changes>"
       "<Count>2</Count>"
       "<Add>"
       "<ServerId>Calendar</ServerId>"
       "<ParentId>0</ParentId>"
      "<DisplayName>Calendar</DisplayName>"
       "<Type>8</Type>"
       "</Add>"
       "<Add>"
       "<ServerId>Inbox</ServerId>"
       "<ParentId>0</ParentId>"
       "<DisplayName>Inbox</DisplayName>"
       "<Type>2</Type>"
       "</Add>"

       "</Changes>"

       "</FolderSync>";
}
else{
        {  count=0; add="";
         ans="";
  key=1;
         db.push(device,"FolderSync",key);

        ans= ans+ "<?xml version=\"1.0\" encoding=\"utf-8\"?>"
          "<!DOCTYPE ActiveSync PUBLIC \"-//AIRSYNC//DTD AirSync//EN\" \"http://www.microsoft.com/\">"
  "<FolderSync xmlns=\"uri:FolderHierarchy\" xmlns:Syncroton=\"uri:Syncroton\" xmlns:Internal=\"uri:Internal\" >"
  "<Status>'1'</Status>"
      "<SyncKey>'"+to_string(key)+"'</SyncKey>"
      "<Changes>"
      "<Count>0</Count>"

    "</Changes>"

   "</FolderSync>";


}
}

      return ((unsigned char*)ans.c_str());


}


unsigned char* command::Sync(char* device,  unsigned char* poststring){

     answer =(unsigned char*)"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
        "<!DOCTYPE AirSync PUBLIC \"-//AIRSYNC//DTD AirSync//EN\"  \"http://www.microsoft.com/\">"
  "<Sync>"
    "    <Collections>"
    "  <Collection>"
    "   <Class>Email</Class>"
    "  <SyncKey>1</SyncKey>"
    " <CollectionId>Inbox</CollectionId>"
    " <Status>1</Status>"
    " </Collection>"
    " </Collections>"
   "</Sync>";

      return answer;




}



unsigned char* command::Search(char* device, unsigned char* poststring){



 answer =(unsigned char*) "<?xml version=\"1.0\" encoding=\"utf-8\"?>"
        "<!DOCTYPE AirSync PUBLIC \"-//AIRSYNC//DTD AirSync//EN\"  \"http://www.microsoft.com/\">"

    "<Search xmlns=\"http://synce.org/formats/airsync_wm5/search\">"
    "<Status>1</Status>"
    "<Response>"
    "<Store>"
    "<Status>1</Status>"
    "<Result>"
      "<Class xmlns=\"http://synce.org/formats/airsync_wm5/airsync\">Contacts</Class>"
  //  "<LongId>RgAAAADi22n%2b5K6eSoH%2bdzl9mrUlBwAiJdrFeosuS5FQPukoeMhpAH7xbHCsAAAiJdrFeosuS5FQPukoeMhpAH7zrksSAAAP</LongId>"
    "<CollectionId xmlns=\"http://synce.org/formats/airsync_wm5/airsync\">3 </CollectionId>"
    "<Properties>"
    "<displayname> costel </displayname>"
    "</Properties>"
    "</Result>"
 "<Total>1</Total>"
  "</Store>"
  "</Response>"
   "</Search>";
     as_log( (char*) answer);
      return answer;


}


unsigned char* command::Sendmail(){

answer = (unsigned char*) "s\r\n";
return answer;


}
