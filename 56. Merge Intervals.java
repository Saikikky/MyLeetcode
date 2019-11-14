class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> result = new ArrayList<>();
        if (intervals == null || intervals.length == 0) {
            return intervals;
        }
        // 二维数组的排序
        Arrays.sort(intervals, (a, b)->a[0] - b[0]);
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 1; i < intervals.length; i++) {
            // 有重叠部分
            if (intervals[i][0] <= right) {
                right = Math.max(right, intervals[i][1]);
            } else {
                result.add(new int[]{left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        result.add(new int[]{left, right});
        int[][] res = new int[result.size()][2];
        for (int i = 0; i < res.length; i++) {
            res[i][0] = result.get(i)[0];
            res[i][1] = result.get(i)[1];
        }
        return res;
    }
}