#pragma once

#include <QAbstractTableModel>
#include "Repository.h"

class IssueModel : public QAbstractTableModel
{
public:
	IssueModel(Repository& r) : repo{ r } {}
	~IssueModel();

	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	//Qt::ItemFlags flags(const QModelIndex& index) const;
	bool setData(const QModelIndex& index, const QVariant& value, int role);

private:
	Repository& repo;
};
