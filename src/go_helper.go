package wx

import "reflect"

func func_pointers_are_equal(f1 interface{}, f2 interface{}) bool{
	return (reflect.ValueOf(f1).Pointer() == reflect.ValueOf(f2).Pointer())
}
