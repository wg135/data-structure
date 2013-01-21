public class TreeNode{
  
  TreeNode left;
  int data;
  TreeNode right;

  public TreeNode(int value){
    data = value;
    left = null;
    right = null;
  }
  
  public void insert(int value){
    if(value < data){
      if(left == null)
        left = new TreeNode(value);
      else
        left.insert(value);
    }
   else if(value > data){
     if(right == null)
       right = new TreeNode(value);
     else
       right.insert(value);
   }
  }
  
}
