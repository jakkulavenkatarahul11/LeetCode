class Solution {
    public int singleNumber(int[] nums) {
        int count = 0;
        for(int x : nums){
            count ^= x;
        }
    return count; 
    }
}