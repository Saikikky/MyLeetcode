class Solution {
    public List<Integer> grayCode(int n) {
        // head = 1 << i 计算出对应位数
        List<Integer> res = new ArrayList<Integer>(){{add(0);}};
        int head = 1;
        for (int i = 0; i < n; i++) {
            for (int j = res.size() - 1; j >= 0; j--) {
                System.out.println(head);
                res.add(head + res.get(j));
            }
            head <<= 1;
        }
        return res;
    }
}