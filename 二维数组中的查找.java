//在一个二维数组中（每个一维数组的长度相同），
//每一行都按照从左到右递增的顺序排序，
//每一列都按照从上到下递增的顺序排序。请完成一个函数，
//输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。


/**
从左下开始，该值是一列最大的也是一行最小的，故若大于该值就右移，若小于就上移
**/
public class Solution {
    public boolean Find(int target, int [][] array) {
        if (array == null || array.length == 0) return false;
        int rowCount = array.length;
        int colCount = array[0].length;
        for (int i = rowCount - 1, j = 0; i >= 0 && j < colCount; ) {
            if (target == array[i][j]) return true;
            else if (target > array[i][j]) {
                j++;
                continue;
            }
            else {
                i--;
                continue;
            }
        }
        return false;
    }
}