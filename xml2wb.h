#include <wbxml.h>

struct wbpair {
WB_LONG len;
WB_UTINY *str;
} ;

wbpair  xml2wb( unsigned char* );

