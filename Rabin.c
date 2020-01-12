#include<stdio.h>
#include<string.h>

#define d 256

void sFunc(char pat[], char txt[], int q)
{
    int patternLen = strlen(pat);
    int txtLen = strlen(txt);
    int i, j;
    int pHash = 0; 
    int tHash = 0; 
    int h = 1;
    for (i = 0; i < patternLen-1; i++)
        h = (h*d)%q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < patternLen; i++)
    {
        pHash = (d*pHash + pat[i])%q;
        tHash = (d*tHash + txt[i])%q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= txtLen - patternLen; i++)
    {

        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters on by one
        if ( pHash == tHash )
        {
            /* Check for characters one by one */
            for (j = 0; j < patternLen; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == patternLen)
                printf("Pattern found at index %d \n", i);
        }

        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if ( i < txtLen- patternLen )
        {
            tHash = (d*(tHash - txt[i]*h) + txt[i+patternLen])%q;

            // We might get negative value of t, converting it
            // to positive
            if (tHash < 0)
            tHash = (tHash + q);
        }
    }
}

int main()
{   char txt[80],pat[80];
    int q;
    printf("Enter text \n");
    scanf("%s",txt);
    printf("Enter a pattern \n");
    scanf("%s",&pat);
    printf("Enter a prime number \n");
    scanf("%d",&q);
    sFunc(pat, txt, q);
    return 0;
}