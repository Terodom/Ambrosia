#ifndef AMBROSIA_MODELS_RECIPE_HPP
#define AMBROSIA_MODELS_RECIPE_HPP

#include "Core/Models/ModelBase.hpp"
#include "Core/Entities/Recipe.hpp"

namespace Ambrosia::Core::Models
{
    class Recipe : public ModelBase<Entities::Recipe> {
        private:

        public:
            Recipe(Entities::Recipe recipe);
            Recipe(std::string title, std::string description);
            ~Recipe();

            // Getters
            std::string GetTitle();
            std::string GetDescription();

            // Setters
            void SetTitle(std::string title);
            void SetDescription(std::string description);
    };
}

#endif