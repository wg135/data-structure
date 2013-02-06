public class Solution {
    public ArrayList<ArrayList<Integer>> generate(int numRows) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        if(numRows == 0)
          return result;
          
        ArrayList<Integer> array = new ArrayList<Integer>();
        array.add(1);
        result.add(array);
        
        if(numRows == 1)
          return result;
          
        ArrayList<Integer> array2 = new ArrayList<Integer>();
        array2.add(1);
        array2.add(1);
        result.add(array2);
        
        int i = 2;
        
        while(i < numRows){
            ArrayList<Integer> array1 = new ArrayList<Integer>();
            array1.add(0, 1);
            for(int j=1; j<i; j++){
                int tmp = result.get(i-1).get(j-1) + result.get(i-1).get(j);
                array1.add(j, tmp);
            }
            array1.add(i, 1);
            result.add(array1);
            i++;
        }
        
        return result;
    }
}
