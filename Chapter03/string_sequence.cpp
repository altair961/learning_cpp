// Solution for exercise 3.7.
// Show the strings in alphabetical sequence

#include "../std_lib_facilities.h"

char to_lower(char str);

  int const first_ascii_uppercase = 65;
  int const last_ascii_uppercase = 90;
  int const first_ascii_lowercase = 97;
  int const last_ascii_lowercase = 122;

int main()
{

  string first_str = "";
  string second_str = "";
  string third_str = "";
 
  cout << "Please, enter the first word: ";
  cin >> first_str;
  //cout << first_str[0];

  cout << to_lower(first_str[0]) << "\n";

  
  //get 1-st char of string 
  //to lowercase before start use own tolower function
  return 0;
}

char to_lower(char curr_char){
  //  str[0] = 99;

  int char_alphabet_pos = 0;
  if(curr_char >= first_ascii_uppercase && curr_char <= last_ascii_uppercase){
    char_alphabet_pos = curr_char - first_ascii_uppercase; 

    
    //  str[curr_char] = first_ascii_lowercase + char_alphabet_pos;
    curr_char = first_ascii_lowercase + char_alphabet_pos;
  }
  
  return curr_char;
}
