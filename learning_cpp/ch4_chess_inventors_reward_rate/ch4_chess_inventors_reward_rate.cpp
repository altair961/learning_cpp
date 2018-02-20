// ch4_chess_inventors_reward_rate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include "../std_lib_facilities.h"

using namespace std;

int main()
{
	//constexpr auto chess_desk_squares = 64;
	//constexpr auto rice_to_give = 1000;
	//auto rice_curr = 0;

	//for (auto curr_square = 0; 
	//	curr_square < chess_desk_squares && 
	//	rice_curr < 1000; 
	//	curr_square++)
	//{	
	//	
	//	rice_curr = pow(2, curr_square);
	//}

	//for (auto i = 0; i < 64; i++)
	//	for (auto curr_grain = 0; curr_grain < 1000; curr_grain=pow(2, i))
	//	{

	//	}




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

	/*
	pow(2, 0);
	pow(2, 1);
	pow(2, 2);


	for (chess_square : chess_squares)
	{
		grains = grains + 
	}

	for (auto grains = 0; grains < 1000; grains = pow(2, i))
	{
		
	}

	//for (auto rice_curr = 0; rice_curr < rice_to_give; rice_curr *= rice_curr)
	//{
	//	cout << rice_curr << endl;
	//}
*/
	keep_window_open();

    return 0;
}