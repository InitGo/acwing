# include <cstdio>
int main()
{   
    int a = 10;
    int b = 12;
    const int *p = &a;  //p指向的内容不能变
    int* const p2 = &b;  //p2的指向不能变
    int *q = &a;
    *q = 20;
    printf("a = %d\n", a);
    a = 30;
    printf("a = %d\n", a);
    //*p = 30;  //这么写就是错的 p指向的内容不能通过p改变

    printf("b = %d\n", b);
    *p2 = 30;
    printf("b = %d\n", b);
    return 0;
}