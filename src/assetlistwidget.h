#ifndef ASSETLISTWIDGET_H
#define ASSETLISTWIDGET_H

#include <QListWidget>
#include <QVector>
#include <QString>
#include "projectmodel.h"

class AssetListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit AssetListWidget(QWidget *parent = 0);
    bool eventFilter(QObject *object, QEvent *event);
    AssetRef assetRef(int id) const;
    const QString& assetName(int id) const;
    int assetType(int id) const;

signals:
    void assetDoubleClicked(const QString& name, int type);
    
public slots:
    void updateList();

protected:
    QVector<AssetRef> mAssetRefs;
    QVector<QString> mAssetNames;
    QVector<int> mAssetTypes;
};

#endif // ASSETLISTWIDGET_H
