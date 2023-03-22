#pragma once
// 
// https://gitlab.com/zvyagin.alexander/dto-code-generator
// Generated by CODE GENERATOR OF DATA TRANSFER OBJECTS (cgdto) version 0.4.1
// 
//         Generated from: MonteCarlo SDK version (0.1.2)
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
void to_json(json &j, const Histogram &obj) {
    j = json::object();
    j["x"] = obj.x;
    if(obj.y.has_value())
        j["y"] = obj.y.value();
}

inline
std::string Histogram_to_json_string(const Histogram &obj) {
    json j;
    to_json(j,obj);
    return j.dump();
}
inline
void from_json(const json &j, Histogram &obj) {
    j.at("x").get_to(obj.x);
    if(auto it=j.find("y"); it!=j.end() and !it->is_null())
        obj.y = *it;
}
inline
Histogram Histogram_from_json(const json &j) {
    Histogram obj;
    from_json(j,obj);
    return obj;
}
} // namespace dto

