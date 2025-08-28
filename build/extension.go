package extension

/*
#include <stdlib.h>
#include "extension.h"
*/
import "C"
import "runtime/cgo"
import "strings"
import "unsafe"
import "github.com/dunglas/frankenphp"

func init() {
	frankenphp.RegisterExtension(unsafe.Pointer(&C.ext_module_entry))
}


//export string_joiner
func string_joiner(base *C.zend_string, separator *C.zend_string, count int64) unsafe.Pointer {
	goBase := frankenphp.GoString(unsafe.Pointer(base))
	goSeparator := frankenphp.GoString(unsafe.Pointer(separator))
	var builder strings.Builder
	for i := 0; i < int(count); i++ {
		builder.WriteString(goBase)
		if i < int(count)-1 {
			builder.WriteString(goSeparator)
		}
	}
	result := builder.String()
	return frankenphp.PHPString(result, false)
}

