struct Matric
{
    int element_size;
    int size;
    void* arT;
    void** mas;

    struct Matric  (*mult)(struct Matric ,struct Matric );
    struct Matric  (*sum)(struct Matric ,struct Matric );
    void** (*zero_matric)(int size);
    void (*print)(struct Matric);

    void (*print_el)(void *el);
    void** (*sum_el)(void *el1,void *el2);
};
void trans_Matric(struct Matric* mat);
void print_Matric(struct Matric mat);
struct Matric sum_Matric(struct Matric mat1,struct Matric mat2);