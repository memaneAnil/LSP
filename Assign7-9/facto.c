
int factorial(int no)
{
    int i = 0;
    int fact = 1;

    for(i = 1;i<=no;i++)
    {
        fact = fact * i;
    }

    return fact;
}