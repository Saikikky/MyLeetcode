class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();

        if (numRows == 0) return result;

        // 第一层一定为1
        result.add(new ArrayList<>());
        result.get(0).add(1);

        for (int i = 1; i < numRows; i++) {
            List<Integer> row = new ArrayList<>();
            // 前一排
            List<Integer> preRow = result.get(i - 1);

            // 第一个一定为1
            row.add(1);

            for (int j = 1; j < i; j++) {
                row.add(preRow.get(j - 1) + preRow.get(j));
            }

            // 最后一个也为1
            row.add(1);
            result.add(row);
        }
        return result;

    }
}