class Solution {
    public String multiply(String num1, String num2) {
         if (num1 == null || num1.length() == 0 || num2 == null || num2.length() == 0) return String.valueOf(0);
        if (Integer.valueOf(String.valueOf(num1.charAt(0))) == 0 || Integer.valueOf(String.valueOf(num2.charAt(0))) == 0) return String.valueOf(0);
        int length1 = num1.length();
        int length2 = num2.length();

        char[] ch1 = num1.toCharArray();
        char[] ch2 = num2.toCharArray();
        int[] n1 = new int[length1];
        int[] n2 = new int[length2];

        for (int i = 0; i < length1; i++) {
            n1[i] = Integer.valueOf(String.valueOf(ch1[i]));
        }

        for (int i = 0; i < length2; i++) {
            n2[i] = Integer.valueOf(String.valueOf(ch2[i]));
        }

        int length = length1 + length2;
        int[] nums = new int[length];
        for (int i = length2 - 1; i >= 0; i--) {
            for (int j = length1 - 1; j >= 0; j--) {
                if (n2[i] != 0) {
                    nums[i + j + 1] += n2[i] * n1[j];
                }

            }
        }
        int index = 0;
        for (int k = length - 1; k >= 0; k--) {
            int temp = (nums[k] + index) / 10;
            nums[k] = (nums[k] + index) % 10;
            index = temp;
        }

        StringBuffer sb = new StringBuffer();
        for (int k = 0; k < length; k++) {
            if (k == 0 && nums[k] == 0) continue;
            sb.append(nums[k]);
        }
        return sb.toString();
    }
}