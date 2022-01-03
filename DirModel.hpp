#ifndef DIRMODEL_HPP
#define DIRMODEL_HPP

extern "C"
{
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#ifndef _WIN32
#include <spawn.h>
#endif
}
#include <QApplication>
#include <QFileSystemModel>
#include <QClipboard>
#include <QMimeData>
#include <QUrl>
#include <QFile>
#include <QFileInfo>

class DirModel : public QFileSystemModel
{
    Q_OBJECT


private slots:
    void rename(const QString &path, const QString &old, const QString &nxt);

public:
    DirModel(QObject *parent = nullptr);
    virtual void open(QModelIndex &);
    virtual QModelIndex mkfile(const QModelIndex &parent, const QString &name);
    virtual void setClip(QModelIndexList &);
    virtual QList<QString> paste(QModelIndex &dst);
    virtual QList<QString> moveToTrash(QModelIndexList &);
};

#endif // DIRMODEL_HPP
