#include <php.h>
#include <Zend/zend_API.h>
#include <Zend/zend_hash.h>
#include <Zend/zend_types.h>
#include <stddef.h>

#include "extension.h"
#include "extension_arginfo.h"
#include "_cgo_export.h"


PHP_MINIT_FUNCTION(extension) {
    
    return SUCCESS;
}

zend_module_entry extension_module_entry = {STANDARD_MODULE_HEADER,
                                         "extension",
                                         ext_functions,             /* Functions */
                                         PHP_MINIT(extension),  /* MINIT */
                                         NULL,                      /* MSHUTDOWN */
                                         NULL,                      /* RINIT */
                                         NULL,                      /* RSHUTDOWN */
                                         NULL,                      /* MINFO */
                                         "1.0.0",                   /* Version */
                                         STANDARD_MODULE_PROPERTIES};

PHP_FUNCTION(string_joiner)
{
    zend_string *base = NULL;
    zend_string *separator = NULL;
    zend_long count = 0;
    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_STR(base)
        Z_PARAM_STR(separator)
        Z_PARAM_LONG(count)
    ZEND_PARSE_PARAMETERS_END();
    zend_string *result = string_joiner(base, separator, (long) count);
    if (result) {
        RETURN_STR(result);
    }

	RETURN_EMPTY_STRING();
}

