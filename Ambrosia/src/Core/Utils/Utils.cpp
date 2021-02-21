#include "Core/Utils/Utils.hpp"

namespace Ambrosia::Core::Utils {
    boost::uuids::uuid NewGUID() {
        boost::uuids::random_generator gen;
        return gen();
    }

    std::tm Now() {
        std::time_t t = std::time(0);
        return *std::localtime(&t);
    }
}