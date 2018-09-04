/*判断素数*/
bool IsPrime(int key)
{
    int i;
    int temp = sqrt(key);
    if(key < 2)
        return false;
    for(i = 2;i <= temp;i++)
        if(key % i == 0)
        return false;
    return true;
}

