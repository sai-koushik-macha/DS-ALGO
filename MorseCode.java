package com.Sum;
import java.util.Scanner;
interface  code1
    {
        String encodel(char x);
    }
    interface i2
    {
        char decode1(String y);
    }
    class p1 implements code1,i2
    {
        public  String encodel(char x)
        {
            switch (x)
            {
                case 'a':
                    return ".- ";
                case 'b':
                    return "-... ";
                case 'c':
                    return "-.-. ";
                case 'd':
                    return "-.. ";
                case 'e':
                    return ". ";
                case 'f':
                    return "..-. ";
                case 'g':
                    return "--. ";
                case 'h':
                    return ".... ";
                case 'i':
                    return ".. ";
                case 'j':
                    return ".--- ";
                case 'k':
                    return "-.- ";
                case 'l':
                    return ".-.. ";
                case 'm':
                    return "-- ";
                case 'n':
                    return "-. ";
                case 'o':
                    return "--- " ;
                case 'p':
                    return ".--. ";
                case 'q':
                    return "--.- ";
                case 'r':
                    return ".-. ";
                case 's':
                    return "... ";
                case 't':
                    return "- ";
                case 'u':
                    return "..- ";
                case 'v':
                    return "...- ";
                case 'w':
                    return ".-- ";
                case 'x':
                    return "-..- ";
                case 'y':
                    return "-.-- ";
                // for space
                case 'z':
                    return "--.. ";
            }
            return " /";
        }
        void tomorseCode(String s)
        {

            for (int i = 0;i<s.length(); i++)
            {  char ch=s.charAt(i);
                //if(ch== ' ')
                //System.out.print("/");
                System.out.print(encodel(ch));
            }System.out.println();
        }
        public static void main (String args[])
        { Scanner sc= new Scanner(System.in);
            System.out.println("welcome to codeing world.");
            // char ch= sc.next().charAt(0);
            p1 p= new p1();
            // if(ch=='c')
            System.out.println("Enter the data to encode");
            String s = sc.nextLine();
            p.tomorseCode(s);
            System.out.println("Enter to decode ");
            String s2 =sc.nextLine();
            s2=s2.trim();
            p.toenglish(s2);
        }
        void toenglish(String s3)
        {
            String x[]= s3.split(" ");
            for(String s4:x)
            {
                char ch=decode1(s4);
                System.out.print(ch);
            }
        }
        public char decode1(String y)
        {
            if(y.equals(".-"))
                return 'a';
            if(y.equals("-..."))
                return 'b';
            if(y.equals("-.-."))
                return 'c';
            if(y.equals("-.-"))
                return 'd';
            if(y.equals("."))
                return 'e';
            if(y.equals("..-."))
                return 'f';
            if(y.equals("--."))
                return 'g';
            if(y.equals("...."))
                return 'h';
            if(y.equals(".."))
                return 'i';
            if(y.equals(".---"))
                return 'j';
            if(y.equals("-.-"))
                return 'k';
            if(y.equals(".-.."))
                return 'l';
            if(y.equals("--"))
                return 'm';
            if(y.equals("-."))
                return 'n';
            if(y.equals("---"))
                return 'o';
            if(y.equals(".--."))
                return 'p';
            if(y.equals("--.-"))
                return 'q';
            if(y.equals(".-."))
                return 'r';
            if(y.equals("..."))
                return 's';
            if(y.equals("-"))
                return 't';
            if(y.equals("..-"))
                return 'u';
            if(y.equals("...-"))
                return 'v';
            if(y.equals(".--"))
                return 'w';
            if(y.equals(".-"))
                return 'x';
            if(y.equals("-.--"))
                return 'y';
            if(y.equals("--.."))
                return 'z';
            else
                return '@';
        }
    }

