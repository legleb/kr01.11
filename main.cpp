#include <iostream>

void destroy(int ** mtx, size_t created)
{
  for (size_t i = 0; i < created; ++i)
  {
    delete[] mtx[i];
  }
  delete[] mtx;
}

int ** create(size_t rows, size_t cols)
{
  int ** mtx = new int * [rows];
  size_t created = 0;
  try {
    for (size_t i = 0; i < rows; ++i)
    {
      mtx[i] = new int[cols];
      created++;
    }
  }
  catch (const std::bad_alloc &e)
  {
    destroy(mtx, created);
    throw;
  }
  return mtx;
}

void construct(int ** mtx, int init, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      mtx[i][j] = init;
    }
  }
}

int main()
{
  int ** matrix = nullptr;
  try
  {
    matrix = create(5, 5);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << "created!\n";
  construct(matrix, 2, 5, 5);
  std::cout << matrix[0][0] << "\n";
  destroy(matrix, 5);
}
