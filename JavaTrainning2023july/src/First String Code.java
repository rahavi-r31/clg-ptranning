public int firststringcode(String input1){
  String[] a=input1.split("\\W+");
  int s1=0,n=0,s=0;
  for (String i:a){
     s1 = s1 + i.length();
     }
  if (s1>9){
     n=s1;
     while(n!=0){
         s=s+n%10;
         n=n/10;
    }
    s1=s;
  }
  return s1;
}
