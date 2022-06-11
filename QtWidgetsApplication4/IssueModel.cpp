#include "IssueModel.h"
#include <qbrush.h>
#include <qcolor.h>

IssueModel::~IssueModel()
{
}

int IssueModel::rowCount(const QModelIndex& parent) const
{
	return this->repo.size();
}

int IssueModel::columnCount(const QModelIndex& parent) const
{
	return 4;
}

QVariant IssueModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();

	Issue s = repo[row];
	if (role == Qt::DisplayRole) {
		switch (column) {
		case 0:
			return QString::fromStdString(s.getDescription());
		case 1:
			return QString::fromStdString(s.getStatus());
		case 2:
			return QString::fromStdString(s.getReporter());
		case 3:
			return QString::fromStdString(s.getSolver());
		}
	}
	else if (role == Qt::BackgroundRole) {
		if (row & 1)
			return QBrush(QColor(224, 224, 224));
	}
	return QVariant();
}
QVariant IssueModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
		switch (section) {
		case 0:
			return QString("Description");
		case 1:
			return QString("Status");
		case 2:
			return QString("Reporter");
		case 3:
			return QString("Solver");
		default:
			break;
		}
	return QVariant();
}

bool IssueModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	int row = index.row();
	int column = index.column();

	Issue& s = this->repo[row];

	if (role == Qt::EditRole || role == Qt::DisplayRole)
	{
		switch (column)
		{
		case 2:
			s.solve(value.toString().toStdString());
			break;
		default:
			break;
		}
	}

	emit dataChanged(index, index);

	return true;
}
