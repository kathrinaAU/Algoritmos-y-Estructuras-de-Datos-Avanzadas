
template<class Clave, class Comparar>
void Bubblesort<Clave,Comparar>::sort(vector<Clave> &v, int tam, int ini,
 int cen, int fin, float alpha, bool show){
    Clave temp;
        //Ejemplo:
        //7 3 1 2 4 6
        //7 1 3 2 4 6; 1 7 3 2 4 6
        //1 7 2 3 4 6; 1 2 7 3 4 6z

        for (int i = 1; i < v.size(); i++)
        { // i=1
            for (int j = v.size() - 1; j >= i; j--)
            { // j=5
                if (this->cmp(v[j], v[j - 1]))
                { // 6 es menor que 4?
                    if (show)
                    {
                        cout << endl
                            << "Comparando: " << v[j] << " y " << v[j - 1] << endl;
                        cout << "Intercambio entre: " << v[j - 1] << " y " << v[j] << endl;
                    }
                    temp = v[j - 1];
                    v[j - 1] = v[j];
                    v[j] = temp;
                    ++Sorter<Clave,Comparar>::Intercambio;
                }
            }
        }
}