#include <stdio.h>
#include "Matric .h"
#include "Matric_int.h"
#include "stdlib.h"
#include "string.h"
#include "compl_num.h"
#include "Matric_compl.h"
int main() {
    int pass = 0;
    int type;
    int size;

    printf("выберите тип матрицы\n");
    while (pass == 0)
    {
        printf("1-матрица целых числел || 2-матрица комплексынх числел \n");
        scanf("%d", &type);
        if ((type == 1) || (type == 2))
        {
            pass = 1;
        }
        else
        {
            printf("введите значение из преложенных!\n");
            printf("________________________________\n");
        }
    }
    while (pass == 1)
    {
        printf("выберите размер матрицы n>0\n");
        scanf("%d", &size);
        if (size > 0)
        {
            pass = 2;
        }
        else
        {
            printf("введите значение из больше 0\n");
            printf("____________________________\n");
        }
    }

    struct Matric Mat1;
    if (type == 1)
    {
        printf("Введите элементы матрицы\n");
        Mat1 = init_int_Matric(sizeof(int), size, vvod_int_Matric(size));
    }
    else if (type == 2)
    {
        printf("Введите элементы матрицы, разделяя вещественную часть и мнимою пробелом\n");
        Mat1 = init_compl_Matric(sizeof(struct compl), size, vvod_compl_Matric(size));
    }
    printf("____________________________\n");
    printf("Вы ввели матрицу:\n");
    print_Matric(Mat1);
    printf("____________________________\n");

    int action;
    printf("выберите действие над матрицей\n");
    while (pass == 2)
    {
        printf("1-Умножение || 2-Сложение || 3-Транспонирование \n");
        scanf("%d", &action);
        if ((action == 1) || (action == 2) || (action == 3))
        {
            pass = 3;
        }
        else
        {
            printf("введите значение из преложенных!\n");
            printf("________________________________\n");
        }
    }
    printf("________________________________\n");
    if (action ==1)
    {
        printf("Введите элементы матрицы второй матрицы для умножения\n");
        struct Matric Mat2;
        struct Matric Mat0;
        if (type == 1)
        {
            char* mr = (char*)calloc(1,size * size * sizeof(int));
            Mat0 = init_int_Matric(sizeof(int), size, mr);
            Mat2 = init_int_Matric(sizeof(int), size, vvod_int_Matric(size));
        }
        else if (type == 2)
        {
            char* mr = (char*)calloc(1,size * size * sizeof(struct compl));
            Mat0 = init_compl_Matric(sizeof(struct compl), size, mr);
            Mat2 = init_compl_Matric(sizeof(struct compl), size, vvod_compl_Matric(size));
        }
        printf("Вы ввели матрицу:\n");
        print_Matric(Mat2);
        printf("________________________________\n");
        mult_Matric(Mat1,Mat2,Mat0);
        printf("Результат умножения:\n");
        print_Matric(Mat0);
    }
    if (action ==2)
    {
        printf("Введите элементы матрицы второй матрицы для суммирования\n");
        struct Matric Mat2;
        struct Matric Mat0;
        if (type == 1)
        {
            char* mr = (char*)calloc(1,size * size * sizeof(int));
            Mat0 = init_int_Matric(sizeof(int), size, mr);
            Mat2 = init_int_Matric(sizeof(int), size, vvod_int_Matric(size));
        }
        else if (type == 2)
        {
            char* mr = (char*)calloc(1,size * size * sizeof(struct compl));
            Mat0 = init_compl_Matric(sizeof(struct compl), size, mr);
            Mat2 = init_compl_Matric(sizeof(struct compl), size, vvod_compl_Matric(size));
        }
        printf("Вы ввели матрицу:\n");
        print_Matric(Mat2);
        printf("________________________________\n");
        sum_Matric(Mat1,Mat2,Mat0);
        printf("Результат сложения:\n");
        print_Matric(Mat0);
    }
    if (action ==3)
    {
        struct Matric otv = Mat1.trans(Mat1);
        printf("Результат транспонирования:\n");
        otv.print(otv);
    }
    return 0;
}
