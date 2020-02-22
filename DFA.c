#include<stdio.h>
#include<string.h>
char pattern[20];
char text[200];
int sufpref(int s,char sc);
int DFA(char patttern[],char text[]);
int step=0,count=0;

int main()
{   
    int pa,te;
    printf("\nEnter the pattern(Without space): ");
    scanf("%s",&pattern);
    printf("%s\n",pattern);
    printf("\nEnter the Text(Without space): ");
    scanf("%s",&text);
    printf("%s\n",text);
    int x = DFA(pattern,text);
    printf("%d\n",x);
}
int DFA(char patttern[],char text[])
{
    int n=strlen(pattern)-1,i,m = strlen(text)-1;
    char c;
    for(i = 0;i<m;i++){
        c = text[i];
        if(pattern[step+1]==c)
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
    return count;
}
//creating highest number of suffuxes and prefixes which are same and returning the result.
int sufpref(int s,char sc)
{
    char temp[s+1];
    int i,x=s+1,flag=0,step;
    for(i=0;i<s;i++)
    {
        temp[i]=pattern[i+1];
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
