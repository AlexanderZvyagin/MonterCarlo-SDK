#pragma once
// 
// https://gitlab.com/zvyagin.alexander/dto-code-generator
// Generated by CODE GENERATOR OF DATA TRANSFER OBJECTS (cgdto) version 0.4.1
// 
//         Generated from: MonteCarlo SDK version (0.1.4)
//         


#include <optional>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <cmath>

#include <nlohmann/json.hpp>
using json = nlohmann::json;


namespace dto {
class Parameter;
std::string Parameter_to_json_string(const Parameter &obj);
class Parameter {
public:

    float value;
    float step;
    float min;
    float max;

    
    Parameter (
        float value = NAN,
        float step = NAN,
        float min = NAN,
        float max = NAN
    )
    : value (
        value
    )
    , step (
        step
    )
    , min (
        min
    )
    , max (
        max
    )
    {
    }

    bool operator == (const Parameter &other) const {
        if (value != other.value) return false;
        if (step != other.step) return false;
        if (min != other.min) return false;
        if (max != other.max) return false;
        return true;
    }
    bool operator != (const Parameter &other) const {return not(*this==other);}
    std::string json (void) const {
        return Parameter_to_json_string(*this);
    }
};
inline
void to_json(json &j, const Parameter &obj) {
    j = json::object();
    j["value"] = obj.value;
    j["step"] = obj.step;
    j["min"] = obj.min;
    j["max"] = obj.max;
}

inline
std::string Parameter_to_json_string(const Parameter &obj) {
    json j;
    to_json(j,obj);
    return j.dump();
}
inline
void from_json(const json &j, Parameter &obj) {
    j.at("value").get_to(obj.value);
    j.at("step").get_to(obj.step);
    j.at("min").get_to(obj.min);
    j.at("max").get_to(obj.max);
}
inline
Parameter Parameter_from_json(const json &j) {
    Parameter obj;
    from_json(j,obj);
    return obj;
}
} // namespace dto

