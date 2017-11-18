// Solution for exercise 3.7.
// Show the strings in alphabetical sequence

#include "../std_lib_facilities.h"

string to_lower(string str);
string min(string first, string second);
string max(string first, string second);

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
  cout << "Now enter the second word: ";
  cin >> second_str;
  cout << "Enter the third word: ";
  cin >> third_str;
  
  if(first_str[0] <= second_str[0]){
    if(first_str[0] <= third_str[0]){
      cout << first_str << ", ";
      cout << min(second_str, third_str) << ", ";
      cout << max(second_str, third_str) << "\n";
    }
    if(third_str[0] < first_str[0]){
      cout << third_str << ", ";
      cout << first_str << ", ";
      cout << second_str << "\n";
    }
  }
  if(second_str[0] < first_str[0]){
    if(second_str[0] <= third_str[0]){ 
      cout << second_str << ", ";
      cout << min(first_str, third_str) << ", ";
      cout << max(first_str, third_str) << "\n";
    }
    if(third_str[0] < second_str[0]){
      cout << third_str << ", ";
      cout << second_str << ", ";
      cout << first_str << "\n";
    }   
  }
  
  return 0;
}

string to_lower(string str){
  int char_alphabet_pos = 0;
  for (int i = 0; i < str.length(); i++) {
    char curr_char = str[i];
    if(curr_char >= first_ascii_uppercase && curr_char <= last_ascii_uppercase){
      char_alphabet_pos = curr_char - first_ascii_uppercase; 
      curr_char = first_ascii_lowercase + char_alphabet_pos;
      str[i] = curr_char;
    }
  }
  return str;
}

string min(string first, string second)
{
  if(first[0] < second[0]){
    return first;
  }
  if(second[0] < first[0]){
    return second;
  }
  if(first == second){
    return first;
  }
  return "";
}

string max(string first, string second)
{
  if(first[0] > second[0]){
    return first;
  }
  if(second[0] > first[0]){
    return second;
  }
  if(first == second){
    return first;
  }
  return "";
}
