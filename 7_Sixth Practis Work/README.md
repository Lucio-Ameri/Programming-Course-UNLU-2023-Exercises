1. En un archivo secuencial (de texto, por ejemplo “lluvias.txt”) se almacenan datos sobre la lluvia caída en un cierto período. Cada línea corresponde a un día y contiene los siguientes datos: Día-Mes-Anio-Precipitaciones (0 si no llovió). Preparar un algoritmo con los procedimientos necesarios para:
A _ cargar los datos correspondientes a los 30 días del mes de septiembre del corriente año. 
B _ leer el archivo e informar por pantalla:cuántos días hubo sin lluvias, cuántos días llovió menos de 50 mm y cuántos llovió 50 mm ó más.

EJEMPLO:
lluvias.txt: 
01 - 09 - 2021 - 25 
02 - 09 - 2021 - 95 
03 - 09 - 2021 - 0 
.. . . . .. . . . .. 
29 - 09 - 2021 - 15 
30 - 09 - 2021 - 0 

Salida: 
Días sin lluvia: 2 
Días con lluvia menor a 50mm: 2 
Días con lluvia mayor o igual a 50mm: 1

2. En una estación meteorológica se registra diariamente la temperatura máxima y mínima de todo un año con el siguiente diseño: Día-Mes-Anio-Temperatura_Maxima-Temperatura_Minima (éstos dos últimos se pueden generar aleatoriamente). Preparar un algoritmo con los procedimientos necesarios para: 
A _ cargar los datos correspondientes a todos los días del corriente año en un archivo llamado “temperaturas.txt”. 
b _ imprima por pantalla un reporte como el siguiente: 
                TEMPERATURA:INFORME ANUAL 

Temperatura Mínima Del Año: xx 
Registrada el Día: xx 
Del Mes: xx

Temperatura Máxima Del Año: xx 
Registrada el Día: xx 
Del Mes: xx

        Máxima Amplitud
Térmica: xx 
Registrada el Día: xx 
Del Mes: xx


EJEMPLO:
temperaturas.txt: 
01 -01 - 2021 - 18 - 31 
02 -01 - 2021 - 16 - 28 
03 - 06 - 2021 - 1 - 9 
30 - 12 - 2021 - 20 - 34
31 - 12 - 2021 - 20 - 36

TEMPERATURA: INFORME ANUAL 

Temperatura Mínima Del Año: 1 
Registrada el Día: 3 
Del Mes: 6

Temperatura Máxima Del Año: 36 
Registrada el Día: 31 
Del Mes: 12

Máxima Amplitud Térmica: 16 
Registrada el Día: 31 
Del Mes: 12

3. Utilizando el mismo archivo generado en el punto anterior, preparar un procedimiento que permita leer los datos y generar otro archivo(“temp_media.txt”), que contenga las temperaturas medias diarias con el siguiente formato: Día-Mes-Anio-Temperatura_Media

EJEMPLO: 
Salida: 
01 -01 - 2021 - 24.5 
02 -01 - 2021 - 22
03 - 06 - 2021 - 5 
30 - 12 - 2021 - 20.
31 - 12 - 2021 - 20.28


4. Se efectúa una encuesta para conocer el nivel de ocupación de los pobladores de una ciudad. Los encuestados contestaron los siguientes ítems: 
a. - Sexo (1 varón; 2 mujer). 
b. - Edad. 
c. - Estado civil (1 soltero; 2 casado; 3 otros).
d. - Trabaja (0 no; 1 sí).
e. - Estudia (0 no; 1 sí).

A _ Generar un archivo secuencial con todos los datos validados.
B _ Utilizando el archivo imprimir un reporte como el siguiente:

PORCENTAJES: 

• varones xx • 
• mujeres xx • 
• menores de 18 años que trabajan xx • 
• solteros xx • 
• casados xx • 
• encuestados que trabajan y estudian xx • 
• mujeres que trabajan xx •