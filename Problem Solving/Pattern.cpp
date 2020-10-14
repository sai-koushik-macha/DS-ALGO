/*Take as input N, an odd number (>=5) . Print the following pattern as given below for N = 7.

*  ****
*  *
*  *
*******
   *  *
   *  *
****  *
Input Format
Enter value of N ( >=5 )

Output Format
Print the required pattern.
*/

#include<iostream>
int main() {
	int n,i,j,k;
	std::cin>>n;
    for(i=0;i<n;i++){
        if(i==0 || i>=n/2)
            std::cout<<"*";
        else
            std::cout<<" ";
    }
    std::cout<<"\n";
	for(i=0;i<n-2;i++){
	    if(i%2 != 0){
	        for(j=0;j<=n/2;j++){
	            if(j==0 || j==n/2)
	                std::cout<<"*";
	            else
	                std::cout<<" ";
	        }
	        std::cout<<"\n";
	    }
	    else{
	        std::cout<<"\n";
	    }
	}
	std::cout<<"\n";
	for(i=0;i<n;i++){
	    std::cout<<"*";
	}
	std::cout<<"\n";
	for(i=0;i<n-2;i++){
	    if(i%2 != 0){
	        for(j=0;j<n;j++){
	            if(j==n/2 || j==n-1)
	                std::cout<<"*";
	            else
	                std::cout<<" ";
	        }
	        std::cout<<"\n";
	    }
	    else{
	        std::cout<<"\n";
	    }
	}
	std::cout<<"\n";
	for(i=0;i<n;i++){
	    if(i==n-1 || i<=n/2)
	        std::cout<<"*";
	    else
	        std::cout<<" ";
	}
	return 0;
}
