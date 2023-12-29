/*
You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have 
to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of 
difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a 
job done on that day.

You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job 
is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.

*/

class Solution {
    int dp[12][302];
    public:
    int minDifficulty(vector<int>& arr, int day) {
        int n = arr.size();
        

        if(n<day) return -1;

        for(int i=0;i<=day;i++){
            for(int j=0;j<=n;j++){
                dp[i][j] = 1e6; 
            }
        } 

        for(int i=0;i<n;i++)
        { 

            dp[1][i] = *std::max_element(arr.begin()+i,arr.begin()+n);
        }

        for(int d= 2;d<=day;d++){
            for(int i=0;i<n;i++){

                if(n-i<d){
                    dp[d][i] = 1e6;
                    continue;
                }
                
                for(int j=i;j<n;j++){
                    dp[d][i] = min(dp[d][i],
                                   *std::max_element(arr.begin()+i,arr.begin()+j+1)
                                   +dp[d-1][j+1]);
                }
            }
        }
        return dp[day][0];
    }
};