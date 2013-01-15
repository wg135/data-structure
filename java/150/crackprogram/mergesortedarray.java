//Merge Two Sorted Arrays
public class mergesortedarray{

  public static void merge2(int[] a, int b[], int lastA, int lastB){
	int last_index = lastA + lastB -1;
        lastA--;//last index of a 
	lastB--;//last index of b
	while((lastA >= 0) && (lastB >= 0)){
		if(a[lastA] > b[lastB]){
		  a[last_index--] = a[lastA--];
		}
                else
		  a[last_index--] = b[lastB--];
	}    
       while(lastB >=0)//a is already in sorted
	  a[last_index--] = b[lastA--];
  }

  public static void main(String[]  args){
	int[] a = new int[10];
        int[] b = {2, 4, 6, 8, 10};
        for(int i=0; i<5; i++)
	  a[i] = 2*i +1;
        merge2(a, b, 5, 5);
        for(int element : a)
		System.out.printf("%d ", element);
   	System.out.printf("\n");

  }
}
