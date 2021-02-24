#include "Core/Models/Ingredient.hpp"

namespace Ambrosia::Core::Models
{
    Ingredient::Ingredient(const Entities::Ingredient& ing) : ModelBase(ing) {

    }
    
    Ingredient::Ingredient(const std::string& name, const double& amount, MeasurementUnit unit, Recipe recipe) : ModelBase() {
        this->SetName(name);
        this->SetAmount(amount);
        this->SetMeasurementUnitGuid(unit.GetGUID());
        this->SetRecipeGuid(recipe.GetGUID());
    }

    Ingredient::~Ingredient() {

    }


    std::string Ingredient::GetName() {
        return this->entity.name;
    }

    double Ingredient::GetAmount() {
        return this->entity.amount;
    }

    Guid Ingredient::GetMeasurementUnitGuid() {
        return Utils::GUIDFromString(entity.measurement_units_guid);
    }

    Guid Ingredient::GetRecipeGuid() {
        return Utils::GUIDFromString(entity.recipes_guid);
    }



    void Ingredient::SetName(const std::string& name) {
        this->entity.name = name;
    }

    void Ingredient::SetAmount(const double& amount) {
        this->entity.amount = amount;
    }

    void Ingredient::SetMeasurementUnitGuid(const Guid& guid) {
        this->entity.measurement_units_guid = Utils::GUIDToString(guid);
    }

    void Ingredient::SetRecipeGuid(const Guid& guid) {
        this->entity.recipes_guid = Utils::GUIDToString(guid);
    }
}