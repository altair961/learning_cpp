// This program shows a median for a given sequence
// of numbers according to the following definition of median:
// "a number so that exactly as many elements come before it in
// the sequence as coe after it"

#include "..\std_lib_facilities.h"

int main()
{
  vector<doubles> temps;
  for(double temp; cin >> temp;)
    temps.push_back(temp)
    
  sort(temps);
  cout << "Median temperature: " << temps[temps.size()/2] << endl;

  // if number of eleents is even we say that median cannot be shown

  return 0;
}
