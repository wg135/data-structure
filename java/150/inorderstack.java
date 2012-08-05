import java.util.*;

public class inorderstack{

  public static void print(TreeNode T){
   Stack<TreeNode> s = new Stack<TreeNode>();
   TreeNode tmp = T;
   boolean done = false;
   if(tmp == null)
    return;

   while(done == false){
     if(tmp != null){
       s.push(tmp);
       tmp = tmp.left;
     }
     else{
      if(!s.empty()){
        tmp = s.pop();
        System.out.printf("%d ", tmp.data);
        tmp = tmp.right;
      }
      else{
        done = true;
      }
     }
   }
   
  System.out.print("\n"); 
    
  }
  
  public static void main(String[] args){
    TreeNode T = new TreeNode(1);
    T.left = new TreeNode(2);
    T.right = new TreeNode(3);
    T.left.left = new TreeNode(4);
    T.left.right = new TreeNode(5);
    print(T);
  }
}
