#pragma once
#include"includes.h"
#include"state.h"

State evolve(State, float, int);
float H(State);
float acc(State, State, float);
