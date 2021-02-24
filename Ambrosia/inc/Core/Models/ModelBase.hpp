#ifndef AMBROSIA_MODELS_MODELBASE_HPP
#define AMBROSIA_MODELS_MODELBASE_HPP

#include "Core/Entities/Recipe.hpp"

namespace Ambrosia::Core::Models
{
    /**
     * Model Base for all Ambrosia Models
     *
     * Databse Entity will be stored in this Class
     *
     * @brief Generic ModelBase for all Database Models
     * @param T Class derived from Ambrosia::Core::Entities::EntityBase
     * @see Core::Entities::Entitybase
     */
    template<class T>
    class ModelBase {
        protected:
            T entity;
            // Setters

            void SetNewGuid();
            void SetCreatedAtNow();

        public:
            ModelBase();
            explicit ModelBase(T entity);

            ~ModelBase();
    
            // Getters
            T GetEntity();
            Guid GetGUID();
            std::string GetGUIDAsString();
            std::tm GetCreatedAt();

            // Setters

            void SetGUID(Guid guid);
            void SetCreatedAt(std::tm created_at);
    };
}

#include "../src/Core/Models/ModelBase.inl"


#endif