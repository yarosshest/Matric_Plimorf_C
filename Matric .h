struct Matric
{
    int element_size;
    int size;
    void* arT;

    long* mas;

    struct Matric  (*mult)(struct Matric ,struct Matric );
    struct Matric  (*sum)(struct Matric ,struct Matric );
    struct Matric  (*trans)(struct Matric);
    void (*print)(struct Matric);
    void (*print_el)(long* el);
    long * (*sum_el)(long*  el1, long* el2);
    long * (*mult_el)(long* el1, long* el2);
};

struct Matric init_Matric(void *arT);
void mult_Matric(struct Matric mat1, struct Matric mat2, struct Matric mat3);
void sum_Matric(struct Matric mat1, struct Matric mat2, struct Matric mat3);
void print_Matric(struct Matric);
long* vvod_compl_Matric(int size);