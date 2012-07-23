/*Given two Binary Search Trees(BST), print the elements of both BSTs in sorted form. The expected time complexity is O(m+n) where m is the number of nodes in first tree and n is the number of nodes in second tree. Maximum allowed auxiliary space is O(height of the first tree + height of the second tree)
*/

import java.util.*;

public class mergebst{

  public static void merge2bst(TreeNode T1, TreeNode T2){
    
    Stack<TreeNode> S1 = new Stack<TreeNode>();
    Stack<TreeNode> S2 = new Stack<TreeNode>();
    TreeNode node1, node2;

    node1 = T1;
    node2 = T2;

    //tree1 is empty, just need inorder travel tree2
    if(node1 == null){
      inorder(node2);
      System.out.print("\n");
      return;
    }

    //tree2 is empty, just need inorder travel tree1
    if(node2 == null){
      inorder(node1);
      System.out.print("\n");
      return;
    }

    while((node1 != null)||(node2 != null)||(!S1.empty())||(!S2.empty())){
      if((node1 != null)||(node2 != null)){
       //reach the left most node
	if(node1 != null){
	  S1.push(node1);
          node1 = node1.left;
        }
        if(node2 != null){
	  S2.push(node2);
 	  node2 = node2.left;
        }
      }
      else{
	if(S1.empty()){//tree1 is done, print rest of t2;
	  while(!S2.empty()){
 	    node2 = S2.pop();
	    node2.left = null;
            inorder(node2);
          }
          return;
        }
        if(S2.empty()){//tree2 is done, print rest of t2
 	  while(!S1.empty()){
            node1 = S1.pop();
 	    node1.left = null;
	    inorder(node1); 
          }
          return;
        }

        node1 = S1.pop();
        node2 = S2.pop();

        if(node1.data < node2.data){//node1 is smaller, 
	  System.out.printf("%d ", node1.data);
          node1 = node1.right;
 	  S2.push(node2);
          node2 = null;
        }
        else{//node2 is smaller
	  System.out.printf("%d ", node2.data);
          node2 = node2.right;
          S1.push(node1);
          node1 = null;
        }
      }
    }


   
    
  }

  public static void inorder(TreeNode T){
    if(T == null)
      return;
    inorder(T.left);
    System.out.printf("%d ", T.data);
    inorder(T.right);
  }
  
  public static void main(String[] args){
    TreeNode T1 = new TreeNode(3);
    T1.left = new TreeNode(1);
    T1.right = new TreeNode(5);

    TreeNode T2 = new TreeNode(4);
    T2.left = new TreeNode(2);
    T2.right = new TreeNode(6);
    merge2bst(T1, T2);
    System.out.print("\n");
  }
} 
