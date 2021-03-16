#include <stdbool.h>
struct Matric
{
    int element_size;
    int size;
    void** mas;

    void** (*zero_matric)(int size);

    void (*print_el)(void *el);
    void* (*sum_el)(void *el1,void *el2);
    void* (*mult_el)(void *el1,void *el2);
    bool (*equal_el)(void *el1,void *el2);

};

void trans_Matric(struct Matric* mat);
void print_Matric(struct Matric mat);
struct Matric sum_Matric(struct Matric mat1,struct Matric mat2);
struct Matric mult_Matric(struct Matric mat1,struct Matric mat2);
bool equal_Matric(struct Matric ar1, struct Matric ar2);
void ** transform_ar_int(int inar [], int size);