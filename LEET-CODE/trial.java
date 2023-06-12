public class Solution {
    public int divide(int dividend, int divisor) {
        if(dividend == Integer.MIN_VALUE && divisor == -1){
            return Integer.MAX_VALUE;
        }
        else if(divisor == Integer.MIN_VALUE && dividend != Integer.MIN_VALUE ){
            return 0;
        }
        else{
            int sign = 1;
            if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
                sign = -1;
            }
            
        }

    }
} 
