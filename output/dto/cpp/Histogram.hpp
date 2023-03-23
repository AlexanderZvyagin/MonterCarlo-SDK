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


#include "HistogramAxis.hpp"
namespace dto {
class Histogram;
std::string Histogram_to_json_string(const Histogram &obj);
class Histogram {
public:

    HistogramAxis x;
    std::optional<HistogramAxis> y;

    
    Histogram (
        HistogramAxis x = HistogramAxis(),
        std::optional<HistogramAxis> y = {}
    )
    : x (
        x
    )
    , y (
        y
    )
    {
    }

    bool operator == (const Histogram &other) const {
        if (x != other.x) return false;
        if (y != other.y) return false;
        return true;
    }
    bool operator != (const Histogram &other) const {return not(*this==other);}
    std::string json (void) const {
        return Histogram_to_json_string(*this);
    }
};
inline
void to_json(json &j, const Histogram &obj) try {
    j = json::object();
    j["x"] = obj.x;
    if(obj.y.has_value())
        j["y"] = obj.y.value();
} catch (const std::exception &e) {
    std::throw_with_nested(std::runtime_error("void to_json(json &j, const Histogram &obj) exception"));
}

inline
std::string Histogram_to_json_string(const Histogram &obj) {
    json j;
    to_json(j,obj);
    return j.dump();
}
inline
void from_json(const json &j, Histogram &obj) try {
    j.at("x").get_to(obj.x);
    if(auto it=j.find("y"); it!=j.end() and !it->is_null())
        obj.y = *it;
} catch (const std::exception &e) {
    std::throw_with_nested(std::runtime_error("void from_json(const json &j, Histogram &obj) exception"));
}
inline
Histogram Histogram_from_json(const json &j) {
    Histogram obj;
    from_json(j,obj);
    return obj;
}
} // namespace dto

