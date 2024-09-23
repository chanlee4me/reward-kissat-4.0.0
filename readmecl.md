addde in vector.h

//在队尾插入值为 0 的元素
void append_zero_to_vector(kissat *solver, vector *v);
//利用索引访问动态数组中的元素
unsigned get_vector_element(kissat *solver, vector *v, size_t index);
//利用索引设置动态数组中的元素值
void set_vector_element(kissat *solver, vector *v, size_t index, unsigned new_value)；

added in internal.h
//初始化 htab 动态数组
void initialize_htab_with_zeros(kissat *solver, vector *htab, size_t N);