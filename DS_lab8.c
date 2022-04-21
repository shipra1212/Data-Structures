// LAB 8 Naive Pattern Searching algorithm
#include <stdio.h>
#include <string.h>
 
void search(char* pat, char* txt)
{
    int m = strlen(pat);
    int n= strlen(txt);
 
    /* sliding patern one by one */
    int i;
    for(i = 0; i <= n - m; i++) 
	{
        int j;
 
        //checking pattern match for current i
        for (j = 0; j < m; j++)
            if (txt[i + j] != pat[j])
                break;
 
        if (j == m) 
            printf("Pattern found at index %d \n", i);
    }
}
 
 
int main()
{
    char txt[] = "AABAACAADAABAAABAA";
    char pat[] = "AABA";
    search(pat, txt);
    return 0;
}
