void redimensionar (int* &v, int& tama, int aumento){
	if(tama+aumento > 0){
		int *v_ampliado = new int[tama+aumento];
		for (int i=0; (i<tama) && (i<tama+aumento); i++)
			v_ampliado[i] = v[i];
		delete[] v;
		v = v_ampliado;
		tama=tama+aumento;
	}
}
