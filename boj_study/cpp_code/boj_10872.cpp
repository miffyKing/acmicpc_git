#include <cstdio>

int factorial(int n)
{
    if(n <= 1)
        return 1;
    return n * factorial(n-1);
}

int main() {
    int num;
    scanf("%d",&num);
    printf("%d",factorial(num));
}
