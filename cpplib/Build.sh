#!/bin/bash

clang -O2 Main.cpp -o Main.wasm -target wasm32-unknown -nostdlib -mreference-types -Wl,--no-entry,--export-dynamic
