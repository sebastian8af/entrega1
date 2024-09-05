#include <iostream>
using namespace std;

// Función para verificar si un número es palíndromo
bool esPalindromo(int numero) {
    int original = numero;
    int invertido = 0;
    while (numero > 0) {
        invertido = invertido * 10 + (numero % 10);
        numero /= 10;
    }
    return original == invertido;
}

// Función para calcular el número de divisores de un número
int contarDivisores(int num) {
    int conteo = 0;
    for (int i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
            if (i * i == num) {
                conteo++; // i es un divisor único
            } else {
                conteo += 2; // i y num / i son divisores
            }
        }
    }
    return conteo;
}
// Función para calcular la longitud de la serie de Collatz
int calcularLongitudCollatz(int n) {
    int longitud = 1; // La serie siempre comienza con el número n
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        longitud++;
    }
    return longitud;
}
// Función para calcular el máximo factor primo
int calcularMaximoFactorPrimo(int n) {
    int maxFactor = -1;

    // Dividir el número por 2 hasta que no sea divisible por 2
    while (n % 2 == 0) {
        maxFactor = 2;
        n /= 2;
    }

    // Dividir el número por todos los números impares a partir de 3
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            maxFactor = i;
            n /= i;
        }
    }

    // Si n es un número primo mayor que 2
    if (n > 2) {
        maxFactor = n;
    }

    return maxFactor;
}

// Función para calcular el máximo común divisor (MCD) usando el algoritmo de Euclides
int calcularMCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Función para calcular el mínimo común múltiplo (MCM) de dos números
int calcularMCM(int a, int b) {
    return (a * b) / calcularMCD(a, b);
}

// Función para calcular el MCM de todos los números entre 1 y n
int calcularMCMHastaN(int n) {
    int mcm = 1; // Inicializar el MCM como 1

    for (int i = 2; i <= n; ++i) {
        mcm = calcularMCM(mcm, i); // Actualizar el MCM usando el siguiente número
    }

    return mcm;
}

// Función para determinar si un número es primo
bool esPrimo(int numero) {
    if (numero < 2) return false; // Los números menores que 2 no son primos
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) return false; // Si es divisible por algún número, no es primo
    }
    return true;
}

// Función para encontrar el enésimo número primo
int encontrarEnesimoPrimo(int n) {
    int contador = 0; // Contador de números primos encontrados
    int numero = 1;   // Número que se va a evaluar como primo

    while (contador < n) {
        numero++;
        if (esPrimo(numero)) {
            contador++; // Incrementar el contador si es primo
        }
    }

    return numero; // Retornar el enésimo número primo
}

// Función para calcular el factorial de un número
double factorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Función para calcular el valor aproximado de e
double calcularEuler(int elementos) {
    double e = 0;
    for (int i = 0; i < elementos; ++i) {
        e += 1 / factorial(i);
    }
    return e;
}

void mostrarPatron(int n) {
    // Parte superior del patrón (número de líneas creciente)
    for (int i = 1; i <= n; i += 2) {
        // Imprimir espacios iniciales para centrar
        for (int j = 0; j < (n - i) / 2; j++)
            cout << " ";
        // Imprimir estrellas
        for (int j = 0; j < i; j++)
            cout << "*";

        cout << endl;
    }

    // Parte inferior del patrón (número de líneas decreciente)
    for (int i = n - 2; i >= 1; i -= 2) {
        // Imprimir espacios iniciales para centrar
        for (int j = 0; j < (n - i) / 2; j++)
            cout << " ";
        // Imprimir estrellas
        for (int j = 0; j < i; j++)
            cout << "*";

        cout << endl;
    }
}

// Función para validar si la hora o el tiempo son válidos
bool esHoraValida(int hora) {
    int horas = hora / 100;
    int minutos = hora % 100;
    return (horas >= 0 && horas < 24) && (minutos >= 0 && minutos < 60);
}

// Función para sumar la duración a la hora inicial
int sumarTiempo(int hora, int duracion) {
    int horasIniciales = hora / 100;
    int minutosIniciales = hora % 100;

    int horasDuracion = duracion / 100;
    int minutosDuracion = duracion % 100;

    int totalMinutos = minutosIniciales + minutosDuracion;
    int totalHoras = horasIniciales + horasDuracion + (totalMinutos / 60);

    totalMinutos %= 60;
    totalHoras %= 24;  // Asegurarse de que no exceda las 24 horas

    return (totalHoras * 100) + totalMinutos;
}

