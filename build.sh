#!/bin/sh

g++ -std=c++11 main-cli.cpp lib/*.cpp cli-ui/*.cpp -o tictactoe
chmod +x tictactoe

