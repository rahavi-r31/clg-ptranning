int countPrimesInRange(int unput1, int input2){
  int i,j,flag,c=0;
    for (i = input1; i <= input2; i++) {
 
            // Skip 0 and 1 as they are
            // neither prime nor composite
        if (i == 1 || i == 0)
            continue;
 
            // flag variable to tell
            // if i is prime or not
        flag = 1;
 
        for (j = 2; j <= i / 2; ++j) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
 
            // flag = 1 means i is prime
            // and flag = 0 means i is not prime
        if (flag == 1)
            c=c+1;
    }
    return c;

}
