#include <stdio.h>

#define n 4

int top = -1;

struct Interval {
    int start;
    int end;
};

struct Interval s[n];

void push(struct Interval x)
{
    
    top++;
    s[top] = x;
}

struct Interval pop()
{
    struct Interval x;

   
    x = s[top];
    top--;

    return x;
}

int main()
{
    int i, j;
    struct Interval a[n];

  
    for (i = 0; i < n; i++)
    {
        printf("Enter Interval %d: ", i + 1);
        scanf("%d %d", &a[i].start, &a[i].end);
    }

   
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i].start > a[j].start)
            {
                struct Interval temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }


    push(a[0]);

 
    for (i = 1; i < n; i++)
    {
        if (a[i].start <= s[top].end)
        {
            
            if (a[i].end > s[top].end)
            {
                s[top].end = a[i].end;
            }
        }
        else
        {
      
            push(a[i]);
        }
    }

  
    printf("\nMerged Intervals:\n");

    for (i = 0; i <= top; i++)
    {
        printf("%d %d\n", s[i].start, s[i].end);
    }

    return 0;
}
