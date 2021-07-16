#!/bin/bash
g++ -c src/*.cpp -m64 -g -Wall -I include && g++ *.o -o bin/debug/main -l SDL2 -l SDL2_image
rm *.o
bin/debug/main
