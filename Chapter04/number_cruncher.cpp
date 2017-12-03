#include "..\std_lib_facilities.h"

bool IsUnitAcceptable(string);
bool IsInputSucceeded(double, string);
bool IsInputTerminated(double);

int main()
{
  double input_value = 0.0;
  double largest_so_far = 0;
  double smallest_so_far = 0;
  string unit = "";
  
  cout << "Please, provide two numbers" << endl
       << "When input is not a number it is being assigned to 0" << endl
       << "Terminate the input with '|'" << endl;
  
  while (cin >> input_value &&
    //	 cin >> unit) &&
	 //	 IsUnitAcceptable(unit))// &&
    	 !IsInputTerminated(input_value))
  {
    cout << "======================================" << endl;
    cout << "Inputed number: " << input_value << endl << unit;
    smallest_so_far = input_value;
    if(largest_so_far < input_value)
    {
      smallest_so_far = largest_so_far;
      largest_so_far = input_value;
      cout << "The largest so far is: " << largest_so_far << endl;
      cout << "The smallest so far is: " << smallest_so_far << endl;
    }
    if(largest_so_far > input_value)
    {
      smallest_so_far = input_value;
      cout << "The largest so far is: " << largest_so_far << endl;
      cout << "The smallest so far is: " << smallest_so_far << endl;
    }
    if(largest_so_far == smallest_so_far)
    {
      cout << "The largest so far is: " << largest_so_far << endl;
      cout << "The smallest so far is: " << smallest_so_far << endl;
      cout << "The numbers are equal" << endl;
    }
   
    if(((largest_so_far - smallest_so_far) <= 1.0/100) &&
       ((largest_so_far - smallest_so_far) != 0.0))
    {
     cout << "The numbers are almost equal" << endl
	  << "smallest_so_far: " << smallest_so_far << endl
	  << "largest_so_far: " << largest_so_far << endl;
    }
    cout << "The largest so far is: " << largest_so_far << endl;
      cout << "The smallest so far is: " << smallest_so_far << endl;
  }
    cout << "smallest_so_far: " << smallest_so_far << endl;
   cout << "largest_so_far: " << largest_so_far << endl;
  
  
 //  cout << smallest_so_far << endl;
 //  cout << largest_so_far << endl;
  
  return 0;
}

bool IsUnitAcceptable(string unit)
{
  if(unit == "cm" || unit == "m" || unit == "in" || unit == "ft")
    return true;
  cout <<"at IsUnitAcceptable";
  return false;
}

bool IsInputTerminated(double input_value)
{
  return char(input_value) == '|';
}
