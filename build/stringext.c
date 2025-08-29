#include <php.h>
#include <Zend/zend_API.h>
#include <Zend/zend_hash.h>
#include <Zend/zend_types.h>
#include <stddef.h>

#include "stringext.h"
#include "stringext_arginfo.h"
#include "_cgo_export.h"


PHP_MINIT_FUNCTION(stringext) {
    
    return SUCCESS;
}

zend_module_entry stringext_module_entry = {STANDARD_MODULE_HEADER,
                                         "stringext",
                                         ext_functions,             /* Functions */
                                         PHP_MINIT(stringext),  /* MINIT */
                                         NULL,                      /* MSHUTDOWN */
                                         NULL,                      /* RINIT */
                                         NULL,                      /* RSHUTDOWN */
                                         NULL,                      /* MINFO */
                                         "1.0.0",                   /* Version */
                                         STANDARD_MODULE_PROPERTIES};

PHP_FUNCTION(repeat_this)
{
    zend_string *str = NULL;
    zend_long count = 0;
    zend_bool reverse = 0;
    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_STR(str)
        Z_PARAM_LONG(count)
        Z_PARAM_BOOL(reverse)
    ZEND_PARSE_PARAMETERS_END();
    zend_string *result = repeat_this(str, (long) count, (int) reverse);
    if (result) {
        RETURN_STR(result);
    }

	RETURN_EMPTY_STRING();
}

