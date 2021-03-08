#include <stdlib.h>
#include <stdio.h>
#include "Matric_compl.h"
#include "Matric .h"
#include "compl_num.h"
#include <assert.h>

struct Matric init_compl_Matric(int element_size, int size,void* ar)
{
    assert(size > 0);
    struct Matric_compl *arT = (struct Matric_compl* ) calloc(1, sizeof (struct Matric_compl));
    arT->mas = ar;

    struct Matric cont = init_Matric(arT);

    cont.mult = mult_compl_Matric;
    cont.sum = sum_compl_Matric;
    cont.trans = trans_compl_Matric;
    cont.element_size = element_size;
    cont.size = size;
    cont.print = print_compl_Matric;

    return cont;
}

struct Matric mult_compl_Matric(struct Matric mat1, struct Matric mat2)
{
    assert(mat1.size == mat2.size);
    assert(mat1.element_size == mat2.element_size);

    struct Matric_compl m1 = *( struct Matric_compl *)(mat1.arT);
    struct Matric_compl m2 = *( struct Matric_compl *)(mat2.arT);

    int size =mat1.size;

    struct compl *mr = (struct compl*)calloc(1,size * size * sizeof(struct compl));
    struct Matric ret = init_compl_Matric(sizeof(struct compl),size,mr);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <size;j++)
        {
            for(int z = 0; z < size; z++)
            {
                struct compl mult = mult_compl(m1.mas[i*size+z],m2.mas[z*size+j]);
                mr[i*size+j] = sum_compl(mr[i*size+j],mult);
            }
        }
    }
    return ret;
}

struct Matric sum_compl_Matric(struct Matric mat1, struct Matric mat2)
{
    assert(mat1.size == mat2.size);
    assert(mat1.element_size == mat2.element_size);
    struct Matric_compl m1 = *( struct Matric_compl *)(mat1.arT);
    struct Matric_compl m2 = *( struct Matric_compl *)(mat2.arT);

    int size =mat1.size;

    struct compl *mr = (struct compl*)calloc(1,size * size * sizeof(struct compl));
    struct Matric ret = init_compl_Matric(sizeof(struct compl),size,mr);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <size;j++)
        {
            struct compl sum = sum_compl(m1.mas[i*size+j],m2.mas[i*size+j]);
            mr[i*size+j] = sum_compl(mr[i*size+j],sum);
        }
    }
    return ret;
}

struct Matric trans_compl_Matric(struct Matric mat1)
{
    struct Matric_compl m1 = *( struct Matric_compl *)(mat1.arT);

    int size =mat1.size;

    struct compl *mr = (struct compl*)calloc(1,size * size * sizeof(struct compl));
    struct Matric ret = init_compl_Matric(sizeof(struct Matric_compl),size,mr);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <=i;j++)
        {
            struct compl b = m1.mas[i*size+j];
            mr[i*size+j] = m1.mas[j*size+i];
            mr[j*size+i] = b;
        }
    }
    return ret;
}


void print_compl_Matric(struct Matric mat)
{
    struct Matric_compl m = *( struct Matric_compl *)(mat.arT);

    int size =mat.size;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            printf(" %d+%di |",m.mas[i*size+j].x,m.mas[i*size+j].y);
        }
        printf("\n");
    }
}
struct compl * vvod_compl_Matric(int size)
{
    struct compl c;
    struct compl *a = (struct compl*)calloc(1,size*size * sizeof(struct compl));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            int x;
            int y;
            scanf("%d%d", &x, &y);
            c.x = x;
            c.y = y;
            a[i*size+j] = c;
        }
    }
    return a;
}
