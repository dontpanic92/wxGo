package wx

import "reflect"

//type EventCallbackFunc func(Event)

func func_pointer_is_equal(f1 interface{}, f2 interface{}) bool{
	return (reflect.ValueOf(f1).Pointer() == reflect.ValueOf(f2).Pointer())
}
