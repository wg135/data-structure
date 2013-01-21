public class LRU{

  public static int MAX_SIZE = 100;
  public Node head, tail;
  public HashMap<String, Node> map;	
  public LinkedList<Node> list;
  public int size = 0;

  public LRU(){
	map = new HashMap<String, Node>();
	list = new LinkedList<Node>();
  }

  //move node to front of linkedlist
  public void movetofront(Node node){...}
  
  //remove node from the linkedlist
  public void remove(Node node){...}
  
  //get the query result and update the cache
  public String[] getresult(String query){
	if(!map.containsKey(query))
	  return null;
 	
	Node node = map.get(query);
	movetofront(node);
	return node.result;
  }

  public void insert(String query, String[] results){
	if(map.containsKey(query)){ //update the result;
	  Node node = map.get(query);
	  node.result = results;
	  movetofront(node);
	  return;
	}
	Node node = new Node(query, results);
	movetofront(node);
	map.put(query, node);
	
	if(size > MAX_SIZE){
	  map.remove(tail.query);
	  remove(tail);
	}
  }
}
