#include <iostream>
#include <cstring>
using namespace std;
void remove_duplicates(char a[]) {
	if(!strlen(a) || strlen(a)==1){
		return;
	}
	int j = 0;
	for (int i = 1; i < strlen(a); i++) {
		if (a[i] != a[j]) {
			j++;
			a[j] = a[i];
		}
	}
	a[j+1] = '\0';
	cout << "After removing duplicaltes : " << a << endl;
}
int main() {
	char a[1000];
	cin.getline(a, 1000);
	remove_duplicates(a);
}