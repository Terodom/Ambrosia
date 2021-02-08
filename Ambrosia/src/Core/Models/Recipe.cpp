#include "Core/Models/Recipe.hpp"

namespace Ambrosia::Core::Models
{
    Recipe::Recipe() {

    }

    Recipe::~Recipe() {

    }

#pragma region "Getters"

    boost::uuids::uuid Recipe::GetGUID() {
        boost::uuids::string_generator gen;
        return gen(this->recipe.guid);
    }

    std::tm Recipe::GetCreatedAt() {
        return this->recipe.created_at;
    }

    std::string Recipe::GetTitle() {
        return this->recipe.title;
    }

    std::string Recipe::GetDescription() {
        return this->recipe.description;
    }

#pragma endregion
#pragma region "Setters"

    void Recipe::SetGUID(boost::uuids::uuid guid) {
        this->recipe.guid = boost::uuids::to_string(guid);
    }

    void Recipe::SetCreatedAt(std::tm created_at) {
        this->recipe.created_at = created_at;
    }

    void Recipe::SetTitle(std::string title) {
        this->recipe.title = title;
    }

    void Recipe::SetDescription(std::string description) {
        this->recipe.description = description;
    }

#pragma endregion
}