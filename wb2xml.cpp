#include "/usr/local/include/libwbxml-1.0/wbxml/wbxml.h"
//nclude "/usr/local/include/
//#include <wbxml_charset.h>
#include <stdio.h>
#define INPUT_BUFFER_SIZE 1000
static WBXMLLanguage get_lang(const WB_TINY *lang)
{
//#if defined( WBXML_SUPPORT_WML )
    if (WBXML_STRCMP(lang, "WML10") == 0)
        return WBXML_LANG_WML10;
    if (WBXML_STRCMP(lang, "WML11") == 0)
        return WBXML_LANG_WML11;
    if (WBXML_STRCMP(lang, "WML12") == 0)
        return WBXML_LANG_WML12;
    if (WBXML_STRCMP(lang, "WML13") == 0)
        return WBXML_LANG_WML13;
//#endif /* WBXML_SUPPORT_WML */

//#if defined( WBXML_SUPPORT_WTA )
    if (WBXML_STRCMP(lang, "WTA10") == 0)
        return WBXML_LANG_WTA10;
    if (WBXML_STRCMP(lang, "WTAWML12") == 0)
        return WBXML_LANG_WTAWML12;
    if (WBXML_STRCMP(lang, "CHANNEL11") == 0)
        return WBXML_LANG_CHANNEL11;
    if (WBXML_STRCMP(lang, "CHANNEL12") == 0)
        return WBXML_LANG_CHANNEL12;
//#endif /* WBXML_SUPPORT_WTA */

//#if defined( WBXML_SUPPORT_SI )
    if (WBXML_STRCMP(lang, "SI10") == 0)
        return WBXML_LANG_SI10;
//#endif /* WBXML_SUPPORT_SI */

//#if defined( WBXML_SUPPORT_SL )
    if (WBXML_STRCMP(lang, "SL10") == 0)
        return WBXML_LANG_SL10;
//#endif /* WBXML_SUPPORT_SL */

//#if defined( WBXML_SUPPORT_CO )
    if (WBXML_STRCMP(lang, "CO10") == 0)
        return WBXML_LANG_CO10;
//#endif /* WBXML_SUPPORT_CO */

//#if defined( WBXML_SUPPORT_PROV )
    if (WBXML_STRCMP(lang, "PROV10") == 0)
        return WBXML_LANG_PROV10;
//#endif /* WBXML_SUPPORT_PROV */

//#if defined( WBXML_SUPPORT_EMN )
    if (WBXML_STRCMP(lang, "EMN10") == 0)
        return WBXML_LANG_EMN10;
//#endif /* WBXML_SUPPORT_EMN */

//#if defined( WBXML_SUPPORT_DRMREL )
    if (WBXML_STRCMP(lang, "DRMREL10") == 0)
        return WBXML_LANG_DRMREL10;
//#endif /* WBXML_SUPPORT_DRMREL */

//#if defined( WBXML_SUPPORT_OTA_SETTINGS )
    if (WBXML_STRCMP(lang, "OTA") == 0)
        return WBXML_LANG_OTA_SETTINGS;
//#endif /* WBXML_SUPPORT_OTA_SETTINGS */

//#if defined( WBXML_SUPPORT_SYNCML )
    if (WBXML_STRCMP(lang, "SYNCML10") == 0)
        return WBXML_LANG_SYNCML_SYNCML10;
    if (WBXML_STRCMP(lang, "DEVINF10") == 0)
        return WBXML_LANG_SYNCML_DEVINF10;
    if (WBXML_STRCMP(lang, "SYNCML11") == 0)
        return WBXML_LANG_SYNCML_SYNCML11;
    if (WBXML_STRCMP(lang, "DEVINF11") == 0)
        return WBXML_LANG_SYNCML_DEVINF11;
    if (WBXML_STRCMP(lang, "METINF11") == 0)
        return WBXML_LANG_SYNCML_METINF11;
    if (WBXML_STRCMP(lang, "SYNCML12") == 0)
        return WBXML_LANG_SYNCML_SYNCML12;
    if (WBXML_STRCMP(lang, "DEVINF12") == 0)
        return WBXML_LANG_SYNCML_DEVINF12;
    if (WBXML_STRCMP(lang, "METINF12") == 0)
        return WBXML_LANG_SYNCML_METINF12;
    if (WBXML_STRCMP(lang, "DMDDF12") == 0)
        return WBXML_LANG_SYNCML_DMDDF12;
//#endif /* WBXML_SUPPORT_SYNCML */

//#if defined( WBXML_SUPPORT_WV )
    if (WBXML_STRCMP(lang, "CSP11") == 0)
        return WBXML_LANG_WV_CSP11;
    if (WBXML_STRCMP(lang, "CSP12") == 0)
        return WBXML_LANG_WV_CSP12;
//#endif /* WBXML_SUPPORT_WV */

//#if defined( WBXML_SUPPORT_AIRSYNC )
    if (WBXML_STRCMP(lang, "AIRSYNC") == 0)
        return WBXML_LANG_AIRSYNC;
//#endif /* WBXML_SUPPORT_AIRSYNC */

    return WBXML_LANG_UNKNOWN;
}



unsigned char* wb2xml(WB_UTINY *wb, int wbxml_len){

   WB_UTINY *wbxml = NULL, *output = NULL, *xml = NULL;
    WB_LONG count = 0, total = 0;
    WB_ULONG xml_len = 1;

    WBXMLError ret = WBXML_OK;
    WB_UTINY input_buffer[INPUT_BUFFER_SIZE + 1];
    WBXMLConvWBXML2XML *conv = NULL;

    ret = wbxml_conv_wbxml2xml_create(&conv);
    if (ret != WBXML_OK)
    {
     fprintf(stderr, "conv  failed: %s\n", wbxml_errors_string(ret));
      exit;
    }
     wbxml_conv_wbxml2xml_enable_preserve_whitespaces(conv);
     wbxml_conv_wbxml2xml_set_language(conv, WBXML_LANG_ACTIVESYNC);
     wbxml_conv_wbxml2xml_set_gen_type(conv, WBXML_GEN_XML_CANONICAL);

wbxml_conv_wbxml2xml_set_charset(conv, WBXML_CHARSET_UTF_8);

      ret = wbxml_conv_wbxml2xml_run(conv,(unsigned char*) wb, (WB_LONG)wbxml_len, &xml, &xml_len);
    if (ret != WBXML_OK) {

     fprintf(stderr, "wbxml2xml failed: %s\n", wbxml_errors_string(ret));

        }

    else {
        /* fprintf(stderr, "wbxml2xml succeded: \n%s\n", xml); */
     //   fprintf(stderr, "wbxml2xml succeded\n");

        return xml;
    }
}
