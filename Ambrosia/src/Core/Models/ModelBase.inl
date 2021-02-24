#include "Core/Models/ModelBase.hpp"

namespace Ambrosia::Core::Models
{

    #pragma region "Constructors"

    template <class T>
    ModelBase<T>::ModelBase() {
        this->entity = T();
        this->SetNewGuid();
        this->SetCreatedAtNow();
    }

    template <class T>
    ModelBase<T>::ModelBase(T entity) {
        this->entity = entity;
    }

    template <class T>
    ModelBase<T>::~ModelBase() {
        //delete this->entity;
    }

    template <class T>
    void ModelBase<T>::SetNewGuid() {
        boost::uuids::random_generator gen;
        this->SetGUID(gen());
    }

    #pragma endregion


    #pragma region "Getters"

    template <class T>
    T ModelBase<T>::GetEntity() {
        return this->entity;
    }

    template <class T>
    Guid ModelBase<T>::GetGUID() {
        boost::uuids::string_generator gen;
        return gen(this->entity.guid);
    }

    template <class T>
    std::string ModelBase<T>::GetGUIDAsString() {
        return Utils::GUIDToString(this->GetGUID());
    }

    template <class T>
    std::tm ModelBase<T>::GetCreatedAt() {
        return this->entity.created_at;
    }
    #pragma endregion


    #pragma region "Setters"

    template <class T>
    void ModelBase<T>::SetCreatedAtNow() {
        std::time_t now = std::time(0);
        this->SetCreatedAt(*std::localtime(&now));
    }

    template <class T>
    void ModelBase<T>::SetGUID(boost::uuids::uuid guid)
    {
        this->entity.guid = Utils::GUIDToString(guid);
    }

    template <class T>
    void ModelBase<T>::SetCreatedAt(std::tm created_at)
    {
        this->entity.created_at = created_at;
    }

    #pragma endregion
}