int Potencia(int base, int exponente); // Prototipo de una función

bool EsVocal(char caracter);
bool esBisiesto(int anio);

// Nueva función para calcular la suma de todos los primos menores que un número dado
int sumarPrimosMenores(int n) {
    int suma = 0;
    for (int i = 2; i < n; ++i) {
        if (esPrimo(i)) {
            suma += i;
        }
    }
    return suma;
}

int main() {
    int opcion = 1; // Definición de variables

    cout << endl;
    cout << "Bienvenido a la practica 1" << endl;

    while (opcion != 0) {
        cout << "Seleccione una opcion" << endl;
        cout << "1. Vocal o consonante" << endl;
        cout << "2. Combinacion de billetes" << endl;
        cout << "3. Combinacion de mes" << endl;
        cout << "4. Sumar horas y minutos" << endl;
        cout << "5. Mostrar patron" << endl;
        cout << "6. euler" << endl;
        cout << "7. la serie de Fibonacci" << endl;
        cout << "8. Suma los multiplos de dos numeros " << endl;
        cout << "9. digitos elevados a si mismos. "<< endl;
        cout << "10.enesimo numero primo. "<< endl;
        cout << "11.minimo comun multiplo "<< endl;
        cout << "12.mayor factor primo "<< endl;
        cout << "13.Suma de primos menores que n "<< endl;
        cout << "15.Matriz"<< endl;
        cout << "14.Palimdromo"<< endl;
        cout << "16.La serie de Collatz"<< endl;
        cout << "17.La secuencia de numeros triangulares"<< endl;
        cout << "0. Para salir" << endl;
        cin >> opcion;

        switch (opcion) {
        case 1: {
            char caracter;
            cout << "Ejecutando el problema 1 ..." << endl;
            cout << "Ingrese un caracter" << endl;
            cin >> caracter;
            if ((caracter >= 65 && caracter <= 90) || (caracter >= 97 && caracter <= 122)) {
                if (EsVocal(caracter))
                    cout << caracter << " es una vocal" << endl;
                else
                    cout << caracter << " es una consonante" << endl;
            } else {
                cout << caracter << " No es una letra" << endl;
            }
            break;
        }
        case 2: {
            int cantidad;
            cout << "Ingrese la cantidad de dinero (solo se pueden ingresar 10  digitos o menos): ";
            cin >> cantidad;

            int denominaciones[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
            int cantidadDenominaciones[10] = {0}; // Para guardar la cantidad de billetes/monedas de cada denominación
            int faltante = 0;

            // Calcular la mínima combinación de billetes y monedas
            for (int i = 0; i < 10; ++i) {
                cantidadDenominaciones[i] = cantidad / denominaciones[i];
                cantidad %= denominaciones[i];
            }

            // Si queda algún faltante (cantidad no divisible por las denominaciones)
            faltante = cantidad;

            // Imprimir el resultado
            for (int i = 0; i < 10; ++i) {
                cout << denominaciones[i] << " : " << cantidadDenominaciones[i] << endl;
            }
            if (faltante > 0) {
                cout << "Faltante: " << faltante << endl;
            } else {
                cout << "Faltante: 0" << endl;
            }
            break;
        }
        case 3: {
            int dia, mes;
            int anio = 2024; // Año de referencia para el caso bisiesto

            cout << "Ingrese el mes: ";
            cin >> mes;
            cout << "Ingrese el d1a: ";
            cin >> dia;

            // Validar el mes
            if (mes < 1 || mes > 12) {
                cout << mes << " es un mes invalido." << endl;
                break; // Detener la ejecución si el mes es inválido
            }

            // Días máximos por mes
            int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            // Caso especial para febrero en año bisiesto
            if (mes == 2 && dia == 29) {
                if (esBisiesto(anio)) {
                    cout << "29/2 es valida en bisiesto." << endl;
                } else {
                    cout << "29/2 es una fecha invalida." << endl;
                }
                break;
            }

            // Validar el día
            if (dia < 1 || dia > diasPorMes[mes - 1]) {
                cout << dia << "/" << mes << " es una fecha invalida." << endl;
            } else {
                cout << dia << "/" << mes << " es una fecha valida." << endl;
            }
            break;
        }
        case 4: {
            int hora, duracion;

            cout << "Ingrese la hora inicial (HHMM): ";
            cin >> hora;

            // Validar la hora inicial
            if (!esHoraValida(hora)) {
                cout << hora << " es un tiempo invalido." << endl;
                break; // Detener la ejecución si la hora es inválida
            }

            cout << "Ingrese la duracion (HHMM): ";
            cin >> duracion;

            // Validar la duración
            if (!esHoraValida(duracion)) {
                cout << duracion << " es un tiempo invalido." << endl;
                break; // Detener la ejecución si la duración es inválida
            }

            // Calcular la nueva hora
            int nuevaHora = sumarTiempo(hora, duracion);

            // Imprimir el resultado
            cout << "La hora es " << nuevaHora << "." << endl;
            break;
        }
        case 5: {
            int n;
            cout << "Ingrese el tamano del patron (un numero impar mayor que 1): ";
            cin >> n;
            mostrarPatron(n);

            break;
        }
        case 6:{
            int elementos;
            cout << "Ingrese el numero de elementos para la aproximacion: ";
            cin >> elementos;

            double e = calcularEuler(elementos);
            cout << "e es aproximadamente: " << e << endl;


            break;
        }
        case 7:{
            int n, a = 1, b = 1, sum = 0;

            cout << "Ingrese un numero n: ";
            cin >> n;

            while (true) {
                int fib = a + b; // Calcular el siguiente número de Fibonacci
                if (fib >= n) {
                    break; // Terminar el bucle si el número de Fibonacci es mayor o igual a n
                }
                if (fib % 2 == 0) {
                    sum += fib; // Sumar si el número de Fibonacci es par
                }
                a = b; // Actualizar los valores para el próximo ciclo
                b = fib;
            }

            cout << "El resultado de la suma es: " << sum << endl;
            break;
        }
        case 8:{
            int a, b, c;
            cout << "Ingrese los valores de a, b y c: ";
            cin >> a >> b >> c;

            int suma = 0;
            bool esPrimero = true;

            // Sumar múltiplos de a menores a c
            for (int i = a; i < c; i += a) {
                if (!esPrimero) {
                    cout << " + ";
                }
                cout << i;
                suma += i;
                esPrimero = false;
            }

            // Sumar múltiplos de b menores a c, excluyendo múltiplos comunes con a
            for (int i = b; i < c; i += b) {
                if (i % a != 0) { // Excluir múltiplos comunes
                    cout << " + " << i;
                    suma += i;
                }
            }

            cout << " = " << suma << endl;
            break;
        }
        case 9:{
            int N, suma = 0;
            cout << "Ingrese un numero entero: ";
            cin >> N;

            // Procesar cada dígito
            while (N > 0) {
                int digito = N % 10; // Obtener el ultimo digito
                suma += Potencia(digito, digito); // Elevar el digito a si mismo y sumar
                N /= 10; // Eliminar el ultimo digito
            }

            cout << "El resultado de la suma es: " << suma << endl;
            break;
        }
        case 10:{
            int n;
            cout << "Ingrese un numero entero n: ";
            cin >> n;

            int primo = encontrarEnesimoPrimo(n);
            cout << "El primo numero " << n << " es: " << primo << endl;
            break;
        }
        case 11:{
            int n;
            cout << "Ingrese un numero entero n: ";
            cin >> n;

            int mcm = calcularMCMHastaN(n);
            cout << "El minimo comun multiplo es: " << mcm << endl;
            break;
        }
        case 12:{
            int numero;
            cout << "Ingrese un numero entero: ";
            cin >> numero;

            int maxFactorPrimo = calcularMaximoFactorPrimo(numero);
            cout << "El mayor factor primo de " << numero << " es: " << maxFactorPrimo << endl;
            break;
        }
        case 13:{
            int numero;
            cout << "Ingrese un numero entero: ";
            cin >> numero;

            int sumaPrimos = sumarPrimosMenores(numero);
            cout << "El resultado de la suma es: " << sumaPrimos << endl;
            break;
        }
        case 14:{
            int maxPalindromo = 0;
            int factor1 = 0, factor2 = 0;

            for (int i = 100; i <= 999; ++i) {
                for (int j = i; j <= 999; ++j) { // Comenzar desde i para evitar repeticiones
                    int producto = i * j;
                    if (esPalindromo(producto) && producto > maxPalindromo) {
                        maxPalindromo = producto;
                        factor1 = i;
                        factor2 = j;
                    }
                }
            }

            cout << factor1 << " * " << factor2 << " = " << maxPalindromo << endl;
            break;
        }
        case 15: {
            int n;

            cout << "Ingrese un numero impar n: ";
            cin >> n;

            if (n % 2 == 0) {
                cout << "El numero debe ser impar." << endl;
                return 1;
            }

            // Crear la matriz espiral
            int espiral[n][n];
            int valor = 1;
            int x = n / 2, y = n / 2;
            espiral[x][y] = valor;

            int paso = 1;

            while (valor < n * n) {
                // Moverse hacia la derecha
                for (int i = 0; i < paso && valor < n * n; i++) {
                    y++;
                    valor++;
                    espiral[x][y] = valor;
                }
                // Moverse hacia abajo
                for (int i = 0; i < paso && valor < n * n; i++) {
                    x++;
                    valor++;
                    espiral[x][y] = valor;
                }
                paso++;
                // Moverse hacia la izquierda
                for (int i = 0; i < paso && valor < n * n; i++) {
                    y--;
                    valor++;
                    espiral[x][y] = valor;
                }
                // Moverse hacia arriba
                for (int i = 0; i < paso && valor < n * n; i++) {
                    x--;
                    valor++;
                    espiral[x][y] = valor;
                }
                paso++;
            }

            // Calcular la suma de las diagonales
            int suma = 0;
            for (int i = 0; i < n; i++) {
                suma += espiral[i][i];               // Diagonal principal
                suma += espiral[i][n - 1 - i];       // Diagonal secundaria
            }
            // Evitar contar el centro dos veces si n es impar
            suma -= espiral[n / 2][n / 2];

            cout << "En una espiral de " << n << "x" << n << ", la suma es: " << suma << "." << endl;
            break;
        }
        case 16:{
            int k;
            cout << "Ingrese un numero entero k: ";
            cin >> k;

            int maxLongitud = 0;
            int mejorSemilla = 0;

            // Buscar la semilla menor que k que produce la serie más larga
            for (int i = 1; i < k; i++) {
                int longitudActual = calcularLongitudCollatz(i);
                if (longitudActual > maxLongitud) {
                    maxLongitud = longitudActual;
                    mejorSemilla = i;
                }
            }

            // Imprimir el resultado
            cout << "La serie mas larga es con la semilla: " << mejorSemilla << ", teniendo " << maxLongitud << " terminos." << endl;
            break;
        }
        case 17:{
            int k;
            cout << "Ingrese un numero entero k: ";
            cin >> k;

            int n = 1;
            while (true) {
                // Calcular el enésimo número triangular
                int triangular = n * (n + 1) / 2;

                // Contar los divisores del número triangular
                int numDivisores = contarDivisores(triangular);

                // Verificar si el número de divisores es mayor que k
                if (numDivisores > k) {
                    cout << "El primer numero triangular con mas de " << k << " divisores es: " << triangular << endl;
                    break;
                }

                // Incrementar n para el siguiente número triangular
                n++;
            }
            break;
        }
        default:
            if (opcion != 0)
                cout << "Opcion no valida" << endl;
            break;
        }
    }
    return 0;
}

// Definición de la función EsVocal
bool EsVocal(char caracter) {
    if (caracter >= 97)
        caracter -= 32;

    return (caracter == 'A' || caracter == 'E' || caracter == 'I' || caracter == 'O' || caracter == 'U');
}
// Función para calcular la potencia de un numero
int Potencia(int base, int exponente) {
    int x = 1;
    for (int i = 0; i < exponente; i++) {
        x *= base;
    }
    return x;
}

// Función que determina si un año es bisiesto
bool esBisiesto(int anio) {
    return (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0));
}
