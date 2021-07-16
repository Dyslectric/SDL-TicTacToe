#!/bin/bash
g++ -c src/** -m64 -Wall -I include && g++ *.o -o bin/release/main -l SDL2 -l SDL2_image
rm *.o
bin/release/main
