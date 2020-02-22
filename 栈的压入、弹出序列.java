import java.util.ArrayList;
import java.util.Stack;
public class Solution {
    public boolean IsPopOrder(int [] pushA,int [] popA) {
      if (pushA.length == 0 || pushA.length != popA.length) return false;
        Stack<Integer> temp = new Stack<>();
        int j = 0;
        for (int i = 0; i < pushA.length; i++) {
            temp.push(pushA[i]);
            while (!temp.isEmpty() && temp.peek() == popA[j]) {
                temp.pop();
                j++;
            }
        }
        return temp.isEmpty();
    }
}