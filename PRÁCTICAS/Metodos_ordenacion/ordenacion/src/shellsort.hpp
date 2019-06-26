
template<class Clave, class Comparar>
void Shellsort<Clave,Comparar>::sort(vector<Clave> &v, int tam, int ini,
 int cen, int fin, float alpha, bool show){
   int gap = tam * alpha;
	Clave temp;
	bool uno = false;

	for (gap; gap >= 0 and !uno; gap *= alpha)
	{

		// Para cuando tenemos un alpha < 0.5
		if (gap < 1)
		{
			gap = 1;
			uno = true;
		}

		for (auto i = 0; i < tam; i++)
		{
			if ((i + gap) < tam and  this->cmp(v[i + gap], v[i]))
			{
				if (show)
				{
					cout << endl
						 << "Comparando: " << v[i + gap] << " y " << v[i] << endl;
					cout << "Intercambio entre: " << v[i] << " y " << v[i + gap] << endl;
				}

				temp = v[i];
				v[i] = v[i + gap];
				v[i + gap] = temp;
				++Sorter<Clave, Comparar>::Intercambio;

				for (auto j = i; j >= 0; j -= gap)
				{
					if ((j - gap) >= 0 and this->cmp(v[j], v[j - gap]))
					{
						if (show)
						{
							cout << endl
								 << "Comparando: " << v[j] << " y " << v[j - gap] << endl;
							cout << "Intercambio entre: " << v[j - gap] << " y " << v[j] << endl;
						}

						temp = v[j - gap];
						v[j - gap] = v[j];
						v[j] = temp;
						++Sorter<Clave, Comparar>::Intercambio;
					}
				}
			}
		}
	}
}