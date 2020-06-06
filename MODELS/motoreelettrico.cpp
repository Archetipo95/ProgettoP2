#include "MODELS/motoreelettrico.h"

MotoreElettrico::MotoreElettrico(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro,
                                 u_int potenza, u_int numeroMotori, bool inCarica, double capacitaBatteria, double capacitaAttuale, VelocitaRicarica caricaSupportata, Colonnina colonninaAttuale):
    Veicolo(targa, posizione, km, numeroPosti, ingombro),
    _potenza(potenza), _numeroMotori(numeroMotori) , _inCarica(inCarica), _capacitaBatteria(capacitaBatteria), _capacitaAttuale(capacitaAttuale), _caricaSupportata(caricaSupportata), _colonninaAttuale(colonninaAttuale) {}

MotoreElettrico::~MotoreElettrico() {}

double MotoreElettrico::consumoKm() const {
    return ingombro() * _potenza * _numeroMotori;
}

double MotoreElettrico::autonomia() const {
    return capacitaAttuale() * consumoKm();
}

short int MotoreElettrico::fattoreGreen() const {
    short int somma = 0;
    if(ingombro() == 1)
        somma = somma + 3;                          // meno ingombro positivo
    else if(ingombro() == 2 || ingombro() == 3)
        somma = somma + 2;
    else    somma = somma + 1;
    if(capacitaPosti() > 1)
        somma = somma + 2;                          // piu' posti positivo
    if(guasti() <= 5)
        somma = somma + 2;                          // meno guasti positivo
    else if(guasti() < 10)
        somma = somma + 1;

    return somma;
}

short MotoreElettrico::tempoRimanenteCaricaCompleta() const {
    if (_inCarica) {
        int _capacitaColonnina = 0;
        if (_caricaSupportata == lenta)
            _capacitaColonnina = 16;
        else if (_caricaSupportata == media)
            _capacitaColonnina = 63;
        else
            _capacitaColonnina = 200;
        return _capacitaBatteria / _capacitaColonnina;
    } else
        throw NotInChargeException();
}

unsigned short MotoreElettrico::percentualeCarica() const {
    return (_capacitaAttuale * 100) / _capacitaBatteria;
}

bool MotoreElettrico::inCarica() const {
    return _inCarica;
}

double MotoreElettrico::capacitaBatteria() const
{
    return _capacitaBatteria;
}

double MotoreElettrico::capacitaAttuale() const
{
    return _capacitaAttuale;
}

MotoreElettrico::VelocitaRicarica MotoreElettrico::caricaSupportata() const
{
    return _caricaSupportata;
}

MotoreElettrico::Colonnina MotoreElettrico::colonninaAttuale() const
{
    return _colonninaAttuale;
}

void MotoreElettrico::setInCarica(bool inCarica, Colonnina colonnina) {
    _inCarica = inCarica;
    _colonninaAttuale = colonnina;
}

void MotoreElettrico::setCapacitaAttuale(double capacitaAttuale)
{
    _capacitaAttuale = capacitaAttuale;
}
