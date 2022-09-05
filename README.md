# t1_cyp
Taller 1 para la asignatura de Computación paralela y distribuida. 

## Integrantes
- Benjamin Alexander Castro Donoso Barrera Salas
- German Alejandro Ramirez Obaid
- Enzo Maximiliano Valle Mateluna
- Paulo Andres Hernandez Torreblanca

## Instalacion

Para este proyecto se utilizo Pop!_OS que es una distribución de Linux gratuita y de código abierto, basada en Ubuntu.
Para ubuntu y distribuciones similares como Pop!_os, se puede instalar make con el siguiente comando:
```bash
 user@machine:~$ sudo apt install make
```

Para compilar el programa sera necesario hacer los siguientes pasos
```bash
git clone https://github.com/benjacd/t1_cyp           # Clonar el repositorio
cd t1_cyp
make main
./main "Argumentos"                                   # En argumentos se debera ingresar el polinomio
```

Importante
```bash
Para poder utilizar de forma correcta el programa, se debera tener en consideración la siguiente condición:
Para las X que no esten acompañadas con un coeficiente numerico debera tener la forma 1x.
Ejemplo: 
./main " 1x**2 + 1x-1"
```


