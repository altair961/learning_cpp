// ch4_chess_inventors_reward_memory_limits.cpp : Defines the entry point for the console application.
// This program demonstrates lack of int and double capacity
// to represent the amount of chess inventors reward.

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include "../std_lib_facilities.h"

using namespace std;

int main()
{
	auto constexpr power_base = 2;
	auto constexpr rice_grains_reward = 1000000000;
	auto constexpr chess_desk_squares = 64;
	auto power_lvl = 0;
	auto curr_grains = 0.0;
	auto curr_square = 1;

	while (curr_square < chess_desk_squares)
	{
		curr_grains = pow(power_base, power_lvl);
		power_lvl++;
		curr_square++;
		
		cout << "Chess square " << curr_square << '\t' << curr_grains << " grains" << endl;
	}

	keep_window_open();
    return 0;
}