wxGo
====

Golang wxWidgets Wrapper

Note
----

**About the package**

- Currently wxWidgets is statically linked into wxGo and for convenience (go build-able) a pre-compiled version of wxWidgets is used
- To use your customized version of wxWidgets, please modify `src/define.i` where the `CPPFLAGS` and `LDFALGS` are
- Only linux_amd64 supported and tested now

**About the memory management**

All `NewXXX` functions will allocate memory on C++ side, thus it will not be tracked by Go's garbage collector. However, when a `wxWindow` (or its subclasses) being deleted , it will automatically delete all of its children.

When we click the close botton of a `wxFrame`, by default the `Destroy` will be called and it will be deleted by itself (and also all children). But when we close a `wxDialog`, the `Destroy` won't be called and we have to manually destroy it.

There are also some classes that are not in the GUI hierachy. For these classes, we have to free the memory by calling `DeleteXXX`. 

More Info: 

- [SWIG Manual](http://www.swig.org/Doc3.0/Go.html#Go_class_memory)
- [wxWidgets Manual](http://docs.wxwidgets.org/3.0/overview_windowdeletion.html)

Usage
----

```
go get github.com/dontpanic92/wxGo
```

You can add `-x` option to print each command it executes. Then

```
import "github.com/dontpanic92/wxGo/wx"
```

and have fun!

Examples
----

Examples are in `examples` folder. `Dapeton` is a simple notepad, and `controls` is a dialog that contains several widgets.


Issues
----

The size of the final executalble program grows larger as more classes added into wxGo. Both examples are ~50MB large. You can use `strip` command to reduce the size, but it will remove the symbols.

ScreenShot
----

![screenshot](./examples/screenshot.jpg)
