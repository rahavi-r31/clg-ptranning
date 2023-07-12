int NthPrime(int input1){
  int num=1,count=0,i;
    while (count < input1)  
    {  
        num=num+1;  
        for (i = 2; i <= num; i++)  
        {   
        //determines the modulo and compare it with 0   
            if (num % i == 0)   
            {  
            //breaks the loop if the above condition returns true  
                break;  
            }  
        }  
        if (i == num)  
        {  
        //increments the count variable by 1 if the number is prime  
            count = count+1;  
        }  
    }  
    return num;
    
}
