class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        map<int,int> mp;
        int ans=0;
        mp[0]=0;
        for(int i=0;i<hours.size();i++)
        {
            if(hours[i]%24==0)
            {
                ans+=mp[0];
            }
            else if(mp.find(24-(hours[i]%24))!=mp.end())
            {
                ans+=mp[24-(hours[i]%24)];
            }
            mp[hours[i]%24]++;
        }
        return ans;
    }
};