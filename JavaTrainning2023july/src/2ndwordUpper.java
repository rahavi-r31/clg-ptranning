public String secondWordUpperCase(String input){
		String n=input1;
        String[] name = n.split(" ");
        if (name.length<2)
            return ("LESS");
        return name[1].toUpperCase();
}
