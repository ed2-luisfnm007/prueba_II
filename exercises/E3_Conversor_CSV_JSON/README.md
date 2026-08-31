# Ejercicio E3 — Conversor CSV a JSON con verificación

## Objetivo
Transformar un inventario CSV a JSON y verificar que la persistencia no haya
alterado los datos.

## Archivos de apoyo
- `data/products.csv`: archivo CSV de entrada.
- `data/validation_rules.md`: reglas de comparación requeridas.

## Actividades
Implemente `convert_and_verify` en `src/solution.cpp` para:

1. Leer el CSV usando `fast-csv-parser`.
2. Construir un documento JSON con `warehouse`, `generated_at` y un arreglo
   `products`.
3. Persistir el resultado con `nlohmann/json` y sangría de dos espacios.
4. Volver a abrir el JSON generado.
5. Comprobar que el número de registros, SKU, stock y precio de cada producto
   coincidan con el CSV fuente (precio con tolerancia `0.0001`).
6. Fijar `verified` y registrar cada diferencia encontrada.

## Autoevaluación
```bash
cmake --build build --target e3_test
ctest --test-dir build -R e3_test --output-on-failure
```

## Criterios de validación
- 4 productos.
- `verified == true` y sin diferencias.

## Pista de API
```cpp
// CSV
io::CSVReader<4> reader(csv_path);
reader.read_header(io::ignore_extra_column, "sku", "name", "stock", "price");

// JSON
nlohmann::json doc = {
    {"warehouse", "TGU-A"},
    {"generated_at", "2026-07-15T10:30:00Z"},
    {"products", nlohmann::json::array()}
};
doc["products"].push_back({{"sku", sku}, {"name", name}, {"stock", stock}, {"price", price}});
std::ofstream out(json_out_path);
out << doc.dump(2) << '\n';
```
