template <class Clave, class Comparar>
void Seleccion<Clave, Comparar>::sort(vector<Clave> &v, int tam, int ini,
									  int cen, int fin, float alpha, bool show)
{
	//eficiencia n^2
	Clave x;
	// int j;
	//Comparamos con los elementos anteriores por lo que empezamos en i=1
	// for (int i = 1; i < v.size()-1; i++)
	// {
	// 	j = i;
	// 	x = v[i];
	// 	int ini = 0;
	// 	int fin = i - 1;
	// 	while (ini <= fin)
	// 	{
	// 		int med = (ini + fin) / 2;

	// 		if (this->cmp(v[med], x))
	// 		{
	// 			ini = med + 1;
	// 		}
	// 		else
	// 		{
	// 			fin = med - 1;
	// 		}
	// 	}
	// 	for (int j = i - 1; j >= ini; j--)
	// 	{
	// 		v[j + 1] = v[j];
	// 	}
	// 	v[ini] = x;

	for (int i = 0; i < v.size() - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (this->cmp(v[j], v[min]))
			{
				if (show == true)
				{
					cout << endl << "Comparando: " << v[j] << " y " << v[min];
				}
				min = j;
			}
		}
		x = v[min];
		v[min] = v[i];
		v[i] = x;
		++Sorter<Clave,Comparar>::Intercambio;
		
		if (show == true)
		{
			cout << endl << "Intercambio entre: " << v[i] << " y " << v[min] << endl;
		}
	}
}