#ifndef AMBROSIA_UTILS_HPP
#define AMBROSIA_UTILS_HPP

#include <string>

#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_generators.hpp"
#include "boost/uuid/uuid_io.hpp"
#include "boost/lexical_cast.hpp"

namespace Ambrosia {

    using Guid = boost::uuids::uuid;

    namespace Core::Utils {
        // GUIDS
        Guid NewGUID();
        std::string NewGUIDAsString();
        Guid GUIDFromString(std::string guidString);
        std::string GUIDToString(Guid guid);

        // Time
        std::tm Now();
    }
}

#endif