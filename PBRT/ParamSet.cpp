#include "ParamSet.h"
namespace pbrt {

#define ADD_PARAM_TYPE(T, vec) (vec).emplace_back(new ParamSetItem<T>(name, std::move(values), nValues));

	ParamSet::ParamSet()
	{
	}


	ParamSet::~ParamSet()
	{
	}

	void ParamSet::AddFloat(const std::string &name,
		std::unique_ptr<Float[]> values, int nValues) {
		//EraseFloat(name);
		floats.emplace_back(
			new ParamSetItem<Float>(name, std::move(values), nValues));
	}
}