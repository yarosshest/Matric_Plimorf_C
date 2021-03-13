struct Matric
{
    int element_size;
    int size;
    void* arT;
    void** mas;

    struct Matric  (*mult)(struct Matric ,struct Matric );
    struct Matric  (*sum)(struct Matric ,struct Matric );
    struct Matric  (*trans)(struct Matric);
    void (*print)(struct Matric);
    void (*print_el)(void *el);
};
void trans_Matric(struct Matric mat1,struct Matric mat2);
void print_Matric(struct Matric mat);