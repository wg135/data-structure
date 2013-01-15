//Print Bianry Tree Level
import java.util.*;

public class TreeLevelPrint{

  public static ArrayList<LinkedList<TreeNode>> getlevel(TreeNode T){
    ArrayList<LinkedList<TreeNode>> result = new ArrayList<LinkedList<TreeNode>>();
    LinkedList<TreeNode> list = new LinkedList<TreeNode>();
  
    int level = 0;
    boolean done = false;
    if(T == null)
	return null;
    list.add(T);
    result.add(0, list);
    
    while(done == false){
	list = new LinkedList<TreeNode>();
	for(int i=0; i<result.get(level).size(); i++){
		TreeNode tmp = result.get(level).get(i);
		if(tmp != null){
			if(tmp.left != null)
			  list.add(tmp.left);
 		        if(tmp.right != null)
			  list.add(tmp.right);
		}
        }
        if(list.size() > 0)
		result.add(level+1, list);
	else
	  done = true;
  
        level++;	
    }

   return result;    
  }
  
  public static void main(String[] args){
    TreeNode T = new TreeNode(5);
    T.insert(3);
    T.insert(7);
    T.insert(2);
    T.insert(4);
    T.insert(6);

    ArrayList<LinkedList<TreeNode>> array = getlevel(T);
    for(LinkedList<TreeNode> list : array){
	for(TreeNode node : list)
	   System.out.printf("%d ", node.data);
        System.out.printf("\n");
    }
		

  }
}
