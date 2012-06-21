public class ch3_1a{
  int stack_size = 5;
  int[] array = new int[stack_size * 3];
  int[] stack_pointer = {0, 0, 0};

  public void push(int stack_number, int data){
    int index = stack_number * stack_size + stack_pointer[stack_number] + 1;
    array[index] = data;
    stack_pointer[stack_number]++;
  }

  public int pop(int stack_number){
    int value;
    int index = stack_number *stack_size + stack_pointer[stack_number];
    stack_pointer[stack_number]--;
    value =  array[index];
    array[index] = 0;
    return value;
  }
  
  public int peek(int stack_number){
    int index = stack_number *stack_size + stack_pointer[stack_number];
    return array[index];
  }
  
  public boolean isempty(int stack_number){
    return stack_pointer[stack_number] == stack_size;
  }
  
  public static void main(String[] args){
   int i;
   ch3_1a stack = new ch3_1a();
   for(i=0; i<3; i++)
    stack.push(0, i);
  
   for(i=0; i<3; i++)
    System.out.println(stack.pop(0));  
  }
}
