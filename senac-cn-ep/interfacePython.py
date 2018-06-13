import numpy
import ranqueador
import os

arquivo = open("matriz_entrada.txt","r")
linhas = arquivo.readlines()
lista = []
rank = {}

for line in linhas:
    lista.append ((line.split()))

dimensao = len(lista[0])

matriz = numpy.asarray(lista)



saida = ranqueador.ranquear(matriz,dimensao)

counter = 1
lista = []
for pagina in saida:
    lista.append([counter,pagina[0]])
    counter += 1

lista.sort(key=lambda x: x[1],reverse = True)


print("Rank das páginas:(Ordenado)")
for pagina in lista:
    print("Página "+str(pagina[0]) + ":  " + str(pagina[1]) )
