#include "command.h"
#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;
   char* answer;
   string ans;

    //ctor
char* command::Options(){

     time_t now = time(0);

   // convert now to string form
         string dt = ctime(&now);
         ans= "Server: Apache\r\n"
          "MS-Server-ActiveSync: 14.00.0536.000\r\n"
          "MS-ASProtocolVersions: 2.0,2.1,2.5,12.0,12.1\r\n"
          "MS-ASProtocolCommands: Sync,SendMail,SmartForward,SmartReply,GetAttachment,GetHierarchy,"
          "CreateCollection,DeleteCollection,MoveCollection,FolderSync,FolderCreate,"
          "FolderDelete,FolderUpdate,MoveItems,GetItemEstimate,MeetingResponse,Search,"
          "Settings,Ping,ItemOperations,ResolveRecipients,ValidateCert\r\n"
          "Public: OPTIONS,POST\r\nDate: ";
          ans=ans+dt+"Content-Length: 0\r\n";
           return((char *)ans.c_str());
       }


char* command::Settings(){



          answer =(char*)"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
          "<!DOCTYPE AirSync PUBLIC \"-//AIRSYNC//DTD AirSync//EN\" "
          "<Settings xmlns=\"http://synce.org/formats/airsync_wm5/settings\">"
          "<Status>1</Status>"
          "<Oof>"
          "<Status/>"
          "<Get>"
          "<OofState>0</OofState>"
          "</Get>"
          "</Oof>"
          "</Settings>";



      return answer;


}

char* command::FolderSync(){


          answer =(char*)"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
          "<!DOCTYPE AirSync PUBLIC \"-//AIRSYNC//DTD AirSync//EN\" "
           "\"http://www.microsoft.com/\">"
                   "<FolderSync>"
                    "<Status>0</Status>"
                    "<SyncKey>0</SyncKey>"
                    "<Changes>"
                    "<Count>1</Count>"
                    "</Changes>"
                    "</FolderSync>";
      return answer;


}


