class Solution {
public:
void merge(vector<int>& arr , int start1 ,int start2 , int end){
    
    int n1 = start2 -start1 +1;
    int n2 = end -start2;
    vector<int> left(n1), right(n2) ;
    for(int k =0 ; k<n1 ; k++){
        left[k]= arr[start1 + k];
    }
    for(int k =0 ; k<n2 ; k++){
        right[k]= arr[start2 + k+1];
    }
int i =0,j =0,k=start1;
    while(i<n1 && j<n2){
        if(left[i]<= right[j]){
            arr[k++]= left[i++];
        }
        else{
           
             arr[k++]= right[j++];
        }
    }
    while( i < n1){
        arr[k++]= left[i++];
    }
    while( j < n2){
          arr[k++]= right[j++];
    }
}

   void sort(vector<int>& nums , int start , int end)
   {
    if(start>=end){ return;}
    int  mid = start + (end-start)/2;
         sort(nums, start , mid);
         sort(nums, mid+1 , end);
          merge(nums , start , mid , end);
   }

    vector<int> sortArray(vector<int>& nums) 
    {
     sort(nums, 0 ,nums.size()-1 );
     return nums; 
    }
};