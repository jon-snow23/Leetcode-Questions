class Solution {
public:

    vector<vector<int>>adj;
    set<pair<pair<int,int>,int>>st;
    int dp[51][51][2];

    int solve(int i, int j, int k,int win){
       if(i==j){
        return 2;
       }
       else if(i==0){
        return 1;
       }
        if(dp[i][j][k]!=-1 ){
            return dp[i][j][k];
        }
        if(st.find({{i,j},k})!=st.end()){
            return 0;
        }
        else{
            st.insert({{i,j},k});
        }
        bool won=false;
        bool draw=false;
 
        if(k==0){
            int temp;
            for(auto it:adj[i]){
               temp=solve(it,j,1,2);
               if(temp==0){
                draw=true;
               }
               else if(temp==1){
                won=true;
                break;
               }
            }
            
        }
        else{
            int temp;
            for(auto it:adj[j]){
                if(it==0){
                    continue;
                }
                temp=solve(i,it,0,1);
             
                if(temp==0){
                 draw=true;
                }
                else if(temp==2){
                won=true;
                break;
                }
            }
        }
        st.erase({{i,j},k});
        if(won){
            return dp[i][j][k]=win;
        }
        else if(draw){
            return dp[i][j][k]= 0;
        }
        else {
            if(win==1){
                return dp[i][j][k]=2;
            }
            else{
                return dp[i][j][k]=1;
            }
        }
    }


    int catMouseGame(vector<vector<int>>& graph) {
        adj=graph;
        int ans;
        for(int turn=0;turn<50;turn++){
           for(int i=0;i<51;i++){
            for(int j=1;j<51;j++){
                for(int k=0;k<2;k++){
                if(dp[i][j][k]==0){
                    dp[i][j][k]=-1;
                }
                }
            }
        }
        ans=solve(1,2,0,1);
        }
        return ans;
    }
};