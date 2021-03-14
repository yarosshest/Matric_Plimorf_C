struct Matric_int
{
    int* mas;
};
struct Matric init_int_Matric(int element_size, int size, void** ar);
void print_int_Matric(struct Matric);
void ** vvod_int_Matric(int size);
void* mult_el_int(void* el1, void* el2);
void* sum_el_int(void* el1, void* el2);