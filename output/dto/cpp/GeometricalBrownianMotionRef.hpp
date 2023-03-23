#pragma once
// 
// https://gitlab.com/zvyagin.alexander/dto-code-generator
// Generated by CODE GENERATOR OF DATA TRANSFER OBJECTS (cgdto) version 0.4.2
// 
// Generated from schema: MonteCarlo SDK version (0.1.4)
// 


#include <optional>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <cmath>

#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "Updater.hpp"
namespace dto {
class GeometricalBrownianMotionRef;
std::string GeometricalBrownianMotionRef_to_json_string(const GeometricalBrownianMotionRef &obj);
class GeometricalBrownianMotionRef: public Updater {
public:


    
    GeometricalBrownianMotionRef (
        float start = NAN,
        int drift = -88,
        int diffusion = -88,
        std::string title = ""
    )
    : Updater (
        "GeometricalBrownianMotion",
        {drift,diffusion},
        {},
        start,
        title
    )
    {
    }

    bool operator == (const GeometricalBrownianMotionRef &other) const {
        if (Updater::operator != (other)) return false;
        return true;
    }
    bool operator != (const GeometricalBrownianMotionRef &other) const {return not(*this==other);}
    std::string json (void) const {
        return GeometricalBrownianMotionRef_to_json_string(*this);
    }
};
inline
void to_json(json &j, const GeometricalBrownianMotionRef &obj) try {
    j = json::object();
    to_json(j,static_cast<const Updater &>(obj));
} catch (const std::exception &e) {
    std::throw_with_nested(std::runtime_error("void to_json(json &j, const GeometricalBrownianMotionRef &obj) exception"));
}

inline
std::string GeometricalBrownianMotionRef_to_json_string(const GeometricalBrownianMotionRef &obj) {
    json j;
    to_json(j,obj);
    return j.dump();
}
inline
void from_json(const json &j, GeometricalBrownianMotionRef &obj) try {
    from_json(j,static_cast<Updater &>(obj));
} catch (const std::exception &e) {
    std::throw_with_nested(std::runtime_error("void from_json(const json &j, GeometricalBrownianMotionRef &obj) exception"));
}
inline
GeometricalBrownianMotionRef GeometricalBrownianMotionRef_from_json(const json &j) {
    GeometricalBrownianMotionRef obj;
    from_json(j,obj);
    return obj;
}
} // namespace dto

