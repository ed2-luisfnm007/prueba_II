# Ejercicio E1 — Inventario de una tienda gamer

## Objetivo
Procesar un CSV de inventario con `fast-csv-parser` y producir un reporte de
existencias.

## Archivo de apoyo
- `data/products.csv`: inventario inicial. Sus columnas pueden aparecer en
  distinto orden y pueden existir columnas que no se utilicen.

## Actividades
Implemente `analyze_inventory` en `src/solution.cpp` para:

1. Leer los campos `sku`, `name`, `stock` y `price` **por nombre de encabezado**.
2. Calcular el valor total del inventario (`stock × price`).
3. Listar los productos agotados (`stock == 0`) y los de stock bajo
   (`0 < stock < 10`).
4. Identificar el producto con el precio unitario más alto.

## Autoevaluación
```bash
cmake --build build --target e1_test
ctest --test-dir build -R e1_test --output-on-failure
```

## Criterios de validación
- Valor total esperado: **$1,707.63**.
- Producto agotado: **P103**.
- Stock bajo: **P102**.
- Precio más alto: **P102** ($199.95).

## Pista de API
```cpp
io::CSVReader<4> reader(csv_path);
reader.read_header(io::ignore_extra_column, "sku", "name", "stock", "price");
std::string sku, name; int stock; double price;
while (reader.read_row(sku, name, stock, price)) { /* ... */ }
```
