class MedianFinder {
public:
    priority_queue<int,vector<int>> pqmax;
    priority_queue<int,vector<int>,greater<int>> pqmin;
    MedianFinder() {
        
    }
    
    void addNum(int n) {
        if(pqmax.size()==pqmin.size()){
            if(pqmax.size()==0){
                pqmax.push(n);
                return;
            }
            if(n<=pqmax.top()){
                pqmax.push(n);
            }
            else{
                pqmin.push(n);
            }
        }
        else{
            if(pqmax.size()<pqmin.size()){
                if(n>=pqmin.top()){
                    int temp=pqmin.top();
                    pqmax.push(temp);
                    pqmin.pop();
                    pqmin.push(n);
                }
                else{
                    pqmax.push(n);
                }
            }
            else{
                if(n<=pqmax.top()){
                    int temp=pqmax.top();
                    pqmax.pop();
                    pqmin.push(temp);
                    pqmax.push(n);
                }
                else{
                    pqmin.push(n);
                }
            }
        }
    }
    
    double findMedian() {
        if(pqmax.size()==pqmin.size()){
            return (pqmax.top()+pqmin.top())/2.0;
        }
        else if(pqmax.size()>pqmin.size()){
            return pqmax.top();
        }
        else{
            return pqmin.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */