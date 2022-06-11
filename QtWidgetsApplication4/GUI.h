#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"
#include "User.h"
#include "service.h"
#include "Observer.h"

class GUI : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    GUI(User u, Service& s, QWidget *parent = Q_NULLPTR);
    void update() override;
    void addSolve();
    void remove();

private:
    Ui::GUIClass ui;
    User user;
    Service& service;
    void connectSignalsAndSlots();
};
