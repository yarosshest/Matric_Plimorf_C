struct DynAr_str
{
    char** mas;
};

struct DynAr init_str_DynAr(int element_size);
void def_str_DynAr(void * ar,void *def);