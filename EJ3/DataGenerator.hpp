#pragma once
#include <vector>
#include <string>
#include <type_traits>

using namespace std;

template <typename T>
class GenerarData{
	private:
	vector<double> doubles;
	vector<string> strings;
	vector<int> intTemporales;
	vector<vector<int>> intListas;

	public:
	void AddValue(const T& valor){
		if constexpr (is_same_v<T,double>){
			doubles.push_back(valor);
		}
		else if constexpr (is_same_v<T,string>){
			strings.push_back(valor);
		}
		else if constexpr (is_same_v<T,int>){
			intTemporales.push_back(valor);	
			if (intTemporales.size() == 2){
				intListas.push_back(intTemporales);
				intTemporales.clear();
			}
		}	
	}

	    auto getData() const {
        if constexpr (is_same_v<T, double>) {
            return doubles;
        } else if constexpr (is_same_v<T, string>) {
            return strings;
        } else if constexpr (is_same_v<T, int>) {
            return intListas;
        }
    }
};