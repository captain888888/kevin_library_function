#include <stdio.h>
#define LENGTH 4
char buffer [LENGTH]; //Used to store converted Hex string ,can define the LENGTH as need

char * inttohex(int integer)
{
    static int i = 0;
    if (integer < 16)            //Recursive termination condition
    {
        if (integer < 10)        //Convert current number into characters and placed in string
            buffer[i] = integer + '0';
        else
            buffer[i] = integer - 10 + 'A';
            buffer[i+1] = '\0'; //End of string flag
    }
    else
    {
        inttohex(integer / 16);  //call Recursive function
        i++;
        integer %= 16;
        if (integer < 10)
            buffer[i] = integer + '0';
        else
            buffer[i] = integer - 10 + 'A';
    }
    return (buffer);
}

void main()
{
    int i = 0;
    printf("result is %s\n",inttohex(1200));
    for (i = 0;i <4 ;i++)
    {
        printf("buffer[%d] is %c\n",i,buffer[i]);
    }
}
