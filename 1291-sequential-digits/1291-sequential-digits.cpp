class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string l=to_string(low);
        string h=to_string(high);
        vector<int>ans;
        int digit=l[0]-'0';
        int first=digit;
        int s=l.size();
        // cout<<s<?<endl;
        for(int i=0;i<l.size();i++){
                if((l[i]-'0')>first){
                    // cout<<l[i]<<" "<<
                    digit=l[0]-'0'+1;
                    // cout<<"hi"<<endl;
                    // s++;
                    break;
                }
                else if(l[i]-'0'<first){
                    break;
                }
                first++;
            }
            // cout<<digit<<" "<<s<<endl;
        if((digit+s)>10){
            s++;
            digit=1;
        }
        // else{
            
        // }
        // cout<<l<<" "<<h<<endl;
        // cout<<digit<<" "<<s<<endl;
        bool gotHigher=false;
        while(s<=h.size()){
            string st="";
            int d=digit;
            // cout<<d<<endl;
            for(int i=0;i<s;i++){
                // cout<<(char)(d+'0')<<endl;
                st.push_back(d+'0');
                d++;
            }
            digit++;
            if(s==h.size()){
                for(int i=0;i<s;i++){
                    if(st[i]>h[i]){
                        
                        gotHigher=1;
                        break;
                    }
                    else if(st[i]<h[i])break;
                }
            }
            if(d==10){
                // cout<<"hello hi bye bye"<<endl;
                s++;
                digit=1;

            }
            
            // 300 123
            // cout<<"hi "<<st<<endl;
            int num=stoi(st);
            // cout<<"hi "<<num<<endl;
            if(gotHigher==false){
                // cout<<num<<endl;
                ans.push_back(num);
                // break;
            }
            else{
                break;
            }
        }
        return ans;
        
        
    }
};
