template <class Clave, class Comparar>
void Heapsort<Clave, Comparar>::sort(vector<Clave> &v, int tam, int ini,
                                     int cen, int fin, float alpha, bool show)
{
    //eficiencia n*log(n)
    for (auto i = (tam / 2) - 1; i >= 0; i--)
    {
        heapify(v, tam, i, show);
    }

    Clave aux;
    for (auto i = tam - 1; i >= 0; i--)
    {
        if (show)
        {
            cout << "Intercambio entre: " << v[i] << " y " << v[0] << endl;
        }
        aux = v[i];
        v[i] = v[0];
        v[0] = aux;
        ++Sorter<Clave,Comparar>::Intercambio;
        

        heapify(v, i, 0, show);
    }
}
template <class Clave, class Comparar>
void Heapsort<Clave, Comparar>::heapify(vector<Clave> &v, int tam, int i, bool show)
{

    //eficiencia log(n)
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;
    Clave aux;

    if (l < tam and this->cmp(v[max], v[l]))
    {
        if (show)
        {
            cout << endl
                 << "El hijo es mayor que el padre: Hijo: " << v[l] << " Maximo: " << v[max] << endl;
        }
        max = l;
    }

    if (r < tam and this->cmp(v[max], v[r]))
    {
        if (show)
        {
            cout << endl
                 << "El hijo es mayor que el padre: Hijo: " << v[r] << " Maximo: " << v[max] << endl;
        }
        max = r;
    }

    if (max != i)
    {
        if (show)
        {
            cout << "Intercambio entre: " << v[i] << " y " << v[max] << endl;
        }

        aux = v[i];
        v[i] = v[max];
        v[max] = aux;
        ++Sorter<Clave,Comparar>::Intercambio;

        heapify(v, tam, max);
    }
}