#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};

class FunctionParts {
    public:
    FunctionParts(const char& new_operation, const double& new_value) {
        operation = new_operation;
        value = new_value;
    }

    double Apply(const double& initial_value) const { // const here? IDK
        if (operation == '+') {
            return initial_value + value;
        } else {
            return initial_value - value;
        }
    }

    void Invert() {
        if (operation == '+') {
            operation = '-';
        } else {
            operation = '+';
        }
    }

    private:
    char operation;
    double value;
};


class Function {
    public:
    void AddPart(const char& operation, double value) {
        parts.push_back(FunctionParts(operation, value));
    }
    
    double Apply(double value) const { // const here?
        for (const FunctionParts& part : parts) {
            value = part.Apply(value);
        }
        return value;
    }

    void Invert() {
        for (FunctionParts& part : parts) {
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }

    private:
    vector<FunctionParts> parts;

};

Function MakeWeightFunction(const Params& params, const Image& image) {
    Function function;
    function.AddPart('-', image.freshness * params.a + params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
};

double ComputeImageWeight(const Params& params, const Image& image) {
    Function function = MakeWeightFunction(params, image);
    return function.Apply(image.quality);
};

double ComputeQualityByWeight(const Params& params, const Image& image, double weight) {
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    return function.Apply(weight);
};

int main() {
    
    return 0;
}