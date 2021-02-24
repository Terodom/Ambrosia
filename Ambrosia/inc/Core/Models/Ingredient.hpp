#ifndef AMBROSIA_MODELS_INGREDIENT_HPP
#define AMBROSIA_MODELS_INGREDIENT_HPP

#include "Core/Models/MeasurementUnit.hpp"
#include "Core/Models/Recipe.hpp"
#include "Core/Entities/Ingredient.hpp"

namespace Ambrosia::Core::Models
{
    class Ingredient : public ModelBase<Entities::Ingredient> {
        public:
            explicit Ingredient(const Entities::Ingredient& ing);
            Ingredient(const std::string& name, const double& amount, MeasurementUnit unit, Recipe recipe);
            ~Ingredient();

            // Getters
            std::string GetName();
            double GetAmount();
            Guid GetMeasurementUnitGuid();
            Guid GetRecipeGuid();

            // Setters
            void SetName(const std::string& name);
            void SetAmount(const double& amount);
            void SetMeasurementUnitGuid(const Guid& guid);
            void SetRecipeGuid(const Guid& guid);
    };
}

#endif