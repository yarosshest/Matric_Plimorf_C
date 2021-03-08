
struct Matric_compl
{
    struct compl* mas;
};
struct Matric init_compl_Matric(int element_size, int size, void* ar);
struct Matric mult_compl_Matric(struct Matric,struct Matric);
struct Matric sum_compl_Matric(struct Matric,struct Matric);
struct Matric trans_compl_Matric(struct Matric);
void print_compl_Matric(struct Matric);
struct compl * vvod_compl_Matric(int size);