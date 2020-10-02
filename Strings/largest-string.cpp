#include<iostream>
#include<cstring>
using namespace std;
int main() {
	char istring[50], lstring[50];
	int lar_len = 0, s;
	cout << "Enter no of strings " << endl;
	cin.get();
	cin >> s;

	cout << "enter strings :" << endl;
	
	for (int i = 0; i < s; i++) {
		cin.getline(istring, 50);
		if (strlen(istring) > lar_len) {
			lar_len = strlen(istring);
			strcpy(lstring, istring);
		}
	}
	cout << "string :" << lstring << " of length :" << lar_len << endl;
}