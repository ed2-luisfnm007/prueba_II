#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "solution.hpp"

#include <string>

static InventoryReport load() {
    return analyze_inventory(std::string(DATA_DIR) + "/products.csv");
}

TEST_CASE("E1: valor total del inventario") {
    const InventoryReport r = load();
    CHECK(r.total_value == doctest::Approx(1707.63));
}

TEST_CASE("E1: producto agotado") {
    const InventoryReport r = load();
    REQUIRE(r.out_of_stock.size() == 1);
    CHECK(r.out_of_stock[0] == "P103");
}

TEST_CASE("E1: producto con stock bajo") {
    const InventoryReport r = load();
    REQUIRE(r.low_stock.size() == 1);
    CHECK(r.low_stock[0] == "P102");
}

TEST_CASE("E1: precio unitario mas alto") {
    const InventoryReport r = load();
    CHECK(r.highest_price_sku == "P102");
    CHECK(r.highest_price == doctest::Approx(199.95));
}
