#include "..\std_lib_facilities.h"

int main(){
	string previous = ""; 
	string current;
	
	while(cin>>current){
		if(previous == current)
			cout << "Repeated word: " + current << '\n';

		previous = current;
		
		//else {
		//	cout << "We are at else\n";
		//	cout << "Current :" + current << '\n';
		//	cout << "Previous :" + previous << '\n';
		//}
       
	}
}
