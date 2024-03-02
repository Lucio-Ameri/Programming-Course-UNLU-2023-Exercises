1. Producir un reporte con los sueldos de los empleados de una compañía, emitiendo totales por sucursal. Cada empleado tiene un único registro en el archivo maestro de nómina con los siguientes datos:

• Código de sucursal (cod_suc: entero)
• Código de empleado (cod_emp: entero)
• Sueldo mensual(sueldo:real)

El archivo está ordenado en forma ascendente por código de sucursal (Archivo sueldos.txt): 


    EJEMPLO:

sueldos.txt:
01 - 15 - 50000,00
01 - 25 - 35000,00
. . . . . . . . . .
05 - 33 - 50000,00
05 - 42 - 45000,00

    Salida:

REPORTE DE SUELDO

SUCURSAL 1
Código Empleado     Sueldo
15                  $ 50.000,00
25                  $ 35.000,00
Total Sucursal      $ 85.000,00
. . . . . . . . . . . . . .
SUCURSAL 5
Código Empleado     Sueldo
33                  $ 50.000,00
42                  $ 45.000,00
Total Sucursal      $ 95.000,00


2. En una entidad bancaria se dispone de un archivo de transacciones, ordenado por Número de cuenta, con los clientes que han tenido movimiento en sus cuentas (puede haber más de un movimiento por cuenta). El registro está compuesto por:

• Nro. de cuenta (n_cuenta:entero)
• Movimiento(codi:entero)
• Importe (importe:real)

Donde codi puede tomar los siguientes valores: 1 si es un depósito, 2 si es una extracción. Cada registro representa un movimiento y contiene el importe de la misma. 

A - Realizar un programa que imprima un listado con todos los clientes que hayan tenido movimientos en sus cuentas y el saldo neto de dichos movimientos. (Archivo movimientos.txt)

    EJEMPLO

movimientos.txt:
100 - 01 - 10000,00
100 - 01 - 25000,00
100 - 02 - 15000,00
. . . . . . . . . .
585 - 02 - 15000,00
585 - 01 - 10000,00

INFORME MOVIMIENTOS DE CUENTA CORRIENTE:

Número de Cuenta       Saldo
100                    $ 20.000,00
. . . . . . . . . . . . . . . . . .
585                    $ -5.000,00


3. Producir un informe con los sueldos de los empleados de una compañía, emitiendo subtotales por departamento y por sucursal. Cada empleado tiene un único registro en el archivo maestro de nómina con los siguientes datos:

• Código de sucursal (cod_suc:entero)
• Código de departamento (cod_dpto:entero)
• Código de empleado (cod_emp:entero)
• Sueldo mensual (sueldo:real)

El archivo está ordenado en forma ascendente por código de sucursal y, dentro de sucursal por departamento (Archivo sueldos2.txt)

    EJEMPLO

sueldos2.txt:
01 - 10 - 15 - 50000,00
01 - 10 - 25 - 35000,00
01 - 15 - 44 - 25000,00
. . . . . . . . . . . . 
05 - 10 - 65 - 50000,00
05 - 15 - 88 - 45000,00
05 - 15 - 24 - 28000,00

Salida:
REPORTE DE SUELDO

SUCURSAL 1
Código Departamento     Código     Empleado Sueldo
10                        15         $ 50.000,00
10                        25         $ 35.000,00
Total Departamento $ 85.000,00

15                        44         $ 25.000,00
Total Departamento $ 25.000,00

Total Sucursal $ 115.000,00
. . . . . . . . . . . . . . . . . . . . . . . . . . 
SUCURSAL 5
Código Departamento     Código     Empleado Sueldo
10                        65         $ 50.000,00
Total Departamento $ 50.000,00


15                        88         $ 45.000,00
15                        24         $ 28.000,00
Total Departamento $ 73.000,00

Total Sucursal $ 123.000,00 

