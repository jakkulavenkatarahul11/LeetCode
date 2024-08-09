class Solution {
    public boolean searchMatrix(int[][] array2D, int target) {
        int rows = array2D.length;
        int cols = array2D[0].length;
    
        for (int i = 0; i < rows * cols; i++) {
            int rowIndex = i / cols;
            int colIndex = i % cols;
            if(array2D[rowIndex][colIndex]==target)return true;  
        }
    return false;}
}