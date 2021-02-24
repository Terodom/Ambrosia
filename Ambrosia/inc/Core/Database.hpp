#ifndef AMBROSIA_LIB_DATABASE_HPP
#define AMBROSIA_LIB_DATABASE_HPP

#include <iostream>
#include <stdexcept>

#include "Models/Ingredient.hpp"

namespace Ambrosia
{

    namespace Core
    {

        using std::unique_ptr;
        using std::make_unique;

        class Database {
            private:
                std::string connectionString;
                unique_ptr<soci::session> sql;

            public:
                Database();
                ~Database();

                void Init(const std::string& connectionString);

                const inline bool GetSQLInitialized() { return sql != nullptr; };


                #pragma region "Adders"

                void Add(Models::Recipe& recipe);
                void Add(Models::Ingredient& ingredient);
                void Add(Models::MeasurementUnit& measurement_unit);

                #pragma endregion


                #pragma region "EntityAcessors"

                std::vector<Models::Recipe> GetRecipes();
                std::vector<Models::Ingredient> GetIngredients();
                std::vector<Models::MeasurementUnit> GetMeasurementUnits();

                #pragma endregion

        };
    }
}

#endif