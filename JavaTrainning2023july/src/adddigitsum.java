public int odddigitsum(int input1){
int n=input1;
        int s=0;
        while(n>0){
            if ((n%10)%2!=0){
                s=s+(n%10);
            }
            n=n/10;
        }
        return s;
	}
