class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int minp = prices[0];
        int mp = 0;
        for(int i = 1; i < n ;i++){
            minp = Math.min(prices[i],minp);
            if(prices[i] - minp > mp)  mp = prices[i] - minp;
        }
        return mp;
}
}