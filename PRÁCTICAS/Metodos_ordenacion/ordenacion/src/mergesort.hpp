
template <class Clave, class Comparar>
void Mergesort<Clave, Comparar>::sort(vector<Clave> &v, int tam, int ini, int cen, int fin, float alpha, bool show)
{
	//eficiencia n*log(n)
	if (ini < fin)
	{
		int cen = (ini + fin) / 2;
		sort(v, tam, ini, 0, cen, 0, show);
		sort(v, tam, cen + 1, 0, fin, 0, show);
		mezcla(v, tam, ini, cen, fin, show);
	}
}

template <class Clave, class Comparar>
void Mergesort<Clave, Comparar>::mezcla(vector<Clave> &v, int tam, int ini, int cen, int fin, bool show)
{

	int i = ini;
	// int cen = v.size()/2;
	int j = cen + 1;
	int k = 0;
	vector<Clave> aux;
	while ((i <= cen) && (j <= fin))
	{
		if (this->cmp(v[i], v[j]))
		{
			if (show == true)
			{
				cout << endl << "Comparando: " << v[i] << " y " << v[j];
				cout << endl
					 << "Introduciendo en vector auxiliar: " << v[i] << endl;
			}
			++Sorter<Clave,Comparar>::Intercambio;
			aux.push_back(v[i]);
			i++;
		}
		else
		{
			if (show == true)
			{
				
				cout << endl
					 << "Introduciendo en vector auxiliar: " << v[j] << endl;
			}
			++Sorter<Clave,Comparar>::Intercambio;
			aux.push_back(v[j]);
			j++;
		}
	}

	// for(int h=0; h < aux.size(); h++){
	// 	cout << aux[h] << ' ';
	// }
	// cout << endl;

	if (i > cen)
	{
		while (j <= fin)
		{
			if (show == true)
			{
				cout << endl
					 << "Introduciendo en vector auxiliar: " << v[j] << endl;
			}
			++Sorter<Clave,Comparar>::Intercambio;
			aux.push_back(v[j]);
			j++;
		}
	}
	else
	{
		while (i <= cen)
		{
			if (show == true)
			{
				cout << endl
					 << "Introduciendo en vector auxiliar: " << v[i] << endl;
			}
			++Sorter<Clave,Comparar>::Intercambio;
			aux.push_back(v[i]);
			i++;
		}
	}

	i = 0;
	for (int k = ini; k <= fin; k++)
	{
		v[k] = aux[i];
		i++;
	}
}