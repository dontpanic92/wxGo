wxGo
====

Golang wxWidgets Wrapper

Usage
----

```
go get github.com/dontpanic92/wxGo/wx
```

You can add `-x` option to print each command it executes. Then

```
import "github.com/dontpanic92/wxGo/wx"
```

and have fun!

Examples
----

Examples are in `examples` folder. `Dapeton` is a simple notepad, and `controls` is a dialog that contains several widgets.

Note
----

**About the package**

- Currently wxWidgets is statically linked into wxGo and for convenience (go build-able) a pre-compiled version of wxWidgets is used
- To use your customized version of wxWidgets, please modify `src/define.i` where the `CPPFLAGS` and `LDFALGS` are
- Only linux_amd64 supported and tested now

**About the memory management**

All `NewXXX` functions will allocate memory on C++ side (on heap), thus it will not be tracked by Go's garbage collector. However, in most cases we don't need to worry about it, because wxWidgets will handle it. Some common cases are listed below:

- √ When a `wxWindow` (or its subclasses) being deleted , it will automatically delete all of its children.

- √ When we click the close botton of a `wxFrame`, by default the `Destroy` will be called and it will be deleted by itself (and also all children). 

- × However when we close a `wxDialog`, the `Destroy` won't be called by default and we have to manually destroy it.

- × If an object isn't in the GUI hierachy, we have to free the memory by calling `DeleteXXX`. 

More Info: 

- [wxWidgets docs on window deletion](http://docs.wxwidgets.org/3.0/overview_windowdeletion.html)

- [SWIG docs on Go memory management](http://www.swig.org/Doc3.0/Go.html#Go_class_memory)


ScreenShot
----

![screenshot](./examples/screenshot.jpg)
