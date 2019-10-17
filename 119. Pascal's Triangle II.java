/**
只需要最后一行的数据 且只有一个额外的数组O(k) 用一个数组不停的覆盖 只需要保存前一个数字就ok
**/
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> result = new ArrayList<>();
        int pre = 1;
        result.add(1);
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = 1; j < i; j++) {
                int temp = result.get(j);
                result.set(j, temp + pre);
                pre = temp;
            }
            result.add(1);
        }
        return result;
    }
}