from random import uniform
import matplotlib.pyplot as plt

veces = input("Veces para tirar la moneda: ")
ratio = input("Trucado de la cara de la moneda(decimal entre 0 y 1): ")
ratio = float(ratio)
num_tiradas = 0;
num_caras = 0;

array_tiradas = []
array_frecuencias = []

for _ in range (int(veces)):
	tirada = uniform(0,1)
	#1 es cara 0 es cruz
	resultado = 1 if tirada <=ratio else 0
	num_caras += resultado
	num_tiradas += 1
	array_tiradas.append(num_tiradas)
	array_frecuencias.append(num_caras/num_tiradas*1.0)
	

plt.plot(array_tiradas, array_frecuencias)
plt.xlabel("Numero de tiradas")
plt.ylabel("Frecuencia relativa")
plt.show()
