#pragma once
#include"includes.h"
#include"state.h"
#include"dynamics.h"

std::vector<std::vector<float>> H_vs_T(State, float, int, int);
std::vector<std::vector<float>> H_vs_B(State, float, float, float, int, int, int);
float mean(std::vector<float>, int);
float uncert(std::vector<float>, int);
std::vector<float> extract(std::vector<std::vector<float>>, int);
