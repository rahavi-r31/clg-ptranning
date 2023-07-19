public int isPlaindrome(String input1){
        int strLength = input1.length();
        String reverseStr="";
        for (int i = (strLength - 1); i >=0; --i) {
            reverseStr = reverseStr + input1.charAt(i);
        }

        if (input1.toLowerCase().equals(reverseStr.toLowerCase())) {
            return 2;
        }
        else {
            return 1;
        }
	}
