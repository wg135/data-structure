
public rand5_generate_rand7{

  int rand7(){
	while(1){
	  int rand = 5 * (rand5() - 1);
	  rand = rand + rand5()-1;
	  if(rand < 22 && rand > 0)
	    return rand % 7 + 1;
	}
  }
}
