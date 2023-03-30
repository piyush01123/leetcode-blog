class Job
{
    public:
    int startTime, endTime, profit;
    Job(int s, int e, int p): startTime(s), endTime(e), profit(p) {}
    bool operator <  (const Job &other_job)const{return endTime  < other_job.endTime;}
    bool operator == (const Job &other_job)const{return endTime == other_job.endTime;}
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        int n = startTime.size();
        vector<Job> jobs;
        for (int i=0; i<n; i++)
            jobs.push_back(Job(startTime[i],endTime[i],profit[i]));
        sort(jobs.begin(),jobs.end());
        
        vector<Job> dp = vector<Job>{Job(-1,0,0)};
        for (const Job &job: jobs)
        {
            auto itr = upper_bound(dp.begin(),dp.end(),Job(-1,job.startTime,-1));
            int idx = itr-dp.begin()-1;
            int opt_A = dp[idx].profit + job.profit;
            int opt_B = dp.rbegin()->profit;
            if (opt_A > opt_B)
                dp.push_back(Job(-1,job.endTime, opt_A));
        }
        return dp.rbegin()->profit;
    }
};

