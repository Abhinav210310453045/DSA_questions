#define MOD 1000000007
#include <bits/stdc++.h> 

#include <vector>


using namespace std;
// int Total_ways(int &des,int src)
// {   


//     if(src==des)
//     {   
//         return 1 ;
//     }

//     if(src>des)
//     {
//         return 0;
//     }
//     return (Total_ways(des, src+1)+Total_ways(des, src+2))%MOD;
// }

//this one is using DP
int solve(int n,int i,vector<int> &dp)
{
    if(i==n)
    {
        dp[n]==1;
        return dp[n];
    }
    if(i>n)
    {
        dp[i]=0;
        return dp[i];
    }
    if (dp[i] == -1) {
        dp[i] = (solve(n, i + 1, dp) + solve(n, i + 2, dp)) % MOD;

        return dp[i];
    }
    else{
        return dp[i];
    }
}
int countDistinctWays(int n) {
    // int src=0;
    
    // int des=nStairs;
    // if(nStairs==0)
    //     return 1;
    // int res=Total_ways(des,src);
    // return res;
    //  Write your code here.

    int i=0;

    vector<int> dp;
    for(int i=0;i<=n;i++)
    {
        dp.push_back(-1);
    }

    return -1*solve(n,i,dp);
    
}
