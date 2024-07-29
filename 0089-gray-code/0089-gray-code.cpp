class Solution {
 vector<string>solve(int n)
 {
    if(n==1)
    {
        return {"0","1"};
    }
    vector<string>ans;
    vector<string>temp=solve(n-1);//yaha temp mai n=2 tak ke binary form mai store ho gye hai
    for(int i=0;i<temp.size();i++)
    {
        ans.push_back("0"+temp[i]);//0 laga do n=2 ke aage 00 01 11 10
    }
    for(int i=temp.size()-1;i>=0;i--)
    {
        ans.push_back("1"+temp[i]);
        //1 laga do aage sabke lekin n=2 mai hi piche se taaki first aur last mai bhi ek bit ka hi difference aye
    }
    return ans;
 }
public:
    vector<int> grayCode(int n) {//ab yaha string ko int mai convert krenege kyuki answer int mai maanga hai end mai
        vector<string>result=solve(n);//string type hai na
        vector<int>ans;
        for(int i=0;i<result.size();i++)
        {
            ans.push_back(stoi(result[i],0,2));//matlab i 0 se start hoga aur base 2 yaani binary ko convert krega jaise 100 hai toh iss pure ko 4 mai convert krdega
        }
        return ans;
    }
};