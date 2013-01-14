//get sqrt of a number
public class mysqrt{

  public static double gao_sqrt(double x){
    if(x <0)
        return -1;
    if((x==0)||(x==1))
	return x;
    
    double prev = 0.00001;
    double start = 0;
    double end = x;
    if(x < 1)
	end = 1;

    while((end-start) > prev){
	double middle= start + (end - start) / 2;
	double mid_sq = middle * middle;
        if(mid_sq == x)
	  return mid_sq;
        else if(mid_sq > x)
	      end = middle;
	else
	    start = middle;  
    } 

     return x/2;
  }

  public static void main(String[] args){

  }
}
