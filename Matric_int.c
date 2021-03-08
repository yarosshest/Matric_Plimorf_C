#include <stdio.h>
#include "Matric_int.h"
#include "Matric .h"
#include "stdlib.h"
#include <assert.h>

struct Matric init_int_Matric(int element_size, int size,void* ar)
{
    assert(size > 0);
    struct Matric_int *arT = (struct Matric_int* ) calloc(1, sizeof (struct Matric_int));
    arT->mas = ar;

    struct Matric cont = init_Matric(arT);

    cont.mult = mult_int_Matric;
    cont.sum = sum_int_Matric;
    cont.trans = trans_int_Matric;
    cont.element_size = element_size;
    cont.size = size;
    cont.print = print_int_Matric;

    return cont;
}
struct Matric mult_int_Matric(struct Matric mat1, struct Matric mat2)
{
    assert(mat1.size == mat2.size);
    assert(mat1.element_size == mat2.element_size);

    struct Matric_int m1 = *( struct Matric_int *)(mat1.arT);
    struct Matric_int m2 = *( struct Matric_int *)(mat2.arT);

    int size =mat1.size;

    int *mr = (int*)calloc(1,size * size * sizeof(int));
    struct Matric ret = init_int_Matric(sizeof(int),size,mr);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <size;j++)
        {
            mr[i*size+j] = 0;
            for(int z = 0; z < size; z++)
            {
                mr[i*size+j] = mr[i*size+j] + m1.mas[i*size+z]*m2.mas[z*size+j];
            }
        }
    }
    return ret;
}

struct Matric sum_int_Matric(struct Matric mat1, struct Matric mat2)
{
    assert(mat1.size == mat2.size);
    assert(mat1.element_size == mat2.element_size);

    struct Matric_int m1 = *( struct Matric_int *)(mat1.arT);
    struct Matric_int m2 = *( struct Matric_int *)(mat2.arT);

    int size =mat1.size;

    int *mr = (int*)calloc(1,size * size * sizeof(int));
    struct Matric ret = init_int_Matric(sizeof(int),size,mr);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <size;j++)
        {
            mr[i*size+j] = 0;
            mr[i*size+j] = mr[i*size+j] + m1.mas[i*size+j]+m2.mas[i*size+j];
        }
    }
    return ret;
}

struct Matric trans_int_Matric(struct Matric mat1)
{
    struct Matric_int m1 = *( struct Matric_int *)(mat1.arT);

    int size =mat1.size;

    int *mr = (int*)calloc(1,size * size * sizeof(int));
    struct Matric ret = init_int_Matric(sizeof(int),size,mr);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <=i;j++)
        {
            int b = m1.mas[i*size+j];
            mr[i*size+j] = m1.mas[j*size+i];
            mr[j*size+i] = b;
        }
    }
    return ret;
}



void print_int_Matric(struct Matric mat)
{
    struct Matric_int m = *( struct Matric_int *)(mat.arT);

    int size =mat.size;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            printf(" %d |",m.mas[i*size+j]);
        }
        printf("\n");
    }
}

int * vvod_int_Matric(int size)
{
    int *a = (int*)calloc(1,size*size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            scanf("%d", &a[i*size+j]);
        }
    }
    return a;
}

