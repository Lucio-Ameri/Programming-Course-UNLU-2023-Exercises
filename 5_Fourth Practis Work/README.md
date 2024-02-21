A continuacion se muestran las consignas de los respectivos ejecicios que se han resuelto en los siguientes archivos:

1. Escribir un procedimiento que almacene en un arreglo de registros los datos de 10 alumnos, conteniendo su legajo (generado automáticamente de 100 en 100, comenzando con legajo = 1, para que quede ordenado), nombre, apellido y las calificaciones de los 3 exámenes parciales de una asignatura. Calcular el promedio de cada uno y mostrar el listado de alumnos junto con un mensaje de Promovido si el alumno supera o iguala el promedio de 7, Regular si resulta entre 4 y 7 y Libre en caso que la nota media no alcance el 4.
Ejemplo:

El arreglo podría ser:
{[1,“Juan”, “Pérez”, 5,7,8], [101,“Luis”, “García”, 2,8,8], [201,“Maria”, “Alonso”, 6,6,10],..., [901,“Alicia”, “Rojas”, 2,2,4]}

Resultado:
Legajo Nombre Apellido Promedio Condición
  1     Juan   Pérez     6,66     Regular
  101   Luis   García    6,00     Regular
  201   Maria  Alonso    7,33     Promovido
..........................................
  901   Alicia Rojas     2,66      Libre

2. Hacer un programa que almacene en un arreglo de registros la siguiente información de N trabajadores: nombre, edad, sexo (F o M), estado civil(S(soltero), C(casado), D(divorciado) y O(otro)) y salario base. Calcular y mostrar por pantalla la cantidad de trabajadores del sexo masculino, la cantidad de trabajadoras casadas, el nombre del/a empleado/a más joven y la suma de todos los salarios.
Ejemplo:
N= 4
Empleados={[“Pérez Pablo”, 25,”M”,”C”,28000,00],
[“García Ismael”, 45,”M”,”D”,32500,00],
[“Sanchez Claudia”,38,”F”,”C”,30000,00],
[“Rodriguez Marisa”, 23,”F”,”S”,28000,00]}

Resultado:
Cantidad de trabajadores de sexo masculino= 2
Cantidad de trabajadoras casadas= 1
Empleado más joven= Rodriguez Marisa
Suma total de salarios: $118500,00

3. En un colegio de primaria, una clase tiene un nivel, un profesor y contiene 20 estudiantes. Cada estudiante tiene un nombre, apellido, una fecha de nacimiento y tendrá diez notas en el año. Hay cinco clases. Proporcione las estructuras de los registros clase y estudiantes. Escriba un algoritmo que muestre para cada clase, la lista de los estudiantes y sus diez notas asociadas.