#ifndef AMBROSIA_INGREDIENT_HPP
#define AMBROSIA_INGREDIENT_HPP

#include "EntityBase.hpp"

namespace Ambrosia::Core::Entities
{
    class Ingredient : public EntityBase {
        public:
            Ingredient();
            Ingredient(const std::string& name, double amount, const std::string& measurement_units_guid, const std::string& recipes_guid);
            ~Ingredient();

            // Properties
            double amount;
            std::string name;
            std::string measurement_units_guid;
            std::string recipes_guid;

            // Functions
            static void InitTable(soci::session& sql);
            static void Add(soci::session& sql, Ingredient& ing);
            static void Delete(soci::session&, const Ingredient& ing);
    };
}

namespace soci
{

    namespace Entities = Ambrosia::Core::Entities;

    template<>
    struct type_conversion<Entities::Ingredient>
    {
        typedef values base_type;

        static void from_base(values const& v, indicator ind, Entities::Ingredient& r)
        {
            r.guid = v.get<std::string>("guid");
            r.created_at = v.get<std::tm>("created_at");
            r.name = v.get<std::string>("name");
            r.amount = v.get<double>("amount");
            r.measurement_units_guid = v.get<std::string>("measurement_units_guid");
            r.recipes_guid = v.get<std::string>("recipes_guid");
        }

        static void to_base(const Entities::Ingredient& r, values& v, indicator& ind)
        {
            v.set("guid", r.guid);
            v.set("created_at", r.created_at);
            v.set("name", r.name);
            v.set("amount", r.amount);
            v.set("measurement_units_guid", r.measurement_units_guid);
            v.set("recipes_guid", r.recipes_guid);

            ind = i_ok;
        }
    };
}

#endif