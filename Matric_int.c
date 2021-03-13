#include <stdio.h>
#include "Matric_int.h"
#include "Matric .h"
#include "stdlib.h"
#include <assert.h>
void print_el_int_Matric(void* el)
{
    int a = *(int*) el;
    printf(" %d |",a);
}

struct Matric init_int_Matric(int element_size, int size,void** ar)
{
    assert(size > 0);

    void* test = ar[0];
    int* test2 = (int*) test;

    struct Matric cont;

    cont.element_size = element_size;
    cont.size = size;

    cont.print_el = print_el_int_Matric;

    cont.mas = ar;

    return cont;
}


void ** vvod_int_Matric(int size)
{
    int *a = (int *) calloc(1, size * size * sizeof(int));
    void **mr = (void **) calloc(1, sizeof(a));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            scanf("%d", &a[i*size+j]);
        }
    }
    mr = &a;
    void* test = mr[0];
    int* test2 = (int*) test;
    return mr;
}

