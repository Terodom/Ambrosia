#ifndef AMBROSIA_LIB_ENTITIES_RECIPE_HPP
#define AMBROSIA_LIB_ENTITIES_RECIPE_HPP

#include "EntityBase.hpp"


namespace Ambrosia::Core::Entities
{
    class Recipe : public EntityBase {
        public:
            Recipe();
            Recipe(const std::string& title, const std::string& description);
            Recipe(const std::string& guid, const std::tm& created_at, const std::string& title, const std::string& description);
            ~Recipe();

            std::string title;
            std::string description;

            static void InitTable(soci::session& sql);
            static void Add(soci::session& sql, Recipe& recipe);
            static void Delete(soci::session& sql, const Recipe& recipe);
    };
}

namespace soci
{

    namespace Entities = Ambrosia::Core::Entities;

    template<>
    struct type_conversion<Entities::Recipe>
    {
        typedef values base_type;

        static void from_base(values const& v, indicator ind, Entities::Recipe& r)
        {
            r.guid = v.get<std::string>("guid");
            r.created_at = v.get<std::tm>("created_at");
            r.title = v.get<std::string>("title");
            r.description = v.get<std::string>("description");
        }

        static void to_base(const Entities::Recipe& r, values& v, indicator& ind)
        {
            v.set("guid", r.guid);
            v.set("created_at", r.created_at);
            v.set("title", r.title);
            v.set("description", r.description);

            ind = i_ok;
        }
    };
}

#endif