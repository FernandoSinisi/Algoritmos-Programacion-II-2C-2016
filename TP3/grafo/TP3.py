import heapq
import sys
import grafo

def main():
	marvel = Grafo()
	if len(sys.argv) != 2:
		print("cantidad de parametros incorrecta")
		return ValueError
	try:
		cargar_grafo(marvel,sys.argv[1])
		
		
		
def cargar_grafo(grafo,ruta):		
	with open (sys.argv[1]) as archivo:
		linea = archivo.readline()
		ref = linea.split()
		cant_pers = int(ref[1])
		dicc_aux={}
		for i in range(cant_pers):
			linea = archivo.readline()
			cadena = linea.split()
			vertice,personaje = cadena[0]," ".join(cadena[1:])
			dicc_aux[vertice]=personaje
			grafo.vertices[personaje] = {}
		linea = archivo.readline()
		##print(linea)
		while(linea != ""):
			linea = archivo.readline()
			#print(linea)
			aristas = linea.split()
			pers1,pers2= dicc_aux[arista[0]],dicc_aux[arista[1]]
			grafo.vertices[pers1][pers2]=arista[2]
			grafo.vertices[pers2][pers1]=arista[2]
	except IOError:
		print("Se ha producido un error al buscar/leer el archivo ")
	#for i in range(1,6000):
	#	print(dicc_aux[str(i)])
		
	
	
main()	
