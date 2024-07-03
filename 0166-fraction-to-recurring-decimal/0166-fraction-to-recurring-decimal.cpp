class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long int newnum = abs(numerator);
        long long int newden = abs(denominator);
        string intpart = to_string(newnum/newden);
        long long int init_frac = newnum%newden;
        if(init_frac == 0){
            if((numerator<0 && denominator>0) || (numerator>0 && denominator<0)){
                return '-'+intpart;
            }
            return intpart;
        }
        map<long long int,pair<int,int>> remainder;
        string frac="";
        int pos = 0;
        int place = 0;
        while(init_frac!=0){
            if(remainder.find(init_frac)!=remainder.end()){
                place = remainder[init_frac].second;
                break;
            }
            frac+=to_string((10*init_frac)/newden);
            remainder[init_frac].first++;
            remainder[init_frac].second=pos;
            init_frac = (10*init_frac)%newden;
            pos++;
            
        }
        if(init_frac==0){
            if((numerator<0 && denominator>0) || (numerator>0 && denominator<0)){
                return '-'+intpart+'.'+frac;
            }
            return intpart+'.'+frac;
        }
        string ans = "";
        for(long long int i=0; i<place; i++){
            ans+=frac[i];
        }
        ans+='(';
        for(int i=place; i<frac.size(); i++){
            ans+=frac[i];
        }
        ans+=')';
        if((numerator<0 && denominator>0) || (numerator>0 && denominator<0)){
            return '-'+intpart+'.'+ans;
        }
        return intpart+'.'+ans;
    }
};