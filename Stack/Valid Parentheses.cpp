class Solution {
public:
    bool isValid(string s) {
        stack<int> b;
        for(int i=0;i<s.size();i++){
            if(b.empty()&&(s[i]==')'||s[i]=='}'||s[i]==']')){
                return false;
            }
            else if(s[i]=='(')
                b.push(1);
            else if(s[i]=='{')
                b.push(2);
              else if(s[i]=='[')
                b.push(3);
              else if(s[i]==')'){
                  if(b.top()==1)
                      b.pop();
                  else
                      return false;
              }
            else if(s[i]=='}'){
                  if(b.top()==2)
                      b.pop();
                  else
                      return false;
              }
            else if(s[i]==']'){
                  if(b.top()==3)
                      b.pop();
                  else
                      return false;
              }
              
        }
        if(!b.empty())return false;
        else return true;
        
    }
};