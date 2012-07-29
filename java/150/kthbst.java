/*
Given root of binary search tree and K as input, find K-th smallest element in BST
*/

import java.util.*;

public class kthbst{

  public static TreeNode find(TreeNode T, int k){
    Stack<TreeNode> S = new Stack<TreeNode>();
    return findutil(T, S, k);
  } 

  public static TreeNode findutil(TreeNode T, Stack<TreeNode> S, int k){
    TreeNode tmp = T;
    
    while(tmp != null){
      S.push(tmp);
      tmp = tmp.left;
    }
    
    while(S.peek() != null){
      tmp = S.pop();
      if(--k == 0)
        break;
      if(tmp.right != null){
        tmp = tmp.right;
        while(tmp != null){
          S.push(tmp);
          tmp = tmp.left;
        }
      }
   
    }
    return tmp;
  } 

  public static void main(String[] args){
    TreeNode T = new TreeNode(20);
    T.left = new TreeNode(8);
    T.right = new TreeNode(22);
    T.left.left = new TreeNode(4);
    T.left.right = new TreeNode(12);
    T.left.right.left = new TreeNode(10);
    T.left.right.right = new TreeNode(14);
    TreeNode tmp = find(T, 3);
    System.out.printf("%d\n", tmp.data); 
  }
}
