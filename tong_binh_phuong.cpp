#include<iostream>
#include<math.h>
#include<climits>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int dp[10005] = {};
        for(int i = 1; i <= n; ++i)
        {
            dp[i] = INT_MAX;
            int sqr;
            sqr = sqrt(i);
            for(int j = 1; j <= sqr; ++j)
                if(dp[i - j * j] < INT_MAX)
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
        cout << dp[n] << endl;
    }
    return 0;
}