#include "Core/Database.hpp"

int main() {
    Ambrosia::Core::Database db;
    db.Init("test.db");
    auto recipes = db.GetRecipes();

    for(auto& recipe : recipes)
    {
        std::cout << recipe.GetTitle() << "\n";
    }

    return 0;
}