// ch4_print_median.cpp : Defines the entry point for the console application.
// This program shows a median for a given sequence
// of numbers according to the following definition of median:
// "a number so that exactly as many elements come before it in
// the sequence as come after it"

#include "stdafx.h"
#include "..\std_lib_facilities.h"

int get_left_edge_index(vector<double>, int);
double get_average(double, double);
double median_left_edge = 0.0;
double median_right_edge = 0.0;
int reminder = 0;
int constexpr zero_index_compensation = 1;
int constexpr delta_to_next_element = 1;

int main()
{
	vector<double> temps;
	for (double temp; cin >> temp && temp != '|';)
		temps.push_back(temp);

	double reminder = temps.size() % 2;
	cout << "reminder: " << reminder << endl;

	if (reminder == 0)
	{
		cout << "Size is even: " << temps.size() << endl;

		median_left_edge = temps[get_left_edge_index(temps, zero_index_compensation)];
		median_right_edge = temps[get_left_edge_index(temps, zero_index_compensation) + delta_to_next_element];

		cout << "median_left_edge: " << median_left_edge << endl;
		cout << "median_right_edge: " << median_right_edge << endl;
		cout << "The median is: " << get_average(median_left_edge, median_right_edge) << endl;
	}
	else
	{
		cout << "Size is odd" << endl;
		cout << "temps.size()/2: " << temps.size() / 2 << endl;
		cout << "Median temperature: " << temps[temps.size() / 2] << endl;
	}
	for (double temp : temps)
		cout << "temp: " << temp << endl;
	cout << temps.size() << endl;

	keep_window_open();
	return 0;
}

double get_average(double first, double second)
{
	return (first + second) / 2.0;
}

int get_left_edge_index(vector<double> values, int zero_index_compensation)
{
	return values.size() / 2 - zero_index_compensation;
}

