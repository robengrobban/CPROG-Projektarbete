#include "JObject.h"

namespace engine {

    JObject::JObject(std::string val) : value(val) {}

    /// <summary>
    /// Returns vector containing contents of json-array with property name first matching "property" param.
    /// </summary>
    /// <param name="property">Name of the array to return.</param>
    /// <returns>Vector of JObjects contained in array.</returns>
    std::vector<JObject> JObject::get_array(std::string property)
    {
        std::vector<JObject> objects = std::vector<JObject>();
        std::string raw_arr(get_jarray(property));

        size_t first = 0;
        size_t second = 0;
        int left_amount = 0;
        int right_amount = 0;

        for (size_t i = 0; i < raw_arr.size(); i++) {
            if (raw_arr[i] == '{') {
                if (left_amount == 0)
                    first = i;
                left_amount++;
            }
            else if (raw_arr[i] == '}') {
                right_amount++;
            }
            if (left_amount > 0 && left_amount == right_amount) {
                second = i;
                objects.push_back(JObject(raw_arr.substr(first, second - first + 1)));
                left_amount = 0;
                right_amount = 0;
            }
        }
        return objects;
    }

    /// <summary>
    /// Returns sring containing contents of json-array with property name first matching "property" param.
    /// </summary>
    /// <param name="name">Name of the array.</param>
    /// <returns>Array represented as a plain string.</returns>
    std::string JObject::get_jarray(std::string name) {

        size_t first = value.find(name) + name.size() + 2;
        size_t second = 0;
        int left_amount = 0;
        int right_amount = 0;

        for (size_t i = first; i < value.size(); i++) {
            if (value[i] == '[')
                left_amount++;
            else if (value[i] == ']')
                right_amount++;

            if (left_amount > 0 && left_amount == right_amount) {
                second = i;
                break;
            }
        }

        return value.substr(first, second - first);
    }

    /// <summary>
    /// Returns
    /// </summary>
    /// <param name="property"></param>
    /// <returns></returns>
    std::string JObject::get(std::string property) {
        size_t first = value.find(property) + property.size() + 2;
        if (value[first] == '\"')
            first++;
        size_t last = 0;

        for (size_t i = first + 1; i < value.size(); i++) {
            if (value[i] == '\"' || value[i] == ',' || value[i] == '}') {
                last = i;
                break;
            }
        }
        return value.substr(first, last - first);
    }
}
