// ch4_chess_inventors_reward_rate.cpp : Defines the entry point for the console application.
// This program calculates amount of rice grains to be given 
// to inventor of chess game by the emperor.
// The result is shown for each chess desk square untill the rice grain limit

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include "../std_lib_facilities.h"

using namespace std;

int main()
{
	auto constexpr power_base = 2;
	auto constexpr rice_grains_reward = 1000000000;
	auto power_lvl = 0;
	auto curr_grains = 0;
	auto line_number = 0;

	while (curr_grains <= rice_grains_reward)
	{
		curr_grains = pow(power_base, power_lvl);
		power_lvl++;
		line_number++;
		cout << line_number << '\t' << curr_grains << endl;
	}

	keep_window_open();

    return 0;
}