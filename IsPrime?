public int isPrime(int input1){
        if (input1 <= 1)
            return 1;
        // Check if number is 2
        else if (input1 == 2)
            return 2;

        // Check if n is a multiple of 2
        else if (input1 % 2 == 0)
            return 1;

        // If not, then just check the odds
        for (int i = 3; i <= Math.sqrt(input1); i += 2)
        {
            if (input1 % i == 0)
                return 1;
        }
        return 2;

	}
}
