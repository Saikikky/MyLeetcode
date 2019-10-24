class Solution {
    public String convert(String s, int numRows) {
        if (numRows < 2) return s;
        List<StringBuffer> list = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            // 每一行一个新的字符串
            list.add(new StringBuffer());
        }
        // 从第一行开始 表示当前在第几行
        int i = 0;
        // 往下走为+1 往上走为-1
        int flag = -1;
        // 开始对字符串进行循环
        for (char c : s.toCharArray()) {
            list.get(i).append(c);
            // 在转折处将flag置为相反数
            if (i == 0 || i == numRows - 1) {
                flag = -flag;
            }
            // 下一行
            i += flag;
        }
        StringBuffer stringBuffer = new StringBuffer();
        for (int j = 0; j < numRows; j++) {
            stringBuffer.append(list.get(j));
        }
        return stringBuffer.toString();
    }
}