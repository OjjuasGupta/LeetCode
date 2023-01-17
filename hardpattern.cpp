#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    for(i=1;i<=5;i++)
    {  cout<<i<<" ";
        k=i;
        for(j=1;j<i;j++)
        {
            if(j%2!=0)
            {
            cout<<k+((2*((5+1-i))-1))<<" ";
            k=k+((2*((5+1-i))-1));
            }
            else{
            cout <<(k+2*(i-j))<<" ";
            k=k+2*(i-j);
            }
        }
      cout<<endl;
    }
}
