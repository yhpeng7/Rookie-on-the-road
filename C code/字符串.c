/*字符串逆置*/
void reverse(char s[])
{
    int c,i,j;
    for(i = 0,j = strlen(s) - 1;i < j;i++,j--)
        c = s[i],s[i] = s[j],s[j] = c;
}

/*将字符串转化为整数*/
int Atoi(char s[])
{
    int i,n,sign;
    for(i = 0;isspace(s[i]);i++)
        ;
    sign = (s[i] == '-') ? -1:1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(n = 0;isdigit(s[i]);i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

/*整数转化为字符串*/
void Itoa(int n,char s[])
{
    int sign,i = 0;
    if((sign = n) < 0)
        n = -n;

    do
        s[i++] = n % 10 + '0';
    while(n /= 10);

    if(sign < 0)
        s[i++] = '-';
        s[i] = '\0';

    reverse(s);
}

/*BF算法*/
int StrIndex(char s[],char t[],int pos)
{

    int i = pos,j = 0;
    while(s[i] && t[j])
    {
        if(s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if(t[j] == 0)
        return i - j;
    else
        return -1;
}

/*字符串替换*/
char *StrReplace(char *str,char *s1,char *s2)
{
    char *s = (char *)malloc(100 * (sizeof(char)));

    memset(s,0,100 * (sizeof(char)));
    char buf[100];
    //while(*s++ = *str++);
    strcpy(s,str);
    char *pStr = strstr(s,s1);
    while(pStr)
    {
        strcpy(buf,pStr + strlen(s1));
        strcpy(pStr,s2);
        pStr += strlen(s2);
        strcpy(pStr,buf);
        pStr = strstr(pStr,s1);
    }
    str = s;
    return str;
}