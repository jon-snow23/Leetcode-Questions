class Solution {
public:
    bool isReachableAtTime(int startX, int startY, int endX, int endY, int time) {
        // If start and end positions are the same
        if(startX == endX && startY == endY){
            // If time is 1, return false as we can't move and then return to the same cell in 1 second
            if(time == 1)                
                return false;
            else                
                return true;
        }        
        // Calculate the absolute differences in x and y coordinates
        int diffX = abs(endX - startX);
        int diffY = abs(endY - startY);        
        
        // Get the maximum of the two differences
        int maxDiff = max(diffX, diffY);
        
        // If the maximum difference is less than or equal to the time, return true
        if(maxDiff <= time)            
            return true;
        else            
            return false;
    }
};
