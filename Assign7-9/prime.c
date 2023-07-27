
int checkPrime(int no)
{
    int i = 0;

    for(i = 2;i<=(no/2);i++)
    {
        if(no%i == 0)
        {
            break;
        }
    }
    if(i == (no/2)+1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}