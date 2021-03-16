#include <stdio.h>
#include "Matric_int.h"
#include "Matric.h"
#include "stdlib.h"
#include <assert.h>
#include <stdbool.h>
void* sum_el_int(void* el1, void* el2)
{

    int a1 = *((int*) el1);
    int a2 = *((int*) el2);
    int* sum =  (int*) calloc(1,sizeof(int));
    *sum = a1 + a2;
    return sum;
}

void* mult_el_int(void* el1, void* el2)
{
    int a1 = *((int*) el1);
    int a2 = *((int*) el2);
    int* mult =  (int*) calloc(1,sizeof(int));
    *mult = a1 * a2;
    return mult;
}

bool equal_el_int(void *el1,void *el2)
{
    int a1 = *((int*) el1);
    int a2 = *((int*) el2);
    bool flag;

    if (a1 == a2)
    {
        flag = true;
    }
    else
    {
        flag = false;
    }
    return flag;
}

void print_el_int_Matric(void* el)
{
    int a = *(int*) el;
    printf(" %d |",a);
}

void ** zero_int_Matric(int size)
{
    int* a = (int *) calloc(1, size * size * sizeof(int));
    void** ar = (void **) calloc(1,size * size*sizeof(a));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            a[i*size+j] = 0;
            ar[i*size+j] = &a[i*size+j];

        }
    }
    return ar;
}

struct Matric init_int_Matric(int size,void** ar)
{
    assert(size > 0);
    struct Matric cont;

    cont.element_size = sizeof(int);
    cont.size = size;

    cont.zero_matric = zero_int_Matric;
    cont.print_el = print_el_int_Matric;

    cont.sum_el =  sum_el_int;
    cont.mult_el = mult_el_int;
    cont.equal_el = equal_el_int;

    cont.mas = ar;

    return cont;
}


void ** vvod_int_Matric(int size)
{
    int* a = (int *) calloc(1, size * size * sizeof(int));
    void** ar = (void **) calloc(1,size * size*sizeof(a));


    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            scanf("%d", &a[i*size+j]);
            ar[i*size+j] = &a[i*size+j];

        }
    }
    return ar;
}

void ** transform_ar_int(int inar [], int size)
{
    int* a = (int *) calloc(1, size * size * sizeof(int));
    void** ar = (void **) calloc(1,size * size*sizeof(a));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            ar[i*size+j] = &inar[i];
        }
    }
    return ar;
}