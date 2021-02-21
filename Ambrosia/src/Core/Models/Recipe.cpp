#include "Core/Models/Recipe.hpp"

namespace Ambrosia::Core::Models
{
    Recipe::Recipe(Entities::Recipe recipe) : ModelBase(recipe) {
        this->SetTitle(recipe.title);
        this->SetDescription(recipe.description);
    }

    Recipe::Recipe(std::string title, std::string description) : ModelBase()
    {
        this->SetTitle(title);
        this->SetDescription(description);
    }

    Recipe::~Recipe() {

    }

    #pragma region "Getters"

    std::string Recipe::GetTitle() {
        return this->entity.title;
    }

    std::string Recipe::GetDescription() {
        return this->entity.description;
    }

    #pragma endregion


    #pragma region "Setters"

    void Recipe::SetTitle(std::string title) {
        this->entity.title = title;
    }

    void Recipe::SetDescription(std::string description) {
        this->entity.description = description;
    }

    #pragma endregion

}