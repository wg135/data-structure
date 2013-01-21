
import java.util.*;

public class treelevelprint{
 
  public static ArrayList<LinkedList<TreeNode>> treelevel(TreeNode T){
	ArrayList<LinkedList<TreeNode>> array = new ArrayList<LinkedList<TreeNode>>();
	LinkedList<TreeNode> list = new LinkedList<TreeNode>();
  	int level = 0;
	list.add(T);
	array.add(0, list);
	
	while(true){
	  list = new LinkedList<TreeNode>();
	  for(int i=0; i<array.get(level).size(); i++){
	    TreeNode tmp = array.get(level).get(i);
	    if(tmp != null){
	      if(tmp.left != null){
		list.add(tmp.left);
	      }
	      if(tmp.right != null){
		list.add(tmp.right);
	      }	
	    }
	  }
	  if(list.size() > 0)
	    array.add(level+1, list);
	  else
	    break;
	
	  level++;
	}
	return array;
  }  

  public static void main(String[] args){
    TreeNode T = new TreeNode(2);
    T.insert(1);
    T.insert(3);		
  }
}
