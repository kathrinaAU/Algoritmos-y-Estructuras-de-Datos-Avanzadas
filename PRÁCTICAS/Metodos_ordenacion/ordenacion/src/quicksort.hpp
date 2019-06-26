
template <class Clave, class Comparar>
void Quicksort<Clave, Comparar>::sort(vector<Clave> &v, int tam, int ini, int cen, int fin, float alpha, bool show)
{
	//eficiencia n*log(n)

	if (ini < fin)
	{
		int p = partition(v, ini, fin, show);
		sort(v, tam, ini, 0, p - 1, 0, show);
		sort(v, tam, p, 0, fin, 0, show);
	}
}

template <class Clave, class Comparar>
int Quicksort<Clave, Comparar>::partition(vector<Clave> &v, int ini, int fin, bool show)
{

	Clave pivote = v[fin];
	int i = ini - 1;
	Clave aux;

	for (auto j = ini; j <= fin - 1; j++)
	{
		if (this->cmp(v[j], pivote))
		{
			if (show)
			{
				cout << endl
					 << "Comparando: " << v[j] << " y " << pivote << endl;
				cout << "Intercambio entre: " << v[j] << " y " << v[i + 1] << endl;
			}
			i++;
			aux = v[j];
			v[j] = v[i];
			v[i] = aux;
			++Sorter<Clave, Comparar>::Intercambio;
		}
	}

	aux = pivote;
	v[fin] = v[i + 1];
	v[i + 1] = aux;
	++Sorter<Clave, Comparar>::Intercambio;

	return i + 1;
}