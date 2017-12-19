#include "..\std_lib_facilities.h"

double convert_input_to_meters(double, string);

int main()
{
  double largest_so_far = 0;
  double smallest_so_far = 0;
  double sum = 0;
  
  cout << "Please, provide two numbers" << endl
       << "When input is not a number it is being assigned to 0" << endl
       << "Terminate the input with '|'" << endl;
  
  double current_value = 0;
  string unit = "";
  int number_of_values = 0;
  double input_in_meters = 0;
  vector<double> entered_values;
  
  while (cin >> current_value &&
	 cin >> unit &&
	 (unit == "cm" || unit == "in" || unit == "ft" || unit == "m"))
    {
      input_in_meters = convert_input_to_meters(current_value, unit);
      current_value = input_in_meters;
      unit = "meters";
      cout << current_value << unit << endl;
      sum += current_value;
      number_of_values = ++number_of_values;
      smallest_so_far = current_value;

      if(largest_so_far < current_value)
      {
	smallest_so_far = largest_so_far;
	largest_so_far = current_value;
	cout << "The largest so far is: " << largest_so_far << unit << endl;
	cout << "The smallest so far is: " << smallest_so_far << unit << endl;
      }
      if(largest_so_far > current_value)
      {
	smallest_so_far = current_value;
	cout << "The largest so far is: " << largest_so_far << unit << endl;
	cout << "The smallest so far is: " << smallest_so_far << unit << endl;
      }
      if(largest_so_far == smallest_so_far)
      {
	cout << "The largest so far is: " << largest_so_far << unit << endl;
	cout << "The smallest so far is: " << smallest_so_far << unit << endl;
	cout << "The numbers are equal" << endl;
      }
      if(((largest_so_far - smallest_so_far) <= 1.0/100) &&
	 ((largest_so_far - smallest_so_far) != 0.0))
      {
	cout << "The numbers are almost equal" << endl
	     << "smallest_so_far: " << smallest_so_far << unit << endl
	     << "largest_so_far: " << largest_so_far << unit << endl;
      }      
      cout << "The sum is: " << sum << " " << unit << endl;
      cout << "The number of values: " << number_of_values << endl;
      entered_values.push_back(current_value);
      
      cout << "End of iteration" << endl;
  }
  for (double value : entered_values)
  {
    cout << value << endl;
    
  }
  cout << "sorting..." << endl;

  sort(entered_values);
  
  for (double value : entered_values)
  {
    cout << value << endl;
  }
  
  return 0;
}

double convert_input_to_meters(double value, string unit)
{
  double result = 0;

  switch(unit[0]) {
  case 'c':
    result = value / 100;
    break;
  case 'i':
    result = value * 2.54 / 100;
    break;
  case 'f':
    result = value * 12 * 2.54 / 100;
    break;
  case 'm':
    result = value;
    break;
  default:
    cout << "Unknown unit type";
    break;
  }
  
  return result;
}
