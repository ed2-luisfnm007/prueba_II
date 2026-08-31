#pragma once

#include <string>
#include <vector>

struct Product {
    std::string sku;
    std::string name;
    int stock = 0;
    double price = 0.0;
};

struct InventoryReport {
    double total_value = 0.0;
    std::vector<std::string> out_of_stock;  // SKUs con stock == 0
    std::vector<std::string> low_stock;     // SKUs con 0 < stock < 10
    std::string highest_price_sku;
    double highest_price = 0.0;
};

// Lee el CSV (las columnas pueden aparecer en cualquier orden) y calcula el
// reporte de existencias. Debe leer los campos por NOMBRE de encabezado.
InventoryReport analyze_inventory(const std::string& csv_path);
