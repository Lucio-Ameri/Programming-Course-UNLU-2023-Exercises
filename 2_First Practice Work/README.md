A continuacion se muestran las consignas de los respectivos ejecicios que se han resuelto en los siguientes archivos:

1. Crear una función con cuatro parámetros (array, N, menor, mayor) que cargue y devuelva un vector de N elementos cargados de forma aleatoria con números comprendidos entre menor y mayor.

2. Dados dos vectores A y B de igual cantidad de elementos cargados con la función del punto 1, obtener el producto escalar: Σ A(i) * B(i).
Ejemplo:
A = {5, 7, 3} ; B = {9, 2, 1}          ;          producto_escalar = (5 x 9) + (7 x 2) + (3 x 1)

3. Hacer una función que reciba dos vectores A y B de números enteros de n cantidad de elementos, siendo n un número par, y retorne la suma de los elementos que ocupan las posiciones pares del primero con los elementos que ocupan las impares del segundo. Recuerde que en C las posiciones en los arreglos se numeran desde el cero, y que el cero es un número par.
Ejemplo:
A = {13, 2, 1, 6};            B = {5, 7, 3, 9};          sumatoria = 13 + 7 + 1 + 9

4. Dado un arreglo de N elementos, escribir un programa que permita desplazar los elementos del arreglo una posición a la derecha, de tal forma que el primero pase a la segunda posición, el segundo a la tercera y así sucesivamente.
Ejemplo:
A = {5, 7, 4, 9, 3} ;         resultado = {3, 5, 7, 4, 9}

5. Crear una función que cargue un vector de 30 elementos con la letra “x" y coloque en una ubicación aleatoria una “A” y en otra ubicación aleatoria que no sea la misma que tiene la letra “A” una letra “B”
Ejemplo:
A = {“x”,...,”x”,”A”,”x”,....,”B”}

6. Realizar una función que devuelva distancia entre las posiciones de la letra “A” y la letra “B” del vector cargado en el ejercicio anterior.
Ejemplo:
A = {“x”,”x”,”A”,”x”,”B”}  distancia = 1;  A = {“x”,”x”,”B”,”A”}  distancia = 0

7. Ingresar 1000 edades en un vector e indicar cuál es la edad de mayor frecuencia (la que más se repite).

8. Realizar una función que determine si dos vectores cargados con números naturales, de igual cantidad de elementos, son idénticos.

9. Escribir una función que acepte como parámetro un vector que contiene números positivos, que puede contener valores duplicados, y reemplace cada elemento repetido por -1 (menos uno). El procedimiento debe retornar el vector modificado y la cantidad de veces que fue modificado.

10. Hacer una función que reciba un vector con n elementos numéricos y retorne la cantidad de números negativos que se encuentran en el vector.

11. Hacer una función que reciba un vector con n elementos numéricos y retorne la cantidad de números ceros que se encuentran en el vector.

12. Hacer una función que reciba un vector con n elementos numéricos y retorne la cantidad de números negativos que se encuentran en el vector.

13. Hacer una función que reciba un vector con n elementos numéricos y llamando a las funciones de los 3 ítems anteriores, muestre por pantalla la cantidad de números positivos, ceros y negativos que se encuentran en el
vector.

14. Realizar un programa que reciba un vector con n elementos numéricos y muestre por pantalla el mayor de los valores del vector. Haga una función auxiliar que pruebe la correctitud del programa.

15. Imprimir y sumar los elementos que ocupan las posiciones impares de un vector de 50 elementos numéricos.

16. Escribir una función que reciba como argumentos un arreglo de N elementos de tipo entero y un número entero X, y haga lo siguiente:
a. Busque todos los elementos que coincidan con X y devuelva la cantidad de coincidencias encontradas.
b. Busque la primera coincidencia del elemento en la lista y devuelva su posición. Si X no existe en el arreglo debe devolver -1.
c. Utilizando la función anterior, busque todos los elementos que coincidan con X y devuelva un arreglo con las posiciones que ocupan estos elementos en el arreglo original. Si no hay elementos coincidentes, devolverá un arreglo vacío.
Ejemplo:
Para N=7  El arreglo podría ser A ={5, 7, 3, 9, 2, 3, 8 }  

Con X=3, los resultados serían:
a) coincidencias(x) = 2
b) primera_posicion_coincidencia(x) = 2
c) posicionesCoincidentes(x) = {2, 5 }

Con X=4, los resultados serían:
a) coincidencias(x) = 0
b) primera_posicion_coincidencia(x) = -1
c) posicionesCoincidentes(x) = {}

