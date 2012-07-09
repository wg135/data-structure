/* Create a data structure twoStacks that represents two stacks. 
Implementation of twoStacks should use only one array */

public class twostack{

  int[] array;
  int top1;
  int top2;
  int size;

  public twostack(int n){
    array = new int[n];
    top1 = -1;
    top2 = n;
    size = n;   
  }

  public void push1(int x){
    if(top1 < top2-1){
      top1++;
      array[top1] = x;
    }
    else{
      System.out.println("overflow");
    } 
  }
  

  public void push2(int x){
    if(top1 < top2-1){
      top2--;
      array[top2] = x;
    }
    else
      System.out.println("overflow");
  }

  public int pop1(){
    if(top1 >= 0){
      int x = array[top1];
      top1--;
      return x;
    }
    else
      System.out.println("overflow");
  }
  
  public int pop2(){
    if(top2 < size){
      int x = array[top2];
      top2++;
      return x;
    }
    else
      System.out.println("overflow");
  }
  
  public static void main(String[] args){
   twostack s = new twostack(10);
  }
}
