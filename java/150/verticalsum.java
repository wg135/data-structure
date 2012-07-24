/*
Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. 
Print all sums through different vertical lines.
*/
import java.util.*;

public class verticalsum{

  public static void vertical(TreeNode T){
    if(T == null)
      return;

    HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
    getvertical(T, 0, map);
    
    if(map != null)
      System.out.println(map.entrySet()); 
  }

  public static void getvertical(TreeNode T, int cnt, HashMap<Integer, Integer> map){
    if(T == null)
      return;
  
   int sum;
   getvertical(T.left, cnt-1, map);
   if(map.get(cnt) == null)
     sum = 0;
   else
     sum = map.get(cnt);   
   map.put(cnt, sum+T.data);
   getvertical(T.right, cnt+1, map);
 
  }  

  public static void main(String[] args){
    TreeNode T = new TreeNode(1);
    T.left = new TreeNode(2);
    T.right = new TreeNode(3);
    T.left.left = new TreeNode(4);
    T.left.right = new TreeNode(5);
    T.right.left = new TreeNode(6);
    T.right.right = new TreeNode(7);
  
    vertical(T);
  }
}
