#include "../std_lib_facilities.h"

double users_number = 100.0;
bool less_than_100 = false;
//char answer = '';

int main()
{
	
  /*
  if(cin >> answer && answer == 'y')
  {
    less_than_50 = true;
  }
  else
  {
    less_than_50 = false;
  }    
  *//*
  if(cin >> answer && answer == 'y')
  {    
    cout << "Is number less than 25?" << endl;
    if(cin >> answer && answer == 'y')
    {
      cout << "Is number Less
    }
  }
  else
  {

  }*//*
  int x = 50;
  for (int i = 0; i < 4; ++i)
  {
    cout << "Less than " << x << "?" << endl;
    x = x/2;
    cout << "Now x is: " << x << endl;
    }*/

 
  cout << "Please, think of some number between 1 and 100." << endl;
  cout << "Now answer the questions and program will guess the number you made up" << endl << endl;
  cout << "Is number you are thinking of less than 50? Type \"y\" for \"yes\" and \"n\" for \"no\" answer" << endl;
  cin >> answer;
  if(answer == 'y')
  {
    cout << "Less than 25?" << endl;
    cin >> answer;
    if(answer == 'y')
    {
      cout << "Less than 12?" << endl;
      cin >> answer
      if(answer == 'y')
      {
	cout << "Less than 6?" << endl;
      	cin << answer;
	if(answer == 'y')
	{
	  cout << "Less than 3?" << endl;
	  cin << answer;
	  if(answer == 'y')
	  {
	    cout << "Less than 2?" << endl;
	    cin << answer;
	    if(answer == 'y')
	    {
	      cout << "The number you are thinking of is 1" << endl;
	    }
	    else
	    {
	      cout << "The number you are thinking of is 2" << endl;
	    }
	  }
	  else
	  {
	    cout << "Less than 5?" << endl;
	    if(answer == 'y')
	    {
	      cout << "Less than 4?" << endl;
	      cin >> answer;
	      if(answer == 'y')
	      {
		cout << "The number you are thinking of is 3" << endl;
	      }
	      else
	      {
		cout << "The number you are thinking of is 4" << endl;
	      }
	    }
	    else
	    {
	      cout << "The number you are thinking of is 5" << endl;
	    }
	  }
	}
	else // 6 or greater but still less than 12
	{
	  cout << "Less than 9?" << endl; 
	  cin >> answer;
	  if(answer == 'y') // 6 7 or 8
	  {
	    cout << "Less than 8?" << endl;
	    cin >> answer;
	    if(answer == 'y')
	    {
	      cout << "Less than 7?" << endl;
	      cin >> answer;
	      if(answer == 'y')
	      {
		cout << "The number you are thinking of is 6" << endl;
	      }
	      else
	      {
		cout << "The number you are thinking of is 7" << endl;
	      }
	    }
	    else // not less than 8 still less than 9 so it is 8
	    {
	      cout << "The number you are thinking of is 8" << endl;
	    }
	  }
	  else //9 10 or 11 still less than 12
	  {
	    cout << "Less than 10?" << endl;
	    cin >> answer;
	    if(answer == 'y')
	    {
	      cout << "The number you are thinking of is 9" << endl;
	    }
	    else
	    {
	      cout << "Less than 11?" << endl;
	      cin >> answer
	      if(answer < 11)
	      {
		cout << "The number you are thinking of is 10" << endl;
	      }
	      else
	      {
		cout << "The number you are thinking of is 11" << endl;
	      }
	    }
	  }
	  else // greater or eq to 12 still less than 25
	  {// 12 25
	    cout << "Less than 18?" << endl;
	    cin >> answer;
	    if(answer == 'y') // 12 13 14 15 16 17
	    {
	      cout << "Less than 14?" << endl;
	    }
	  }
	}
      }
    }
  }
  else
  {
  }
  return 0;
}
/*
void ask_user(bool fact)
*/
