#include "..\std_lib_facilities.h"

vector<double> distances;
double total_distance = 0.0;
double get_smallest(vector<double>);
double get_greatest(vector<double>);
double get_mean(vector<double>);
int zero_index_conpensator = 1;

int main()
{
  cout << "Please, enter values: " << endl;
  for (double distance; cin >> distance;)
  {
    distances.push_back(distance);
        total_distance = total_distance + distance;
  }

  cout << "The smallest number: " << get_smallest(distances) << endl;
  cout << "The greatest number: " << get_greatest(distances) << endl;
  cout << "The mean is: " << get_mean(distances) << endl;
  cout << "The total distance: " << total_distance << endl;

  return 0;
}

double get_smallest(vector<double> distances)
{
  sort(distances);
  return distances.at(0);
}

double get_greatest(vector<double> distances)
{
  sort(distances);  
  return distances.at(distances.size() - zero_index_conpensator);
}

double get_mean(vector<double> distances)
{
  int last_element_index = distances.size() - zero_index_conpensator;
  int first_element_index = 0;
  return (distances.at(last_element_index) + distances.at(first_element_index)) / 2;
}
