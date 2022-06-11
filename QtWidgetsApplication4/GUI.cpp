#include "GUI.h"
#include <qmessagebox.h>
#include <sstream>
#include <qdebug.h>

GUI::GUI(User u, Service& srv, QWidget *parent)
    : user{ u }, service{ srv }, QMainWindow(parent)
{
    ui.setupUi(this);
    this->update();
    connectSignalsAndSlots();
    this->service.addObserver(this);
    this->setWindowTitle(QString::fromStdString(u.getName() + " " + u.getType()));
    if (user.getType() == "programmer") {
        this->ui.label->hide();
        this->ui.lineEdit->hide();
        this->ui.pushButton->setText("Solve");
    }

}

void GUI::update()
{
    this->ui.listWidget->clear();
    for (auto it : this->service.get()) {
        std::string itm = "Description: " + it.getDescription() + ", status: " + it.getStatus() + ", reporter: " + it.getReporter() + ", solver: " + it.getSolver() + ".";
        this->ui.listWidget->addItem(QString::fromStdString(itm));
    }
}

void GUI::addSolve()
{
    if (this->user.getType() == "tester") {
        std::string desc = this->ui.lineEdit->text().toStdString();
        try {
            this->service.add(this->user.getName(), desc);
        }
        catch (std::exception& e) {
            QMessageBox box;
            box.setText(e.what());
        }
    }
    else {
        for (auto it : this->ui.listWidget->selectedItems()) {
            std::string line = it->text().toStdString();
            std::stringstream ss{ line };
            std::string token;

            std::getline(ss, token, ':');
            std::getline(ss, token, ' ');

            std::stringstream ss2{ token };
            std::getline(ss, token, ',');

            try {
                this->service.solve(token, this->user.getName());
            }
            catch (std::exception& e) {
                QMessageBox box;
                box.setText(e.what());
                box.exec();
            }
        }
    }
}

void GUI::remove()
{
    for (auto it : this->ui.listWidget->selectedItems()) {
        std::string line = it->text().toStdString();
        std::stringstream ss{ line };
        std::string token;

        std::getline(ss, token, ':');
        std::getline(ss, token, ' ');

        std::stringstream ss2{ token };
        std::getline(ss, token, ',');

        try {
            this->service.remove(token);
        }
        catch (std::exception& e) {
            QMessageBox box;
            box.setText(e.what());
            box.exec();
        }
    }
}

void GUI::connectSignalsAndSlots()
{
    QObject::connect(this->ui.pushButton, &QAbstractButton::clicked, this, &GUI::addSolve);
    QObject::connect(this->ui.pushButton_2, &QAbstractButton::clicked, this, &GUI::remove);
}
