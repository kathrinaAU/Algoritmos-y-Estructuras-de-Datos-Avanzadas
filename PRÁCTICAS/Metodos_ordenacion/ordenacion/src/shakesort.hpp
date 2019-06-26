template <class Clave, class Comparar>
void Shakesort<Clave, Comparar>::sort(vector<Clave> &v, int tam, int ini,
									  int cen, int fin, float alpha, bool show)
{
	Clave temp;
	ini = 1;
	fin = tam - 1;
	int cam = tam;

	while (ini < fin)
	{

		for (int j = fin; j >= ini; j--)
		{
			if (this->cmp(v[j], v[j - 1]))
			{
				if (show == true)
				{
					cout << endl
						 << "Comparando: " << v[j] << " y " << v[j - 1] << endl;
				}

				temp = v[j - 1];
				v[j - 1] = v[j];
				v[j] = temp;
				++Sorter<Clave,Comparar>::Intercambio;

				cam = j;
				if (show == true)
				{
					cout << "Intercambio entre: " << v[j] << " y " << v[j - 1] << endl;
				}
			}
		}
		ini = cam + 1;
		for (int j = ini; j <= fin; j++)
		{
			if (this->cmp(v[j], v[j - 1]))
			{
				if (show == true)
				{
					cout << endl
						 << "Comparando: " << v[j] << " y " << v[j - 1] << endl;
				}
				temp = v[j - 1];
				v[j - 1] = v[j];
				v[j] = temp;
				++Sorter<Clave,Comparar>::Intercambio;
				
				cam = j;
				if (show == true)
				{
					cout << "Intercambio entre: " << v[j] << " y " << v[j - 1] << endl;
				}
			}
		}
		fin = cam - 1;
	}
}