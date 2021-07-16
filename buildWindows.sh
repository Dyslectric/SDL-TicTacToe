#!/bin/bash
x86_64-w64-mingw32-g++ -c src/** -mwindows -Wall -I include
x86_64-w64-mingw32-g++ *.o -l SDL2 -l SDL2main -l SDL2_image -l mingw32 -o bin/release/main.exe
rm *.o
