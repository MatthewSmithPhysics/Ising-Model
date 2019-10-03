#!/bin/bash

g++ -o ising main.cpp report.cpp trials.cpp dynamics.cpp state.cpp includes.cpp
./ising
