#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <ostream>
#include <string>

using namespace std;

class Measurement
{
    public:
        Measurement(string name, double value) : name(name), value(value){};
        virtual ~Measurement(){};

        friend ostream& operator <<(ostream &out, const Measurement m){
            out << "[" << m.name << ": " << m.value << "]";
            return out;
        };

    protected:

    private:
        string name;
        double value;
};

#endif // MEASUREMENT_H
