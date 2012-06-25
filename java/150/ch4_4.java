import java.util.*;

public class ch4_4{

  public static ArrayList<LinkedList<TreeNode>> creat(TreeNode T){

    ArrayList<LinkedList<TreeNode>> array = new ArrayList<LinkedList<TreeNode>>();
    LinkedList<TreeNode> list = new LinkedList<TreeNode>();
    int level = 0;
    int i;

    list.add(T);
    array.add(0, list);   //store the root
    
    while(true){
      list = new LinkedList<TreeNode>();
      for(i=0; i<array.get(level).size(); i++){
        TreeNode tmp = array.get(level).get(i);
        if(tmp != null){
	  if(tmp.left != null)
             list.add(tmp.left);
          if(tmp.right != null)
             list.add(tmp.right);
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
    TreeNode T = new TreeNode(5);
    T.insert(3);
    T.insert(7);
    T.insert(2);
    T.insert(4);
    T.insert(6);

    ArrayList<LinkedList<TreeNode>> array = creat(T);
    int i, j;
    for(i=0; i<array.size(); i++)
      for(j=0; j<array.get(i).size(); j++)
         System.out.printf("%d ", array.get(i).get(j).data); 
    System.out.print("\n");
  }
}
