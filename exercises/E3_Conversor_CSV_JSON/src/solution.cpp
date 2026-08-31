#include "solution.hpp"

#include "csv.h"
#include <nlohmann/json.hpp>

#include <fstream>
#include <stdexcept>

ConversionResult convert_and_verify(const std::string& csv_path,
                                    const std::string& json_out_path) {
    ConversionResult result;

    // TODO: lea el CSV con fast-csv-parser (sku, name, stock, price).
    //
    // TODO: construya un nlohmann::json con:
    //   - "warehouse" (cadena fija, p. ej. "TGU-A")
    //   - "generated_at" (cadena con la fecha/hora)
    //   - "products" (arreglo de objetos {sku, name, stock, price})
    //
    // TODO: persista con dump(2) (sangría de 2 espacios) y cierre el archivo.
    //
    // TODO: vuelva a abrir el JSON y verifique:
    //   - igual número de productos
    //   - cada SKU aparece exactamente una vez
    //   - name coincide exactamente
    //   - stock coincide como entero
    //   - price coincide con tolerancia 0.0001
    //   Registre cada diferencia en result.differences y fije result.verified.

    return result;
}
