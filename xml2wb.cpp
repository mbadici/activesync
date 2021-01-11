
#include <wbxml.h>
#include <wbxml_conv.h>

unsigned char* xml2wb(char* answer)
{
WBXMLParser *wbxml_parser = NULL;
    WB_UTINY *wbxml = NULL, *xml=NULL;
    WB_ULONG  wbxml_len = 0;
    WB_LONG  xml_len = 0, total = 0;
    WBXMLError ret = WBXML_OK;
    WBXMLGenWBXMLParams params;

    /* Init Default Parameters */
    params.wbxml_version = WBXML_VERSION_13;
    params.use_strtbl = TRUE;
    params.keep_ignorable_ws = TRUE;


      total += strlen(answer);
            xml = (unsigned char*) wbxml_realloc(xml, total);
            xml_len=total;
           // xml[xml_len] = '\0';
            ret=wbxml_conv_xml2wbxml_withlen((unsigned char*) answer, xml_len, &wbxml, &wbxml_len, &params);
            if (ret != WBXML_OK) {
                                   fprintf(stderr, "xml2wbxml failed: %s\n", wbxml_errors_string(ret));
                                    }
            else {
                  if (fwrite(wbxml, sizeof(WB_UTINY), wbxml_len, stdout) < wbxml_len)
                  fprintf(stderr, "Error while writing to file: %s\n", "stdout");

                }

                return(wbxml);
};
