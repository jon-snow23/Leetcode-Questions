class dsu{
    public:
    int cmp;
    vector<int> par;
    vector<int> rank;

    dsu(int n){
        cmp=n;
        par.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<=n;i++){
        par[i]=i;
    }
    for(int i=0;i<=n;i++){
        rank[i]=0;
    }
    }



    int findpar(int u){
        if(u==par[u]){
            return u;
        }

        return par[u]=findpar(par[u]);
    }

    void unionof(int x,int y){
        int xpapa=findpar(x);
        int ypapa=findpar(y);
        if(xpapa==ypapa){
            return;//dont do anything
        }
        
        if(rank[xpapa]>rank[ypapa]){
            //jo bada hai voh papa banega
            par[ypapa]=xpapa;
        }
        else if(rank[ypapa]>rank[xpapa]){
            par[xpapa]=ypapa;
        }
        else{
            //arbitary but rank increase kr dio
            par[xpapa]=ypapa;
            rank[ypapa]++;
        }

        cmp--;

    }

};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        dsu alice(n);
        dsu bob(n);

        int e=0;
        
        auto lambda=[&](vector<int>&a,vector<int>&b){
            return a[0]>b[0]; //type 3 wale first aajayenge 
        };

        sort(edges.begin(),edges.end(),lambda);

        for(auto x:edges){
            int type=x[0];
            int from=x[1];
            int too=x[2];
           
            if(type==3){
                 int drawn=0;
                if(alice.findpar(from)!= alice.findpar(too)){
                    alice.unionof(from,too);
                    //e++;
                    drawn=1;
                }

                if(bob.findpar(from)!= bob.findpar(too)){
                    bob.unionof(from,too);
                   // e++;
                   drawn=1;
                    
                }
                if(drawn){
                    e++;
                }

            }

            else if(type==2){

                 if(bob.findpar(from)!= bob.findpar(too)){
                    bob.unionof(from,too);
                    e++;
                    
                }

            }


            else{

                if(alice.findpar(from)!= alice.findpar(too)){
                    alice.unionof(from,too);
                    e++;
                    
                }


            }
        }

        if(alice.cmp==1 &&bob.cmp==1){
            return edges.size()-e;
        }
        return -1;


        
    }
};