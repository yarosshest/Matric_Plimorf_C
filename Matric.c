#include <stdlib.h>
#include <vcruntime_string.h>
#include <stdio.h>
#include <assert.h>
#include "Matric.h"
#include "Matric_int.h"
#include <stdbool.h>
void print_Matric(struct Matric mat)
{
    int size = mat.size;
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
    void* sum;

    struct Matric res = mat1;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            sum = mat1.sum_el(mat1.mas[i*size+j],mat2.mas[i*size+j]);
            memcpy(ar[i*size+j],sum,bit);
        }
    }
    res.mas = ar;
    return res;
}

struct Matric mult_Matric(struct Matric mat1,struct Matric mat2)
{
    int size = mat1.size;

    assert(size > 0);
    assert(mat1.size == mat2.size);

    int bit = mat1.element_size;

    void** ar = mat1.zero_matric(mat1.size);
    void* sum;
    void* mult;

    struct Matric res = mat1;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            for(int z = 0; z < size; z++)
            {
                mult = mat1.mult_el(mat1.mas[i*size+z],mat2.mas[z*size+j]);
                struct compl* test1 = (struct compl*) mult;
                sum = mat1.sum_el(ar[i*size+j],mult);
                struct compl* test2 = (struct compl*) sum;
                memcpy(ar[i*size+j],sum,bit);
            }
        }
    }
    res.mas = ar;
    return res;
}
bool equal_Matric(struct Matric mat1, struct Matric mat2)
{
    int size = mat1.size;

    assert(size > 0);
    assert(mat1.size == mat2.size);

    bool flag = true;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            if(!mat1.equal_el(mat1.mas[i*size+j],mat2.mas[i*size+j]))
            {
                flag = false;
            }
        }
    }
    return flag;
}