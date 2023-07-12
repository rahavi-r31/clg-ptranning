class IserMainCode{
  public int nFactorial(int input1){
    if (input1==1){
            return 1;
        }
        else{
            return ((input1)*nFactorial(input1-1));
        }
	  }
}
