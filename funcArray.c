#include <stdio.h>
#include <stdlib.h>

double min(double a, double b)
{
    return(a < b ? a : b);
}
double max(double a, double b)
{
    return(a > b ? a : b);
}
double sum(double a, double b)
{
    return(a + b);
}
double diff(double a, double b)
{
    return(a - b);
}
double mult(double a, double b)
{
    return(a * b);
}
double divid(double a, double b)
{
    return(a / b);
}
double ex(double x, double y)
{
    return 0;
}

int recFunc(double* a, double* b, int* action, double (*operations[7])(double, double))
{
    printf("Введите первое число: ");
    scanf("%lf", &*a);
    printf("Введите второе число: ");
    scanf("%lf", &*b);
    printf("Что сделать с введёнными числами?\nПоказать наименьшее - 0\nПоказать наибольшее - 1\nПоказать сумму - 2\nПоказать разность - 3\nПоказать произведение - 4\nПоказать частное- 5\nВыйти из программы - 6\nВведите число: ");
    scanf("%d", &*action);
    if (*action == 6)
    {
        exit;
    }else if(*action == 0 || *action == 1 || *action == 2 || *action == 3 || *action == 4 || *action == 5)
    {
        printf("Результат: %lf\n", operations[*action](*a, *b));
        recFunc(&*a, &*b, &*action, operations);
    }else
    {
        printf("Вы ввели невалидное значение, начнём заново...\n");
        recFunc(&*a, &*b, &*action, operations);
    }
}

int main(void)
{
    double a;
    double b;
    int action;
    double (*operations[7])(double, double) = {min, max, sum, diff, mult, divid, ex};
    int length = sizeof(operations)/sizeof(operations[0]);
    recFunc(&a, &b, &action, operations);
}