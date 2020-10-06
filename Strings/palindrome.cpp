#include <iostream>
#include<cstring>
using namespace std;
bool palindrome(char a[]) {
	int i = 0;
	int j = strlen(a) - 1;
	while (i < j) {
		if (a[i] == a[j]) {
			i++;
			j--;
		}
		else
			return false;
	}
	return true;
}
int main() {
	char a[20];
	cout << "enter a string" << endl;
	cin.getline(a, 20);
	if (palindrome(a))
		cout << "it is palindrome" << endl;
	else
		cout << "not a palindrome" << endl;
}