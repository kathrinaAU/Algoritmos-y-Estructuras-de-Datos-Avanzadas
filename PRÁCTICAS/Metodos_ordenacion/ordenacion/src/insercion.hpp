
template<class Clave, class Comparar>
void Insercion<Clave,Comparar>::sort(vector<Clave> &v, int tam, int ini,
 int cen, int fin, float alpha, bool show){
    //eficiencia n^2
	Clave aux;
	int j;
	//Comparamos con los elementos anteriores por lo que empezamos en i=1
	for (int i = 1; i < v.size(); i++)
	{
		aux = v[i]; // 3
		j = i - 1;  // 7
		//Ejemplo:
		//7 3 1 2 4 6
		while (j >= 0 and this->cmp(aux, v[j]))
		{ //3 menor que 7?
			if (show)
			{
				cout << endl
					 << "Comparando: " << aux << " y " << v[j] << endl;
				cout << "Intercambio entre: " << v[j + 1] << " y " << v[j] << endl;
			}

			v[j + 1] = v[j]; //Intercambio 7 por 3
			++Sorter<Clave,Comparar>::Intercambio;
			j--;
			//3 7 1 2 4 6
		}

		v[j + 1] = aux;
	}
}