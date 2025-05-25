#include <string>
#include <vector>
#include <sstream>

using namespace std;

class JsonBuilder {
private:
    ostringstream jsonStream;  
    bool firstKey = true;           

public:
    void addData(const string& key, const vector<double>& values) {
        if (!firstKey) jsonStream << ",\n";
        jsonStream << "    \"" << key << "\": [";
        for (size_t i = 0; i < values.size(); ++i) {
            if (i != 0) jsonStream << ", ";
            jsonStream << values[i]; 
        }
        jsonStream << "]";
        firstKey = false;
    }

    void addData(const string& key, const vector<string>& values) {
        if (!firstKey) jsonStream << ",\n";
        jsonStream << "    \"" << key << "\": [";
        for (size_t i = 0; i < values.size(); ++i) {
            if (i != 0) jsonStream << ", ";
            jsonStream << "\"" << values[i] << "\"";
        }
        jsonStream << "]";
        firstKey = false;
    }

    void addData(const string& key, const vector<vector<int>>& values) {
        if (!firstKey) jsonStream << ",\n";
        jsonStream << "    \"" << key << "\": [\n";
        for (size_t i = 0; i < values.size(); ++i) {
            if (i != 0) jsonStream << ",\n";
            jsonStream << "        [";
            for (size_t j = 0; j < values[i].size(); ++j) {
                if (j != 0) jsonStream << ", ";
                jsonStream << values[i][j]; 
            }
            jsonStream << "]";
        }
        jsonStream << "\n    ]";
        firstKey = false;
    }

    string build() const {
        return "{\n" + jsonStream.str() + "\n}";
    }
};