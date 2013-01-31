public class Solution {
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        if(prices.length == 0)
            return 0;
        int maxp = 0;
        int low = prices[0];
        for(int i=1; i<prices.length; i++){
            int profit = prices[i] - low;
            if(profit > maxp)
                maxp = profit;
            if(low > prices[i])
               low = prices[i];  
        }
        
        return maxp;
    }
}
