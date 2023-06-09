/* PR middle-end/99007 */

int
bar (int n)
{
  int s[n];
  int i, j;
  for (i = 0; i < n; i++)
    s[i] = 0;
  #pragma omp target map(tofrom:s)
  #pragma omp teams distribute parallel for reduction(+:s) private (j)
  for (i = 0; i < 8; i++)
    for (j = 0; j < n; j++)
      s[j] += i;
  return s[0] + s[n - 1];
}