char* command::Search(){

          answer =(char*)"<?xml version=\"1.0\"?>"
    "<!DOCTYPE AirSync PUBLIC \"-//AIRSYNC//DTD AirSync//EN\" \"http://www.microsoft.com/\">"
    "<Search xmlns=\"http://synce.org/formats/airsync_wm5/search\">"
    "<Status>1</Status>"
    "<Response>"
    "<Store>"
    "<Status>1</Status>"
    "<Result>"
    "<Class xmlns=\"http://synce.org/formats/airsync_wm5/airsync\">Calendar</Class>"
    "<LongId>RgAAAADi22n%2b5K6eSoH%2bdzl9mrUlBwAiJdrFeosuS5FQPukoeMhpAH7xbHCsAAAiJdrFeosuS5FQPukoeMhpAH7zrksUAAAP</LongId>"
    "<CollectionId xmlns=\"http://synce.org/formats/airsync_wm5/airsync\">3</CollectionId>"
    "<Properties>"
     "<Timezone xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">iP///0YATABFACAAUwB0AGEAbgBkAGEAcgBkACAAVABpAG0AZQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAoAAAAFAAQAAAAAAAAAAAAAAEYATABFACAARABhAHkAbABpAGcAaAB0ACAAVABpAG0AZQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAMAAAAFAAMAAAAAAAAAxP///w==</Timezone>"
     "<DtStamp xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">20201226T112208Z</DtStamp>"
     "<StartTime xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">20201226T090000Z</StartTime>"
     "<Subject xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">hfjjf</Subject>"
     "<UID xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">040000008200E00074C5B7101A82E00800000000F4BD10E469BEC901000000000000000010000000449579D4A72EED4EB3F70D04913F0277</UID>"
     "<OrganizerName xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">maemo</OrganizerName>"
     "<OrganizerEmail xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">maemo@test.local</OrganizerEmail>"
     "<Attendees xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">"
      "<Attendee>"
       "<Email>maemo@test.local</Email>"
       "<Name>maemo</Name>"
       "<AttendeeStatus>0</AttendeeStatus>"
       "<AttendeeType>1</AttendeeType>"
      "</Attendee>"
     "</Attendees>"
     "<Location xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">meetingroom  testi</Location>"
     "<EndTime xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">20090417T100000Z</EndTime>"
     "<Body xmlns=\"http://synce.org/formats/airsync_wm5/airsyncbase\">"
      "<Type>2</Type>"
      "<EstimatedDataSize>365</EstimatedDataSize>"
      "<Data>&lt;html&gt;&lt;head&gt;&lt;meta http-equiv=&quot;Content-Type&quot; content=&quot;text/html; charset=utf-8&quot;&gt;"
      "&lt;meta name=&quot;Generator&quot; content=&quot; Exchange Server&quot;&gt;"
        "&lt;!-- converted from text --&gt;"
    "&lt;style&gt;.EmailQuote { margin-left: 1pt; padding-left: 4pt; border-left: #800000 2px solid; }&lt;/style&gt;&lt;/head&gt;"
    "&lt;body&gt;"
    "&lt;font size=&quot;2&quot;&gt;&lt;div class=&quot;PlainText&quot;&gt;&amp;nbsp;&lt;/div&gt;&lt;/font&gt;"
    "&lt;/body&gt;"
    "&lt;/html&gt;</Data>"
     "</Body>"
     "<Sensitivity xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">0</Sensitivity>"
     "<BusyStatus xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">0</BusyStatus>"
     "<AllDayEvent xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">0</AllDayEvent>"
     "<Reminder xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">15</Reminder>"
     "<MeetingStatus xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">5</MeetingStatus>"
     "<NativeBodyType xmlns=\"http://synce.org/formats/airsync_wm5/airsyncbase\">1</NativeBodyType>"
    "</Properties>"
   "</Result>"
   "<Result>"
    "<Class xmlns=\"http://synce.org/formats/airsync_wm5/airsync\">Calendar</Class>"
    "<LongId>RgAAAADi22n%2b5K6eSoH%2bdzl9mrUlBwAiJdrFeosuS5FQPukoeMhpAH7xbHCsAAAiJdrFeosuS5FQPukoeMhpAH7zrksSAAAP</LongId>"
    "<CollectionId xmlns=\"http://synce.org/formats/airsync_wm5/airsync\">3</CollectionId>"
    "<Properties>"
     "<Timezone xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">iP///0YATABFACAAUwB0AGEAbgBkAGEAcgBkACAAVABpAG0AZQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAoAAAAFAAQAAAAAAAAAAAAAAEYATABFACAARABhAHkAbABpAGcAaAB0ACAAVABpAG0AZQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAMAAAAFAAMAAAAAAAAAxP///w==</Timezone>"
     "<DtStamp xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">20090417T105620Z</DtStamp>"
     "<StartTime xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">20090417T110000Z</StartTime>"
     "<Subject xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">tent</Subject>"
     "<UID xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">040000008200E00074C5B7101A82E008000000002E1A5BA069BEC901000000000000000010000000F1BB45467D72B44F822E9686F1D18ED4</UID>"
     "<OrganizerName xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">maemo</OrganizerName>"
     "<OrganizerEmail xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">maemo@test.local</OrganizerEmail>"
     "<Attendees xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">"
      "<Attendee>"
       "<Email>meetingroomtest@test.local</Email>"
       "<Name>meetingroom  testi</Name>"
       "<AttendeeStatus>0</AttendeeStatus>"
       "<AttendeeType>3</AttendeeType>"
      "</Attendee>"
      "<Attendee>"
       "<Email>maemo@test.local</Email>"
       "<Name>maemo</Name>"
       "<AttendeeStatus>0</AttendeeStatus>"
       "<AttendeeType>1</AttendeeType>"
      "</Attendee>"
     "</Attendees>"
     "<Location xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">meetingroom  testi</Location>"
     "<EndTime xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">20090417T120000Z</EndTime>"
     "<Body xmlns=\"http://synce.org/formats/airsync_wm5/airsyncbase\">"
      "<Type>2</Type>"
     " <EstimatedDataSize>365</EstimatedDataSize>"
      "<Data>&lt;html&gt;&lt;head&gt;&lt;meta http-equiv=&quot;Content-Type&quot; content=&quot;text/html; charset=utf-8&quot;&gt;"
   "&lt;meta name=&quot;Generator&quot; content=&quot;Microsoft Exchange Server&quot;&gt;"
    "&lt;!-- converted from text --&gt;"
    "&lt;style&gt;.EmailQuote { margin-left: 1pt; padding-left: 4pt; border-left: #800000 2px solid; }&lt;/style&gt;&lt;/head&gt;"
    "&lt;body&gt;"
    "&lt;font size=&quot;2&quot;&gt;&lt;div class=&quot;PlainText&quot;&gt;&amp;nbsp;&lt;/div&gt;&lt;/font&gt;"
     "&lt;/body&gt;"
      "&lt;/html&gt;</Data>"
     "</Body>"
     "<Sensitivity xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">0</Sensitivity>"
     "<BusyStatus xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">0</BusyStatus>"
     "<AllDayEvent xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">0</AllDayEvent>"
     "<Reminder xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">15</Reminder>"
     "<MeetingStatus xmlns=\"http://synce.org/formats/airsync_wm5/calendar\">5</MeetingStatus>"
     "<NativeBodyType xmlns=\"http://synce.org/formats/airsync_wm5/airsyncbase\">1</NativeBodyType>"
    "</Properties>"
   "</Result>"
   "<Range>0-1</Range>"
   "<Total>19</Total>"
  "</Store>"
  "</Response>"
   "</Search>";




       //     cout << answer <<"\n";
      return answer;


}

