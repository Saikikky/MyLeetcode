/* 
    Reverse Words in a String
    Example 1:

    Input: "the sky is blue"
    Output: "blue is sky the"
    Example 2:

    Input: "  hello world!  "
    Output: "world! hello"
    Explanation: Your reversed string should not contain leading or trailing spaces.
    Example 3:

    Input: "a good   example"
    Output: "example good a"
    Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string. 
*/

class Solution {
    public String reverseWords(String s) {
        String[] words = s.split(" ");
        StringBuffer outputWord = new StringBuffer("");
        for (int i = words.length - 1; i >= 0; i--) {
            outputWord = outputWord.append(words[i]);
            if (i != 0) outputWord = outputWord.append(" ");
        }
        return outputWord.toString();
    }
}


/* 
    Two Sum
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    Example:

    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1]. 
*/
class Solution {
    public int[] twoSum(int[] nums, int target) {

    }
}



/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {

    }
}

/* Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3 */

class Solution {
    public int numIslands(char[][] grid) {
        int sum = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == '1') {
                    // 标记
                    grid[i][j] == '#';

                }
            }
        }
    }

    public static void tag(char[][] grid, int i, int j) {
        // up
        if (i - 1 >= 0 && j >= 0 && grid[i][j] == '1') {
            grid[i][j] = '#';
            tag(grid, i-1, j);
        }
        // down
        if (i + 1 <= grid.length && j >= 0 && grid[i][j] == '1'){
            grid[i][j] = '#';
            tag(grid, i+1, j);
        }
        // left
        if (i >= 0 && j - 1 >= 0 && grid[i][j]
    }
}




