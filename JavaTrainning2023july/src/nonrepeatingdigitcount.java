import java.io.*;
import  java.util.*;
import java.lang.Math;

class UserMainCode{
  public int nonRepeatDigitsCount(int input1){
        int i=input1;
        int count=0;
        
        int length = (int) (Math. log10(input1) + 1);
        
        int[] arr=new int[length];
        i=input1;
        int n=0;
        while(i>0){
            arr[n]=i%10;
            i=i/10;
            n++;
        }
        for(int j=0; j<length; j++){
            int check=0;
            for (int k=0;k<length;k++){
                if(j!=k){
                    if(arr[j]==arr[k]){
                        check++;
                    }
                }

            }
            if (check==0){
                count++;
            }
        }
        return count;
    }
}
