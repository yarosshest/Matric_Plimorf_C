struct DynAr
{
    int element_size;
    int size;
    void* arT;

    void*  (*def)(void *,void *);
};

struct DynAr init_DynAr(int element_size, void *arT);
void def_DynAr(struct DynAr cont, void *ar);