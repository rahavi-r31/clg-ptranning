public int isPalinNum(int input1){
int i=0,rev=0,r;
        int n=input1;
        while(n!=0){
            r=n%10;
            rev=rev*10+r;
            n=n/10;
        }
        if (input1==rev){
            return 2;
        }
        return 1;
	}
