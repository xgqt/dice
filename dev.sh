#!/bin/sh


# This is a simple script to quickly test out the program

# Dev requires:
# - Makefile with options:
#   -clean

# Sys requires:
# - file
# - make
# - sh (time)

# Copyright (c) 2020 XGQT <xgqt@protonamil.com>
# Licensed under the GNU GPL v3 license


bin=dice


build() {
    echo
    echo ">>> Building ${bin}"
    make "${bin}"
}

info() {
    if command -v file >/dev/null
    then
        echo
        echo "* About ${bin}:"
        file "${bin}"
    fi
}

run() {
    if [ -f "${bin}" ]
    then
        echo
        echo ">>> Running ${bin}"
        time ./"${bin}"
    fi
}

clean() {
    echo
    echo ">>> Cleaning ${bin}"
    make clean
}


echo "Running development test for ${bin}"
echo "build -> info -> run -> clean"

if build
then
    echo "* Build successful"
    info
    if run
    then
        echo "* Run successful"
    else
        echo "* Run failed"
        exit 1
    fi
    if clean
    then
        echo "* Clean successful"
    else
        echo "* Clean failed"
        exit 1
    fi
else
    echo "* Build failed"
    exit 1
fi
