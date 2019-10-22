class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer, Integer> hashMap = getElement(nums);
        HashMap.Entry<Integer, Integer> temp = null;
        for (HashMap.Entry<Integer, Integer> entry : hashMap.entrySet()) {
            if (temp == null || temp.getValue() < entry.getValue()) {
                temp = entry;
            }
        }
        return temp.getKey();
    }
    
    public HashMap<Integer, Integer> getElement(int[] nums) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (!hashMap.containsKey(nums[i])) {
                hashMap.put(nums[i], 1);
            } else {
                hashMap.put(nums[i], hashMap.get(nums[i]) + 1);
            }
        }
        return hashMap;
    }
}