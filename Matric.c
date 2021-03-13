#include <stdlib.h>
#include <vcruntime_string.h>
#include <stdio.h>
#include <assert.h>
#include "Matric .h"
#include "Matric_int.h"


void print_Matric(struct Matric mat)
{
    int size = mat.size;
    void* am = *(void**) mat.mas;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            mat.print_el(mat.mas[i*size+j]);
        }
        printf("\n");
    }
}


void trans_Matric(struct Matric* mat1)
{
    int bit = mat1->element_size;
    int size =mat1->size;

    void** copy = mat1->zero_matric(mat1->size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            memcpy(copy[j*size+i],mat1->mas[i*size+j],bit);
        }
    }
    mat1->mas = copy;
}

struct Matric sum_Matric(struct Matric mat1,struct Matric mat2)
{
    int size = mat1.size;

    assert(size > 0);
    assert(mat1.size == mat2.size);

    int bit = mat1.element_size;

    void** ar = mat1.zero_matric(mat1.size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            memcpy(ar[j*size+i],mat1->mas[i*size+j],bit);
        }
    }
    mat1->mas = copy;
}