#include <stdio.h>
#include <cs50.h>
int main()
{
    string answer = get_string("What is your name");
    printf("Hello %s\n", answer);
    return 0;
}