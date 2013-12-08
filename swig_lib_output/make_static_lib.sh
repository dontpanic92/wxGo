#!/bin/bash

6g -o $1.6 $1.go go_helper.go
6c -I /usr/lib/go/src/pkg/runtime/ $1_gc.c
pack grc $1.a $1.6 $1_gc.6
