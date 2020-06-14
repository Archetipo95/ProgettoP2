#ifndef CITIESLISTCONTROLLER_H
#define CITIESLISTCONTROLLER_H

#include "model.h"
#include "VIEWS/view.h"
#include "VIEWS/citieslistview.h"
#include <QObject>

class CitiesListView;
class View;

class Controller: public QObject {
    Q_OBJECT

public:
    explicit Controller(Model* model, QObject* parent = nullptr);

    void setView(View* view);

    Array<Citta*> getCities() const;
    Array<Veicolo*> getVehicles() const;
    Veicolo* getVehicle() const;

    QString getCurrentCity() const;
    QString getCurrentVehicle() const;

private:
    View *_view;
    Model* _model;

private slots:
    void goToVehiclesView(int row, int column) const ;
    void goToVehicleDetailView(int row, int column) const;
    void goBack() const;
    void toggleMaintenance(int state) const;
    void createMoveModal() const;
    void removeVehicle() const;
    void saveChage(int row) const;
};

#endif // CITIESLISTCONTROLLER_H
