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
class EvaluationPoint;
std::string EvaluationPoint_to_json_string(const EvaluationPoint &obj);
class EvaluationPoint {
public:

    int state;
    float time;
    std::optional<float> value;
    std::optional<float> error;
    std::vector<Histogram> histograms;

    
    EvaluationPoint (
        int state = -88,
        float time = NAN,
        std::optional<float> value = {},
        std::optional<float> error = {},
        std::vector<Histogram> histograms = {}
    )
    : state (
        state
    )
    , time (
        time
    )
    , value (
        value
    )
    , error (
        error
    )
    , histograms (
        histograms
    )
    {
    }

    int GetState (
    ) const
    {
        
        return state;
        
    }

    int GetTime (
    ) const
    {
        
        return time;
        
    }

    float GetValue (
    ) const
    {
        
        if( not value.has_value() )
            throw std::invalid_argument("value");
        return value.value();
        
    }

    float GetError (
    ) const
    {
        
        if( not error.has_value() )
            throw std::invalid_argument("error");
        return error.value();
        
    }

    EvaluationPoint & Add (
        Histogram histogram
    )
    {
        
        histograms.push_back(histogram);
        return *this;
        
    }

    bool operator == (const EvaluationPoint &other) const {
        if (state != other.state) return false;
        if (time != other.time) return false;
        if (value != other.value) return false;
        if (error != other.error) return false;
        if (histograms != other.histograms) return false;
        return true;
    }
    bool operator != (const EvaluationPoint &other) const {return not(*this==other);}
    std::string json (void) const {
        return EvaluationPoint_to_json_string(*this);
    }
};
inline
void to_json(json &j, const EvaluationPoint &obj) {
    j = json::object();
    j["state"] = obj.state;
    j["time"] = obj.time;
    if(obj.value.has_value())
        j["value"] = obj.value.value();
    if(obj.error.has_value())
        j["error"] = obj.error.value();
    j["histograms"] = obj.histograms;
}

inline
std::string EvaluationPoint_to_json_string(const EvaluationPoint &obj) {
    json j;
    to_json(j,obj);
    return j.dump();
}
inline
void from_json(const json &j, EvaluationPoint &obj) {
    j.at("state").get_to(obj.state);
    j.at("time").get_to(obj.time);
    if(auto it=j.find("value"); it!=j.end() and !it->is_null())
        obj.value = *it;
    if(auto it=j.find("error"); it!=j.end() and !it->is_null())
        obj.error = *it;
    j.at("histograms").get_to(obj.histograms);
}
inline
EvaluationPoint EvaluationPoint_from_json(const json &j) {
    EvaluationPoint obj;
    from_json(j,obj);
    return obj;
}
} // namespace dto

