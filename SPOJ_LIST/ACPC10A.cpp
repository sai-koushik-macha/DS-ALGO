#include <bits/stdc++.h>
using namespace std;
int main()
{
    float a,b,c;
    while(1){
    cin>>a>>b>>c;if(a==0&&b==0&&c==0){break;}
    if(b==(a+c)/2)
    cout<<"AP "<<floor(c+(b-a))<<"\n";
    else
    cout<<"GP "<<floor((b/a)*c)<<"\n";}
}

