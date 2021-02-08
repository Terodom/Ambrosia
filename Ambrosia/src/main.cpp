#include "Core/Database.hpp"

int main() {
    Ambrosia::Core::Database db;
    db.Init("test.db");
    auto test = db.GetRecipes();
    for(auto i : test) {
        std::cout << i.guid << "\n";
    }
    return 0;
}