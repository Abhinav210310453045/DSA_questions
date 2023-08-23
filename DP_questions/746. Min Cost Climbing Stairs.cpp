#include <bits/stdc++.h>
using namespace std;
/* void solve(int curr,int n,int &pen,vector<int> &cost)
{ 
    if(curr==n-2)
    {
        
        pen=pen+cost[curr];
        // cout<<curr<<" "<<pen<<endl;
        curr=curr+2;
        return;
    }
    if(curr==n-1)
    {
        pen=pen+cost[curr];
        // cout<<curr<<" "<<pen<<endl;
        curr=curr+1;
        return;
    }

    if(cost[curr+2]<=cost[curr+1])
    {
        pen=pen+cost[curr];
    // cout<<curr<<" "<<pen<<endl;
        curr=curr+2;
        solve(curr,n,pen,cost);
    }

    else if(cost[curr+2]>cost[curr+1] && curr+2==n-2 && (cost[0]==0 ))
    {
        pen=pen+cost[curr];
    // cout<<curr<<" "<<pen<<endl;
        curr=curr+2;
        solve(curr,n,pen,cost);
    }
    else{
        pen=pen+cost[curr];
    //    cout<<curr<<" "<<pen<<endl;
        curr=curr+1;
        solve(curr,n,pen,cost);
    }
}
*/




class Solution {
public:
    //top down approach
    int solve(vector<int> & cost,int n,vector<int> & dp)
    {
        if(n==0)
        {
            dp[0]=cost[0];
            return dp[0];

        }
        if(n==1)
        {
            dp[1]= cost[1];
            return dp[1];
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        else
        {
             dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
             return dp[n];
        }
    }
    //bottom up approach
    int solve2(vector<int> & dp,int n,vector<int> &cost)
    {

        
        
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++)
        {

        dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        return min(dp[n-1],dp[n-2]);

    }
    int solve3(int n,vector<int> &cost)
    {
       int prev1=cost[1];
        int prev2=cost[0];
        for(int i=2;i<n;i++)
        {

        int current=min(prev1,prev2)+cost[i];
        prev2=prev1;
        prev1=current;
        }
        return min(prev1,prev2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        // int n=cost.size();
        
        // int curr1=0;
        // int pen1=0;
        // int pen2=0;
        // // if(cost[1]<=cost[0])
        // // {
        // curr1=1;
        // solve(curr1,n,pen1,cost);
        // cout<<pen1<<endl;
        // // }
        // // else{
        //  int curr2=0;
        // solve(curr2,n,pen2,cost);
        // cout<<pen2<<endl;
        // // }
        // if(pen1<pen2)
        // {
        //     return pen1;
        // }

        // else{

        // return pen2;
        // }
        

        // another method
        int n=cost.size();
        // vector<int> dp;
        // for(int i=0;i<=n;i++)
        // {
            // dp.push_back(-1);
        // }
    // int ans=solve2(dp,n,cost);
    int ans=solve3(n,cost);

        // int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));

        return ans;
    }
};
