#include "solution.hpp"

#include "csv.h"

#include <stdexcept>

InventoryReport analyze_inventory(const std::string& csv_path) {
    InventoryReport report;

    // TODO: abra el CSV con io::CSVReader<4> y lea el encabezado por nombre:
    //   io::CSVReader<4> reader(csv_path);
    //   reader.read_header(io::ignore_extra_column, "sku", "name", "stock", "price");
    //
    // TODO: declare las variables sku, name, stock, price y recorra las filas
    //   con reader.read_row(sku, name, stock, price).
    //
    // TODO: acumule total_value (stock * price), detecte out_of_stock (stock == 0)
    //   y low_stock (0 < stock < 10), y registre el precio unitario más alto.

    return report;
}
