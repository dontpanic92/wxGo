wxGo
====

Golang wxWidgets Wrapper

Issues
----

Since GoLang only supports static-link currently, the size of the final executalble program grows larger as more classes are added into wxGo. Is GoLang really suitable for user applications?

Note
----

- This repo isn't ready yet
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

and have fun! Please refer to `example/test.go` for details.

ScreenShot
----

![screenshot](./example/screenshot.jpg)
