#include "Core/Utils/Utils.hpp"

namespace Ambrosia::Core::Utils {
    Guid NewGUID() {
        boost::uuids::random_generator gen;
        return gen();
    }

    Guid GUIDFromString(std::string guidString) {
        boost::uuids::string_generator gen;
        return gen(guidString);
    }

    std::string GUIDToString(Guid guid) {
        return boost::lexical_cast<std::string>(guid);
    }

    std::string NewGUIDAsString() {
        return boost::lexical_cast<std::string>(NewGUID());
    }

    std::tm Now() {
        std::time_t t = std::time(0);
        return *std::localtime(&t);
    }
}