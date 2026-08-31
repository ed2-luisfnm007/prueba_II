#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "solution.hpp"

#include <string>

static BankReport load() {
    return process_transactions(std::string(DATA_DIR) + "/transactions.ndjson");
}

TEST_CASE("E2: balances por cuenta") {
    const BankReport r = load();
    CHECK(r.balances.at("A-100") == doctest::Approx(1269.25));
    CHECK(r.balances.at("A-200") == doctest::Approx(720.00));
    CHECK(r.balances.at("A-300") == doctest::Approx(2500.00));
}

TEST_CASE("E2: registros validos e invalidos") {
    const BankReport r = load();
    CHECK(r.valid_records == 5);
    CHECK(r.invalid_records == 0);
}

TEST_CASE("E2: transacciones grandes") {
    const BankReport r = load();
    CHECK(r.large_transactions.size() == 2);
}
