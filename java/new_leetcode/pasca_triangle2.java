public class Solution {
    public ArrayList<Integer> getRow(int rowIndex) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int []res = new int[rowIndex+1];
        res[0]=1;
        if(rowIndex==0) return getList(res);
        for(int i=1;i<rowIndex+1;i++){
            for(int j=i-1;j>0;j--){
                res[j]=res[j]+res[j-1];
            }
            res[i]=1;
        }
        return getList(res);
    }
    
    public ArrayList<Integer> getList(int[] nums){
        ArrayList<Integer> res = new ArrayList<Integer>();
        for(int i=0;i<nums.length;i++){
            res.add(nums[i]);
        }
        return res;
    }
}
