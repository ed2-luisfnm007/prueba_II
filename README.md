# Prueba II — Estructura de Datos II (Q3 2026)

Examen en computadora. Duración: **1 hora 20 minutos**.

## Reglas

- **Libro abierto**: puede consultar sus ejercicios y material de apoyo previos.
- **Sin acceso a internet**: las bibliotecas se descargan desde el espejo local de
  Forgejo (ya configurado en `CMakeLists.txt`). No modifique las URLs.
- Trabaje únicamente en su repositorio.

## Cómo compilar y autoevaluarse

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

Cada ejercicio incluye una prueba unitaria (doctest) que usted ejecuta para
autoevaluarse. **Implemente las funciones marcadas con `TODO` en
`src/solution.cpp` de cada ejercicio.** No modifique los archivos de prueba
(`tests/`) ni las firmas de `src/solution.hpp`.

## Ejercicios

| # | Carpeta | Biblioteca | Tarea |
|---|---------|-----------|-------|
| 1 | `E1_Inventario_Gamer` | `fast-csv-parser` | Reporte de existencias desde CSV |
| 2 | `E2_Bitacora_Bancaria_NDJSON` | `nlohmann/json` | Balances por cuenta desde NDJSON |
| 3 | `E3_Conversor_CSV_JSON` | ambas | Convertir CSV a JSON y verificar round-trip |

## Referencia de API

La carpeta `reference/` contiene ejemplos de uso de ambas bibliotecas
(solo lectura, no se compilan). Consúltelos si necesita recordar la API.
