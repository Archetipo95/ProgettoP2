#ifndef MODEL_H
#define MODEL_H

#include "MODELS/array.h"
#include "MODELS/citta.h"

class Model {
public:
    Model();
    ~Model();

    Array<Citta*> getCities() const;
    Citta* getCity(const std::string &city) const;
    Citta* getCity(unsigned int index) const;
    void addCity(Citta* const city);

    void addVehicle(const std::string& city, Veicolo* const vehicle);
    Veicolo* getVehicle(const std::string& city, unsigned int vehicle) const;
    Veicolo* getVehicle(const std::string& city, const std::string& vehicle) const;
    Veicolo* removeVehicle(const std::string& city, const std::string& vehicle);
    void moveVehicle(const std::string& from, const std::string& to, const std::string& vehicle);

private:
    Array<Citta*> _cities;

    Array<Citta*>::iterator searchCity(const std::string& city) const;
    Array<Veicolo*>::iterator searchVehicle(const std::string& city, const std::string& vehicle) const;
};

#endif // MODEL_H
