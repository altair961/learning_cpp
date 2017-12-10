#include "..\std_lib_facilities.h"

//bool IsUnitAcceptable(string);
//bool IsInputSucceeded(double, string);
//bool IsInputTerminated(char);
//string GetUnit(string);

int main()
{
  vector<char> input;

  double largest_so_far = 0;
  double smallest_so_far = 0;
  
  cout << "Please, provide two numbers" << endl
       << "When input is not a number it is being assigned to 0" << endl
       << "Terminate the input with '|'" << endl;
  
  double current_char = 0;
  char unit = 0;

  while (cin >> current_char && cin >> unit && (current_char != '|' && unit != '|' ))
    {
      cout << current_char << unit << endl;

      smallest_so_far = current_char;

      if(largest_so_far < current_char)
      {
	smallest_so_far = largest_so_far;
	largest_so_far = current_char;
	cout << "The largest so far is: " << largest_so_far << endl;
	cout << "The smallest so far is: " << smallest_so_far << endl;
      }
      if(largest_so_far > current_char)
      {
	smallest_so_far = current_char;
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
      cout << "End of iteration" << endl;
  }
  
  /*
  for (int i = 0; i <= 2; i++)
  {
    cin >> current_char;
    cin >> temp;

    input.push_back(current_char);
    input.push_back(tmp);
    
    cout << endl << "First iteration has been finished";
  }*/

  //  cout << input[0] << endl << input[1];
  
  /*
  while (cin >> input_value &&
    //	 cin >> unit) &&
	 //	 IsUnitAcceptable(GetUnit(input_value)) &&
    	 !IsInputTerminated(input_value))
  {
    cout << input_value[0] << endl;
    cout << "======================================" << endl;
    cout << "Inputed number: " << input_value << endl << unit;
   
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
 */   
  return 0;
}

//bool IsUnitAcceptable(string unit)
//{
//  cout << "unit: " << unit << endl;
//  if(unit == "cm" || unit == "m" || unit == "in" || unit == "ft")
//    return true;
//  cout <<"at IsUnitAcceptable" << endl;
//  return false;
//}

//bool IsInputTerminated(char current_char)
//{
//  return char(current_char) == '|';
//}

//string GetUnit(string input)
//{
//  for(int x : input)
//  {
    
//  }
//  return "hey";
//}
