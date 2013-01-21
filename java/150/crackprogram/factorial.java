import java.math.BigInteger;

public class factorial{

  public static BigInteger fact(int count){
	BigInteger result = BigInteger.valueOf(1);
	for(int i=1; i<= count; i++)
	  result = result.multiply(BigInteger.valueOf(i));
	
	return result;
  }
  public static void main(String[] args){
     System.out.println(fact(8));    
  }
}
