#include "VIEWS/vehiclelistview.h"

VehicleListView::VehicleListView(Controller* controller, const QString& title, const QStringList& headerStrings, QWidget *parent):
    BaseBackAbstractView(title, headerStrings, parent), _controller(controller) {}

void VehicleListView::update() {
    Array<Veicolo*> vehicles = _controller->getVehicles();
    _table->setRowCount(vehicles.size());
    _table->clearSelection();

    for (int i = 0; i < _table->rowCount(); i++) {
        QLabel *icon = new QLabel;
        icon->setPixmap(QPixmap(":/icons/auto.png"));
        _table->setCellWidget(i, 0, icon);
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(vehicles[i]->targa()));
        _table->setItem(i, 1, item);
        item = new QTableWidgetItem(QString::fromStdString(vehicles[i]->posizione()));
        _table->setItem(i, 2, item);
        item = new QTableWidgetItem(QString::number(vehicles[i]->chilometraggio()));
        _table->setItem(i, 3, item);

        connect(_table, &QTableWidget::itemClicked, this, [=](QTableWidgetItem* item) {
            emit rowClicked(item->row());
        });
    }
}

const QString& VehicleListView::getIconPath(Veicolo* const vehicle) {
    QString basePath = ":/icons/";

    if (typeid(vehicle) == typeid(Automobile))
        std::cout << "Auto";
//        return basePath += "auto.png";
//    else if (typeid(vehicle) == typeid(AutoIbrida))
//        return basePath += "auto_ibrida.png";
//    else if (typeid(vehicle) == typeid(AutomobileElettrica))
//        return basePath += "auto_elettrica.png";
//    else if (typeid(vehicle) == typeid(Moto))
//        return basePath+= "moto.png";
//    else if (typeid(vehicle) == typeid(MotoElettrica))
//        return basePath += "moto_elettrica.png";
//    else if (typeid(vehicle) == typeid(Bicicletta))
//        return basePath += "bici.png";
//    else
//        return basePath += "monopattino.png";
}
