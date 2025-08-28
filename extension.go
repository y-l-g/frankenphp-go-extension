package frankenext

/*
#include <php.h>
*/
import "C"
import (
	"strings"
	"unsafe"
	"github.com/dunglas/frankenphp"
)

//export_php:function string_joiner(string $base, string $separator, int $count): string
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
