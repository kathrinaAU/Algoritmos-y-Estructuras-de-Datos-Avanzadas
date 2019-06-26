
template <class Clave, class Comparar>
void Radixsort<Clave, Comparar>::sort(vector<Clave> &v, int tam, int ini,
                                      int cen, int fin, float alpha, bool show)
{
  // Obtenemos elemento máximo en el vector.
  int maximo = getMaxElement(v);

  // Ordenamos el vector por digito.
  for (int exp = 1; maximo / exp > 0; exp *= 10)
  {
    sortByExpIndex(v, exp);
  }
}

template <class Clave, class Comparar>
int Radixsort<Clave, Comparar>::getMaxElement(vector<Clave> &v)
{
  int max = v[0];

  for (int i = 1; i < v.size(); i++)
    if (this->cmp(max, v[i]))
      max = v[i];

  return max;
}
// {170,45,75,90,802,24,2,66}
template <class Clave, class Comparar>
void Radixsort<Clave, Comparar>::sortByExpIndex(vector<Clave> &v, int exp)
{
  Clave aux[v.size()];
  int count[10] = {0};

  // Contamos número de dígitos en el vector.
  for (int i = 0; i < v.size(); i++)
  {
    count[(v[i] / exp) % 10]++;
  }
  // 2 0 2 0 1 2 1 0 0 0

  for (int i = 1; i < 10; i++)
  {
    count[i] += count[i - 1];
  }
  // 2 2 4 4 5 7 8 8 8 8

  for (int i = v.size() - 1; i >= 0; i--)
  {
    aux[count[(v[i] / exp) % 10] - 1] = v[i];
    count[(v[i] / exp) % 10]--;
  }
  // 170 90 802 2 24 45 75 66

  for (int i = 0; i < v.size(); i++)
  {
    v[i] = aux[i];
  }
}
