#ifndef J_OBJECT_H
#define J_OBJECT_H

#include <string>
#include <vector>

namespace engine {
	class JObject {

	public:
		JObject(std::string);
		std::vector<JObject> get_array(std::string);
		std::string operator[](std::string property) {
			return get(property);
		}
		~JObject() {}
	private:
		std::string value;
		std::string get(std::string);
		std::string get_jarray(std::string);		
	};
}
#endif
