#include "Core/Database.hpp"

int main() {
    Ambrosia::Core::Database db;
    db.Init("test.db");
    auto recipes = db.GetRecipes();
    auto ingredients = db.GetIngredients();
    auto mus = db.GetMeasurementUnits();

    for(auto& recipe : recipes)
    {
        std::cout << recipe.GetTitle() << " ";
    }
    for(auto& ingredient : ingredients)
    {
        std::cout << ingredient.GetAmount() << " ";
    }
    for(auto& mu : mus)
    {
        std::cout << mu.GetName() << "\n";
    }

    return 0;
}