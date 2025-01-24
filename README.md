# Push_swap

## Resumen del proyecto

El proyecto *Push_swap* consiste en crear un programa en C capaz de ordenar un conjunto de números enteros utilizando dos pilas (*stacks*) y un conjunto limitado de instrucciones. El objetivo principal es implementar algoritmos de ordenamiento eficientes y minimizar la cantidad de operaciones necesarias para lograr el resultado deseado.

Este proyecto permite demostrar competencias en:

- Diseño e implementación de algoritmos.
- Optimización de recursos y análisis de complejidad algorítmica.
- Programación en C y manejo de memoria dinámica.
- Trabajo bajo restricciones y validación de resultados.

## Funcionalidad principal

El programa principal, llamado `push_swap`, recibe como entrada un conjunto de números enteros y genera la secuencia de instrucciones necesaria para ordenarlos en orden ascendente dentro de un stack. Estas instrucciones incluyen:

- `sa`, `sb`, `ss`: Intercambiar los dos primeros elementos de un stack.
- `pa`, `pb`: Mover el primer elemento de un stack a otro.
- `ra`, `rb`, `rr`: Rotar un stack hacia arriba.
- `rra`, `rrb`, `rrr`: Rotar un stack hacia abajo.

### Ejemplo de ejecución

1. Ejecución del programa:
   ```bash
   ./push_swap 2 1 3 6 5 8
   ```

2. Resultado esperado (ejemplo de salida):
   ```bash
   sa
   pb
   pb
   pb
   sa
   pa
   pa
   pa
   ```

### Validación del resultado

Durante la evaluación, el programa debe generar la lista de instrucciones más corta posible para ordenar correctamente los números en el stack. Además, se realizará una prueba de rendimiento para evaluar la eficiencia del algoritmo:

- Ordenar 100 números en menos de 700 operaciones.
- Ordenar 500 números en menos de 5500 operaciones.

## Estructura del proyecto

- **Archivos entregados:**
  - `Makefile`: Para compilar el proyecto con las reglas habituales (`all`, `clean`, `fclean`, `re`).
  - Archivos fuente (`*.c`) y de cabecera (`*.h`).

- **Normas del proyecto:**
  - Cumplir con la "Norma" establecida.
  - No utilizar variables globales.
  - Gestionar adecuadamente los errores y evitar fugas de memoria (*leaks*).

## Objetivo del aprendizaje

El proyecto *Push_swap* proporciona una base sólida en el diseño de algoritmos y optimización, habilidades esenciales para desarrolladores. Además, aborda temas relevantes para entrevistas técnicas y proyectos en el mundo real:

- Complejidad algorítmica.
- Resolución eficiente de problemas bajo restricciones.
- Validación exhaustiva y depuración.
