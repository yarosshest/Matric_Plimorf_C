#include <stdlib.h>
#include <vcruntime_string.h>
#include <stdio.h>
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

//            mat.print_el((*(mat.mas)+(i*size+j)*mat.element_size));
//            mat.print_el(mat.mas[i*size+j]);
        }
        printf("\n");
    }
}



void trans_Matric(struct Matric mat1,struct Matric mat2)
{
    int bit = mat1.element_size;
    int size =mat1.size;
    void* b;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <=i;j++)
        {
//            memcpy(&b,&mat1.mas[i*size+j],bit);
//            memcpy(&mat2.mas[i*size+j],&mat1.mas[j*size+i],bit);
//            memcpy(&mat2.mas[j*size+i],&b,bit);
        }
    }
}