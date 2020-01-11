#include<stdio.h>
#include<string.h>
char array[20]={'c','a','g','c'};
int sufpref(int s,char sc);
int step=0,count=0;
int main()
{
    int n=strlen(array)-1,i;
    char c;
    for(i=0;i<10;i++)
    {
        scanf("%c",&c);
        if(array[step+1]==c)
        {
            step++;
            if(step == n)
            {
                count++;
                step=0;

            }
        }
        else
        {
            step = sufpref(step,c);
            if(step == n)
            {
                count++;
                step=0;

            }

        }

    }
    printf("Found %d times\n",count);

}
//creating highest number of suffuxes and prefixes which are same and returning the result.
int sufpref(int s,char sc)
{
    char temp[s+1];
    int i,x=s+1,flag=0,step;
    for(i=0;i<s;i++)
    {
        temp[i]=array[i+1];
    }
    temp[s]=sc;
    for(int j=1;j<x;j++)
    {
        char s[x-1],p[x-1];
        for(i=0;i<x-j;i++)
        {
            s[i]=temp[i];
            p[i]=temp[i+j];

        }
        if(!strcmp(s,p)){
            flag++;
            step=x-j;
            break;
        }

    }
    if(flag==0){
        return 0;
    }
    else
    {
        return step;
    }
}
