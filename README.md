wxGo
====

Golang wxWidgets Wrapper

Issues
----

<del>Since GoLang only supports static-link currently,</del> the size of the final executalble program grows larger as more classes are added into wxGo. Is GoLang really suitable for user applications?

Note
----

**About the package**

- Currently wxWidgets is statically linked into wxGo and for convenience (go build-able) a pre-compiled version of wxWidgets is used
- To use your customized version of wxWidgets, please modify `src/define.i` where the `CPPFLAGS` and `LDFALGS` are
- Only linux_amd64 supported and tested now
- Exe file size will be ~40MB

**About types**

Golang is strongly typed, so there are some tips about types:

- Anywhere a `long` type required by a function of wxWidgets, there should be a `int64` type in go
- All named enums (for example `enum wxItemKind {...}`) will produce a new type (`type WxItemKind int`)

So sometimes a typecast will be needed.

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
