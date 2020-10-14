#include <iostream>
#include <string>
#include<cstring>
#include<stack>
using namespace std;


bool checkRedundantBrackets(char *input) {
	stack<char> s;
    for(int i=0;i<strlen(input);i++){
		int count = 0;
        if(input[i] != ')'){
            s.push(input[i]);
        } else {
            while(s.top() != '('){
                s.pop();
                count++;
            }
            if(count == 0){
                return true;
            } else {
                s.pop();
            }
        }
    	
    }
    return false;
    

}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}
