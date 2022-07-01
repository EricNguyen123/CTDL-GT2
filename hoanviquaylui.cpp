#include<iostream>
#include<stdbool.h>
using namespace std;
int n;
int x[100];
bool check[100];
void gan()
{
	for(int i=1;i<=n;i++)
	{
		check[i]=true;
	}
}
void in()
{
	for(int i=1;i<=n;i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
}
void xu_ly(int i)
{
	for(int j=1;j<=n;j++)
	{
		if(check[j]==true)
		{
			x[i]=j;
		    check[j]=false;
	        if(i==n)
		    {
			    in();
		    }
		    else
		    {
			    xu_ly(i+1);
		    }
		    check[j]=true;
		}
	     
	}
}
int main()
{
	cin>>n;
	gan();
	xu_ly(1);
	return 0;
}
