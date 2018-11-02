#pragma once

#include <stdio.h>
#include <map>
#include <memory>
#include <vector>

#include "pbrt.h"

namespace pbrt {

	class ParamSet
	{
	public:
		ParamSet();
		~ParamSet();
		void AddFloat(const std::string &, std::unique_ptr<Float[]> v, int nValues = 1);
		/*void AddInt(const std::string &, std::unique_ptr<int[]> v, int nValues);
		void AddBool(const std::string &, std::unique_ptr<bool[]> v, int nValues);
		void AddPoint2f(const std::string &, std::unique_ptr<Point2f[]> v, int nValues);
		void AddVector2f(const std::string &, std::unique_ptr<Vector2f[]> v, int nValues);
		void AddPoint3f(const std::string &, std::unique_ptr<Point3f[]> v, int nValues);
		void AddVector3f(const std::string &, std::unique_ptr<Vector3f[]> v, int nValues);
		void AddNormal3f(const std::string &, std::unique_ptr<Normal3f[]> v, int nValues);
		void AddString(const std::string &, std::unique_ptr<std::string[]> v, int nValues);
		void AddTexture(const std::string &, const std::string &);

		bool EraseInt(const std::string &);
		bool EraseBool(const std::string &);
		bool EraseFloat(const std::string &);
		bool ErasePoint2f(const std::string &);
		bool EraseVector2f(const std::string &);
		bool ErasePoint3f(const std::string &);
		bool EraseVector3f(const std::string &);
		bool EraseNormal3f(const std::string &);
		bool EraseSpectrum(const std::string &);
		bool EraseString(const std::string &);
		bool EraseTexture(const std::string &);*/

	private:
		std::vector<std::shared_ptr<ParamSetItem<bool>>> bools;
		std::vector<std::shared_ptr<ParamSetItem<int>>> ints;
		std::vector<std::shared_ptr<ParamSetItem<Float>>> floats;
		/*std::vector<std::shared_ptr<ParamSetItem<Point2f>>> point2fs;
		std::vector<std::shared_ptr<ParamSetItem<Vector2f>>> vector2fs;
		std::vector<std::shared_ptr<ParamSetItem<Point3f>>> point3fs;
		std::vector<std::shared_ptr<ParamSetItem<Vector3f>>> vector3fs;
		std::vector<std::shared_ptr<ParamSetItem<Normal3f>>> normals;
		std::vector<std::shared_ptr<ParamSetItem<Spectrum>>> spectra;*/
		std::vector<std::shared_ptr<ParamSetItem<std::string>>> strings;
		std::vector<std::shared_ptr<ParamSetItem<std::string>>> textures;
	};

	template <typename T>
	struct ParamSetItem
	{
		ParamSetItem(const std::string &name, std::unique_ptr<T[]> val, int nValues = 1);

		const std::string &name;
		const std::unique_ptr<T[]> values;
		const int nValues = 1
			mutable bool lookedUp = false;
	};

	template <typename T>
	ParamSetItem<T>::ParamSetItem(const std::string &name, std::unique_ptr<T[]> v, int nValues)
		: name(name), values(std::move(v)), nValues(nValues) {}

}