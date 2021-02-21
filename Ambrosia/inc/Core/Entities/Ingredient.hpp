#ifndef AMBROSIA_INGREDIENT_HPP
#define AMBROSIA_INGREDIENT_HPP

#include "EntityBase.hpp"

namespace Ambrosia::Core::Entities
{
    class Ingredient : public EntityBase {
        public:
            Ingredient();
            ~Ingredient();

            std::string recipes_guid;

            static void InitTable(soci::session& sql);
            static void Add(soci::session& sql, Ingredient& ingredient);
            static void Delete(soci::session&, Ingredient& ingredient);
    };
}

#endif