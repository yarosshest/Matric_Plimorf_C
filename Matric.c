#include "Matric .h"
#include "Matric_int.h"
#include <assert.h>
#include <stdio.h>
#include "stdlib.h"
#include <assert.h>
#include "string.h"
#include "compl_num.h"

struct Matric init_Matric(void *arT)
{
    struct Matric ar;
    ar.arT = arT;
    return ar;
}

void mult_Matric(struct Matric mat1, struct Matric mat2, struct Matric mat3)
{
    assert(mat1.size == mat2.size);
    assert(mat1.element_size == mat2.element_size);

    int size = mat1.size;
    int bite = mat1.element_size;

    char* mr = (char*)calloc(1,size * size * bite);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <size;j++)
        {
            for(int z = 0; z < size; z++)
            {
                long * mult = mat1.mult_el(&mat1.mas[(i*size+z)*bite],&mat1.mas[(z*size+j)*bite]);
                long * sum = mat1.sum_el(&mr[(i*size+j)*bite],mult);
                mr[(i*size+j)*bite] = sum;
            }
        }
    }
    mat3.mas = mr;
}

void sum_Matric(struct Matric mat1, struct Matric mat2, struct Matric mat3)
{
    assert(mat1.size == mat2.size);
    assert(mat1.element_size == mat2.element_size);

    int size = mat1.size;
    int bite = mat1.element_size;


    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <size;j++)
        {
            int el1 =mat1.mas[(i*size+j)];
            int el2 =mat2.mas[(i*size+j)];
//            long* sum = mat1.sum_el(mat1.mas[(i*size+j)],&mat2.mas[(i*size+j)]);
//            memcpy(&mat3.mas[(i*size+j)*bite],sum,bite);
            mat3.mas[(i*size+j)] = mat1.sum_el(&mat1.mas[(i*size+j)],&mat2.mas[(i*size+j)]);
        }
    }
}

void print_Matric(struct Matric mat)
{

    int size = mat.size;

    struct compl c ;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <size;j++)
        {
            mat.print_el((long *) mat.mas[(i * size + j)*mat.element_size]);
        }
        printf("\n");
    }
}