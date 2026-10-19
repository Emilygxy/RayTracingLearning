#include<stdio.h>

int main(void)
{
    int a = 1;
    if (a == 1)
    {
        goto end_tag; // meet the condition, then to end_tag
    }

    printf("Not Excute Here!! \n");
end_tag:
    printf("goto: Excute Here!! \n");

    return 0;
}

