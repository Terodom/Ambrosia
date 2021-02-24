#include "Core/Models/Recipe.hpp"

namespace Ambrosia::Core::Models
{
    Recipe::Recipe(const Entities::Recipe& recipe) : ModelBase(recipe) {

    }

    Recipe::Recipe(const std::string& title, const std::string& description) : ModelBase()
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

    void Recipe::SetTitle(const std::string& title) {
        this->entity.title = title;
    }

    void Recipe::SetDescription(const std::string& description) {
        this->entity.description = description;
    }

    #pragma endregion

}