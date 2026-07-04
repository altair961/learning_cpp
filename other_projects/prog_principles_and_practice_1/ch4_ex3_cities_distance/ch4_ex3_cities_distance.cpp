#include "../std_lib_facilities.h"

double GetSmallest(vector<double> nums)
{
	sort(nums);
	double smallest = nums.at(0);

	return smallest;
}

double GetLargest(vector<double> nums) 
{
	sort(nums);
	double largest = nums.at(nums.size() - 1);

	return largest;
}

double GetMean(double sumOfTerms, double numOfTerms) 
{
	double mean = sumOfTerms / numOfTerms;

	return mean;
}

int main()
{
	cout << "Please, provide distances between cities \nalong the given route.\n"
		<< "Type pipe-sign \"|\" to terminate input when you're done: ";

	vector<double> distances;
	double totalDistance = 0;
	double prevDistance = 0;
	for (double distance = 0; cin >> distance;) 
	{

		totalDistance += distance;
		distances.push_back(distance);

		prevDistance = distance;
	}
	
	cout << endl;
	cout << "The total distance is: " << totalDistance << "\n";
	
	double smallestDist = GetSmallest(distances);
	cout << "The smallest distance between two neighboring cities is: " << smallestDist << "\n";

	double largestDist = GetLargest(distances);
	cout << "The largest distance between two neighboring cities is: " << largestDist << "\n";

	double meanDistance = GetMean(totalDistance, distances.size());
	cout << "The mean distance between two neighboring cities is: " << meanDistance << "\n";
}