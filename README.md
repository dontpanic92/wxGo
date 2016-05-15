wxGo
====

Golang wxWidgets Wrapper

Note
----

**About the package**

- Currently wxWidgets is statically linked into wxGo and for convenience (go build-able) a pre-compiled version of wxWidgets is used
- To use your customized version of wxWidgets, please modify `src/define.i` where the `CPPFLAGS` and `LDFALGS` are
- Only linux_amd64 supported and tested now

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

![screenshot](./example/screenshot.jpg)
