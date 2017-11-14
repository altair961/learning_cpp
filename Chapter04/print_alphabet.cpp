#include "..\std_lib_facilities.h"

char letter;

int main() {
	//	letter = 97;
	
	//	cout << char('a'+1);
	for(int i = 97; i <= 122; i++) {
		cout << i;
		cout << " ";
		cout << char(i);
		cout << '\n';
	}
}
