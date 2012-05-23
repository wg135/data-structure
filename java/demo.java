class Swaper{
  
  int x, y;
  public Swaper(int x, int y){
    super();
    this.x = x;
    this.y = y;
  }
  
  public Swaper swap(){
    return new Swaper(this.y, this.x);
  }
}

public class demo{

  public static void main(String[] args){
    int x = 3;
    int y = 4;
    
    Swaper swaper = new Swaper(x, y);
  
    x = swaper.swap().x;
    y = swaper.swap().y;
    System.out.println(x +" "+ y);
  
    
  }
}
