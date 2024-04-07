#!/bin/bash

clang -O2 -c Main.cpp -o Main.o -target wasm32-unknown -nostdlib -mreference-types -mmultivalue
clang -O2 -c Main.S -o Main.S.o -target wasm32-unknown -nostdlib -mreference-types -mmultivalue
wasm-ld -O2 Main.o Main.S.o -o Main.wasm --export-dynamic --import-memory=./reflect.js,memory
