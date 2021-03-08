struct Matric
{
    int element_size;
    int size;
    void* arT;

    struct Matric  (*mult)(struct Matric ,struct Matric );
    struct Matric  (*sum)(struct Matric ,struct Matric );
    struct Matric  (*trans)(struct Matric);
    void (*print)(struct Matric);
};

struct Matric init_Matric(void *arT);