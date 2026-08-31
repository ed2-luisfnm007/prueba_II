# Reglas de validación

La comparación entre la fuente CSV y el JSON generado debe comprobar:

1. Igual número de productos.
2. Cada SKU del CSV aparece exactamente una vez en JSON.
3. `name` coincide exactamente.
4. `stock` coincide como entero.
5. `price` coincide como número; puede compararse con tolerancia de `0.0001` para evitar problemas de representación de punto flotante.
6. El JSON contiene además `warehouse` y `generated_at` como metadatos de nivel superior.

El reporte debe indicar `VALIDATION PASSED` o describir el SKU y campo que difiere.
