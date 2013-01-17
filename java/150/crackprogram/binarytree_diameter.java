//Diameter of a Binary Tree
public class binarytree_diameter{

  public static int diameter(TreeNode T){
	int depth_left = 0;
	int depth_right = 0;
	int diameter_left = 0;
	int diameter_right = 0;
	
        if(T == null)
	  return 0;

	depth_left = depth(T.left);
	depth_right = depth(T.right);
	
	diameter_left = diameter(T.left);
	diameter_right = diameter(T.right);
   
       return Math.max((1 + depth_left + depth_right), Math.max(diameter_left, diameter_right));
	

  }
  
  public static int depth(TreeNode T){
	if(T == null)
	  return 0;
        return 1+ Math.max(depth(T.left), depth(T.right));	
  }

  public static void main(String[] args){

	TreeNode T = new TreeNode(1);
	T.left = new TreeNode(2);
	T.right = new TreeNode(3);
	System.out.printf("%d\n",diameter(T));
  }
}
