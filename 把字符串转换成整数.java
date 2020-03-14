public class Solution {
    public int StrToInt(String str) {
        if (str == null || str.length() == 0){
            return 0;
        }
        int res = 0;
        int i = 0;
        int sign = 1;
        if (str.charAt(i) == '+' || str.charAt(i) == '-'){
            if (str.charAt(i) == '-'){
                sign = -1;
            }
            i += 1;
        }
        if (str.length() - i > 10){
            return 0;
        }
        for (; i < str.length(); i++){
            if ((int)str.charAt(i) >= 48 && (int)str.charAt(i) <= 57){
                if (res <= -2147483640){
                    if (res<-2147483640)return 0;
                    else if((int)str.charAt(i)-48 > 8)return 0;
                }
                if (res >= 2147483640){
                    if (res>2147483640)return 0;
                    else if((int)str.charAt(i)-48 > 7)return 0;
                }
                res += ((int)str.charAt(i)-48) * Math.pow(10, str.length() - i - 1) * sign;
            }
            else{
                return 0;
            }
        }
        return res;
    }
}