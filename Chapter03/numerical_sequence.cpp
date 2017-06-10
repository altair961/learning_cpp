// Solution for exercise 3.6.
// Show the numbers in numerical sequence

#include "..\std_lib_facilities.h"

int min(int first, int second);
int max(int first, int second);

int main()
{
  int val1;
  int val2;
  int val3;

  cout << "Please, enter the first integer value: ";
  cin >> val1;
  cout << "\nNow enter the second value: ";
  cin >> val2;
  cout << "\nEnter the third value: ";
  cin >> val3;
  
  if(val1 < val2){
    if(val1 < val3){
      //show: val1
      //show: min(val2, val3);
      //show: max(val2, val3);
    }
    if(val3 < val1){  //val1 < val2 && val3 < val1 show: val3, val1, val2
      //show: val3
      //show: val1
      //show: val2
    }
  }
  
  if(val2 < val1){
    if(val2 < val3){ 
      //show: val2
      //show: min(val1, val3);
      //show: max(val1, val3);
    }
    if(val3 < val2){ // val3, val2, val1
      //show: val3
      //show: val2
      //show: val1
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

  return -1;
}

  /*
  
  if(val2 < val1){
    if(val1 < val3){
      
    }
  }

  if(val1 < val2){
    if(val2 < val3){
      // val1 val2 val3
    }
    if(val3 < val2){
      // val1 val3 val2
    }
  }
  if(val2 < val1){
    if(val2 < val3){
      
    }
  }
  // val1 ? val2
  // val1 ? val3
  cin >> val1;
  cin >> val2;

  if(val1 < val2){
    first = val1;
    second = val2;
  }
  if(val2 < val1){
    first = val2;
    second = val1;
  }

  cin >> val3;

  if(val3 < val1)
  

  


  
  first_candidate = min(val1, val2);
  if(val1)
  
  cin >> val3;

  first = min(first_candidate, val3);

  //show  first
  
  if(first_candidate != first){
    //show val3
  }
  else{
    
  }
  
)
    
  second = 



  
  if(val1 < val2){
    first = val1;
    second = val2;
  }

if(val2 < val1){
    first = val2;
    second = val1;
  }
  cin >> val3
}
  */
