
// Solution for exercise 3.6.
// Show the numbers in numerical sequence

#include "../std_lib_facilities.h"

int min(int first, int second);
int max(int first, int second);

int main()
{
  int val1;
  int val2;
  int val3;

  cout << "Please, enter the first integer value: ";
  cin >> val1;
  cout << "Now enter the second value: ";
  cin >> val2;
  cout << "Enter the third value: ";
  cin >> val3;
  
  if(val1 <= val2){
    if(val1 <= val3){
      cout << val1 << ", "; // show: val1
      cout << min(val2, val3) << ", "; //show: min(val2, val3);
      cout << max(val2, val3) << "\n"; //show: max(val2, val3);
    }
    if(val3 < val1){  //val1 < val2 && val3 < val1 show: val3, val1, val2
      cout << val3 << ", ";//show: val3
      cout << val1 << ", ";//show: val1
      cout << val2 << "\n"; //show: val2
    }
  }
  
  if(val2 < val1){
    if(val2 <= val3){ 
      cout << val2 << ", "; //show: val2
      cout << min(val1, val3) << ", "; //show: min(val1, val3);
      cout << max(val1, val3) << "\n"; //show: max(val1, val3);
    }
    if(val3 < val2){ // val3, val2, val1
      cout << val3 << ", "; //show: val3
      cout << val2 << ", "; //show: val2
      cout << val1 << "\n"; //show: val1
    }   
  }
}

int min(int first, int second)
{
  if(first < second){
    return first;
  }
  if(second < first){
    return second;
  }
  if(first == second){
    return first;
  }
  return -1;
}

int max(int first, int second)
{
  if(first > second){
    return first;
  }
  if(second > first){
    return second;
  }
  if(first == second){
    return first;
  }
  return -1;
}
