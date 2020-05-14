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
    echo
    echo "* About ${bin}:"
    file "${bin}"
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
    run && echo "* Run successful"
    clean && echo "* Clean successful"
fi
