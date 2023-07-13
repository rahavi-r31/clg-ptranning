public int digitsum(int input1){
  int n=input1;
  int s=0;
  while(n>0){
    s=s+n%10;
    n=n/10;
  }
  if(s<=9){
    return s;
  }
  else{
    return digitsum(s);
  }
}
