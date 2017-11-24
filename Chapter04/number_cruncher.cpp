#include "..\std_lib_facilities.h"
void show_result(int, int);

int main()
{
  int input_1 = 0;
  int input_2 = 0;
  int input_3 = 0;
  
  int smallerValue = 0;
  int largerValue = 0;
  
  cout << "Please, provide two integer numbers" << endl
       << "When input is not a number it is being assigned to 0" << endl
       << "Terminate the input with '|'" << endl;
  
  
  while ((cin >> input_1 &&
      	  cin >> input_2 &&
     	  cin >> input_3) &&
          !((char(input_1) == '|') ||
	    (char(input_2) == '|') ||
	    (char(input_3) == '|')))
  {    
    cout << input_1 << "\n";
    cout << input_2 << "\n";
  }

  if(input_1 > input_2)
  {
    smallerValue = input_2;
    largerValue = input_1;

    show_result(smallerValue, largerValue);
  }
  if(input_1 < input_2)
  {
    smallerValue = input_1;
    largerValue = input_2;

    show_result(smallerValue, largerValue);
  }
  if(input_1 == input_2)
  {
    cout << "The numbers are equal" << endl;
  }
  
  cout << input_1 << endl;
  cout << input_2 << endl;

  return 0;
}

void show_result(int smallerValue, int largerValue)
{
  cout << "The smaller value is: " << smallerValue << endl
       << "The larger value is: " << largerValue << endl;
}
