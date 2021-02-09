#ifndef AMBROSIA_MODELS_RECIPE_HPP
#define AMBROSIA_MODELS_RECIPE_HPP

#include "Core/Entities/Recipe.hpp"

namespace Ambrosia::Core::Models
{
    class Recipe {
        private:
            Entities::Recipe recipe;

        public:
            // TODO: Add Constructors
            Recipe(Entities::Recipe recipe);
            ~Recipe();

            // Getters
            boost::uuids::uuid GetGUID();
            std::tm GetCreatedAt();
            std::string GetTitle();
            std::string GetDescription();

            // Setters
            void SetGUID(boost::uuids::uuid guid);
            void SetCreatedAt(std::tm created_at);
            void SetTitle(std::string title);
            void SetDescription(std::string description);

    };
}

#endif