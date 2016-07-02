qsort()

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
qsort(array, how_many_elements, sizeof(int), compare);
