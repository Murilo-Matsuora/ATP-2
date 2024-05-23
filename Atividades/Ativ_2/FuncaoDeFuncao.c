#include <stdlib.h>
#include <stdio.h>

float func1(int a){
    float x;
    x = 1/(a-5.0);
    return x;
}
float func2(int a){
    return 1/(a-5.3213);
}

int main(){
    int a;
    float b, c;
    scanf("%d", &a);

    b=func1(a);
    printf("%f \n", b);

    printf("%f \n",func1(a));

    c=func2(a);
    printf("%f \n", c);

    printf("%f \n",func2(a));

    printf("%p   %p \n", &func1, &func2);

    return 0;
}