#ifndef J_OBJECT_H
#define J_OBJECT_H

#include <string>
#include <vector>

namespace engine {
	const class JObject {

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

		JObject(const JObject&) = delete;
		const JObject& operator=(const JObject&) = delete;
	};
}
#endif
