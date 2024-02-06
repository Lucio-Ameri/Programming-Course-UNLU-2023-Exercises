A continuacion se muestran las consignas de los respectivos ejecicios que se han resuelto en los siguientes archivos:

1. Escribir una función que reciba un arreglo de caracteres e indique si se encuentran ordenados de menor a mayor o no.
Ejemplo:
A = {‘c’, ‘a’, 'j’, ’t’, ‘p’, ‘g’}  Resultado = “NO”
A = {‘a’, ‘c’, ‘g’, ‘j’, ‘p’, ’z’} Resultado = “SI”

2. Haga una función que reciba dos arreglos ordenados A(n) y B(m), y retorne un nuevo arreglo C que contenga los elementos de A y de B de tal forma que quede también ordenado. Si existen elementos repetidos en los arreglos originales, en C deberán aparecer solamente una vez.
Ejemplo:
n=6 ; m=7  ;  A = { 2, 5, 8 , 10,11, 25} ; B = { 1, 2, 6, 7, 9, 1 1,13};  C={ 1, 2, 5, 6, 7, 8, 9, 10, 11, 13,25}

3. Realizar un programa que permita, a través de una función actualizar un arreglo ordenado de n elementos. Esta función recibe cuatro parámetros : el arreglo a actualizar, la cantidad de elementos, la acción a realizar que puede ser I, B o A y un valor entero. Si la acción es I deberá agregar el valor en la última posición. Si es B deberá encontrar el valor dentro del arreglo y borrarlo (si no lo encuentra devolver mensaje de error) y si es A deberá ingresar un nuevo valor en la posición que indique valor.
Ejemplo:
n=6; Si arreglo es ={5, 7, 9, 11, 19, 24 }, acción es “B” y valor es 19.
actualizar(arreglo,cant, accion,valor ) devolverá { 5, 7, 9, 11, 24 }

4. Se tienen dos arreglos de números enteros, ordenados de mayor a menor, de n elementos cada uno: A(n) y B(n). Se pide realizar un algoritmo que permita obtener un nuevo arreglo C, que contenga únicamente los elementos iguales que existan en los dos y no pueden estar repetidos.

5. Escribir un algoritmo que permita procesar 2 arreglos ordenados de n elementos. Legajos(n) y Notas (n * 3) ya que por cada legajo hay 3 notas consecutivas . Se desea obtener un listado con el promedio de cada alumno.
