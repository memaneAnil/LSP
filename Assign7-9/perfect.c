
int checkPerfect(int no)
{
    int i = 0;
    int iSum = 0;

    for(i = 1;i<=(no/2);i++)
    {
        if(no%i == 0)
        {
            iSum = iSum + i;
        }
    }
    if(iSum == no)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}