#include "solution.hpp"

#include "csv.h"
#include <nlohmann/json.hpp>

#include <fstream>
#include <stdexcept>

namespace nl = nlohmann;

ConversionResult convert_and_verify(const std::string &csv_path,
                                    const std::string &json_out_path)
{
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

    io::CSVReader<4> reader(csv_path);

    std::string sku;
    std::string name;
    int stock;
    double price;

    reader.read_header(io::ignore_no_column, "sku", "name", "stock", "price");

    nlohmann::json doc = {{"warehouse", "TGU-A"},
                          {"generated_at", "2026-07-15T10:30:00Z"},
                          {"products", nlohmann::json::array()}};

    int recordCount = 0;
    while (reader.read_row(sku, name, stock, price))
    {
        doc["products"].push_back({{"sku", sku},
                                   {"name", name},
                                   {"stock", stock},
                                   {"price", price}});
        recordCount++;
    }

    std::ofstream out(json_out_path);

    out << doc.dump(2) << '\n';
    out.close();

    std::ifstream in(json_out_path);

    in >> doc;

    reader.set_file_line(1);
    int pos = 0;

    result.verified = true;

    while (reader.read_row(sku, name, stock, price))
    {
        const auto arr = doc.at("products");
        if (arr[pos].at("sku").get<std::string>() != sku)
        {
            result.verified = false;
            result.differences.push_back("different sku");
        }

        if (arr[pos].at("name").get<std::string>() != name)
        {
            result.verified = false;
            result.differences.push_back("differente name");
        }

        if (arr[pos].at("stock").get<int>() != stock)
        {
            result.verified = false;
            result.differences.push_back("different stock");
        }

        if (arr[pos].at("price").get<double>() != price)
        {
            result.verified = false;
            result.differences.push_back("differente price");
        }
    }

    result.record_count = recordCount;

    return result;
}
