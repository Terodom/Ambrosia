#include "Core/Database.hpp"

namespace Ambrosia::Core
{
    Database::Database() {

    }

    Database::~Database() {

    }

    void Database::Init(const std::string& connectionString)
    {
        this->sql = make_unique<soci::session>("sqlite3", "dbname=test.db");
        Entities::Recipe::InitTable(*sql);
        Entities::MeasurementUnit::InitTable(*sql);
        Entities::Ingredient::InitTable(*sql);

        Models::Recipe recipe("test", "teasasfst");
        Models::MeasurementUnit unit("Liter");
        Models::Ingredient ingredient("Wasser", 2, unit, recipe);

        this->Add(recipe);
        this->Add(unit);
        this->Add(ingredient);
    }


    #pragma region "Adders"

    void Database::Add(Models::Recipe& recipe) {
        auto entity = recipe.GetEntity();
        Entities::Recipe::Add(*sql, entity);
    }

    void Database::Add(Models::Ingredient& ingredient) {
        auto entity = ingredient.GetEntity();
        Entities::Ingredient::Add(*sql, entity);
    }

    void Database::Add(Models::MeasurementUnit& measurement_unit) {
        auto entity = measurement_unit.GetEntity();
        Entities::MeasurementUnit::Add(*sql, entity);
    }

    #pragma endregion


    #pragma region "EntityAcessors"

    std::vector<Models::Recipe> Database::GetRecipes() {
        if(!GetSQLInitialized()) {
            std::cerr << "ERROR: Database not Initialized...\n";
            throw std::runtime_error("Database not initialized");
        }

        soci::rowset<Entities::Recipe> rs = (sql->prepare << "SELECT * FROM recipes");
        std::vector<Models::Recipe> recipes;

        for(auto i : rs)
        {
            Models::Recipe recipe(i);
            recipes.push_back(recipe);
        }

        return recipes;
    }

    std::vector<Models::Ingredient> Database::GetIngredients() {
        if(!GetSQLInitialized()) {
            std::cerr << "ERROR: Database not Initialized...\n";
            throw std::runtime_error("Database not initialized");
        }

        soci::rowset<Entities::Ingredient> rs = (sql->prepare << "SELECT * FROM ingredients");
        std::vector<Models::Ingredient> ingredients;

        for(auto i : rs)
        {
            Models::Ingredient ingredient(i);
            ingredients.push_back(ingredient);
        }

        return ingredients;
    }

    std::vector<Models::MeasurementUnit> Database::GetMeasurementUnits() {
        if(!GetSQLInitialized()) {
            std::cerr << "ERROR: Database not Initialized...\n";
            throw std::runtime_error("Database not initialized");
        }

        soci::rowset<Entities::MeasurementUnit> rs = (sql->prepare << "SELECT * FROM measurement_units");
        std::vector<Models::MeasurementUnit> measurement_units;

        for(auto i: rs)
        {
            Models::MeasurementUnit measurement_unit(i);
            measurement_units.push_back(measurement_unit);
        }

        return measurement_units;
    }
    #pragma endregion
}
