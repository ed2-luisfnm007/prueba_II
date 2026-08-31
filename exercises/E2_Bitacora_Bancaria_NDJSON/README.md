# Ejercicio E2 — Bitácora bancaria NDJSON

## Objetivo
Procesar una bitácora de transacciones en formato NDJSON con `nlohmann/json`,
una línea a la vez.

## Archivo de apoyo
- `data/transactions.ndjson`: cada línea es un objeto JSON completo e
  independiente.

## Actividades
Implemente `process_transactions` en `src/solution.cpp` para:

1. Leer el archivo **línea por línea**; no cargue el archivo completo en un
   único arreglo JSON.
2. Convertir cada línea a un objeto JSON.
3. Calcular el balance por cuenta: `CREDIT` suma y `DEBIT` resta.
4. Reportar transacciones mayores o iguales a $1,000.
5. Rechazar y reportar cualquier línea que no sea JSON válido, sin detener el
   procesamiento.

## Autoevaluación
```bash
cmake --build build --target e2_test
ctest --test-dir build -R e2_test --output-on-failure
```

## Criterios de validación
- 5 registros válidos, 0 inválidos.
- Balances: `A-100 = $1269.25`, `A-200 = $720.00`, `A-300 = $2500.00`.
- 2 transacciones grandes (>= $1,000).

## Pista de API
```cpp
std::ifstream input(path);
std::string line;
while (std::getline(input, line)) {
    nlohmann::json obj = nlohmann::json::parse(line);  // lanza excepción si es inválido
    std::string account = obj.at("account").get<std::string>();
    double amount = obj.at("amount").get<double>();
}
```
