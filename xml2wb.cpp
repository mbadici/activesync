
//

#include <iostream>
#include "logging.h"
#include "/usr/local/include/libwbxml-1.0/wbxml/wbxml_conv.h"
#include "xml2wb.h"
#define WBXML_SUPPORT_AIRSYNC
using namespace std;
//struct wbpair {
//int len;
//WB_UTINY *str;
//} ;

struct WBXMLConvWBXML2XML_s {
    WBXMLGenXMLType gen_type;    /**< WBXML_GEN_XML_COMPACT | WBXML_GEN_XML_INDENT | WBXML_GEN_XML_CANONICAL (Default: WBXML_GEN_XML_INDENT) */
    WBXMLLanguage lang;          /**< Force document Language (overwrite document Public ID) */
    WBXMLCharsetMIBEnum charset; /**< Set document Language (does not overwrite document character set) */
    WB_UTINY indent;             /**< Indentation Delta, when using WBXML_GEN_XML_INDENT Generation Type (Default: 0) */
    WB_BOOL keep_ignorable_ws;   /**< Keep Ignorable Whitespaces (Default: FALSE) */
};

struct WBXMLConvXML2WBXML_s {
    WBXMLVersion wbxml_version; /**< WBXML Version */
    WB_BOOL keep_ignorable_ws;  /**< Keep Ignorable Whitespaces (Default: FALSE) */
    WB_BOOL use_strtbl;         /**< Generate String Table (Default: TRUE) */
    WB_BOOL produce_anonymous;  /**< Produce an anonymous document (Default: FALSE) */
};

wbpair xml2wb(unsigned char* answer)
{

WB_LONG count = 0;
unsigned int total = 0;
 WBXMLError ret = WBXML_OK;

wbpair xml2wb;
WBXMLConvXML2WBXML *conv = NULL;
total += strlen((const char*)answer);

   ret = wbxml_conv_xml2wbxml_create(&conv);
    if (ret != WBXML_OK)
    {
        fprintf(stderr, "xml2wbxml failed: %s\n", wbxml_errors_string(ret));
    }


 WB_ULONG wbxml_len = 0;
  wbxml_conv_xml2wbxml_disable_public_id(conv);

 // wbxml_conv_xml2wbxml_enable_string_table(conv);
//  wbxml_conv_xml2wbxml_enable_preserve_whitespaces(conv);


 ret = wbxml_conv_xml2wbxml_run(conv, answer, total, &xml2wb.str,
(unsigned int*)  &xml2wb.len);
    if (ret != WBXML_OK) {
        fprintf(stderr, "xml2wbxml failed: %s\n", wbxml_errors_string(ret));









          }
            else {
                  //cout << "Content-Length:" <<xml_len<<"\r\n";
                   //cout << "\r\n";
               //   if (fwrite(wbxml, sizeof(WB_UTINY), wbxml_len, stdout) < wbxml_len)
               //   fprintf(stderr, "Error while writing to file: %s\n", "stdout");


          //      xml2wb.len= wbxml_len;

                as_log_data((char*)xml2wb.str,xml2wb.len);
                return(xml2wb);
                }

};
