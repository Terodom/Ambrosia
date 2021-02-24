#ifndef AMBROSIA_MODELS_RECIPE_HPP
#define AMBROSIA_MODELS_RECIPE_HPP

#include "Core/Models/ModelBase.hpp"
#include "Core/Entities/Recipe.hpp"

namespace Ambrosia::Core::Models
{
    class Recipe : public ModelBase<Entities::Recipe> {
        public:
            explicit Recipe(const Entities::Recipe& recipe);
            Recipe(const std::string& title, const std::string& description);
            ~Recipe();

            // Getters
            std::string GetTitle();
            std::string GetDescription();

            // Setters
            void SetTitle(const std::string& title);
            void SetDescription(const std::string& description);
    };
}

#endif