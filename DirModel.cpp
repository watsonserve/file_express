#include "DirModel.hpp"
#include <iostream>

DirModel::DirModel(QObject *parnet) : QFileSystemModel(parnet)
{
    setReadOnly(false);

    // rename
    connect(this, SIGNAL(fileRenamed(const QString &, const QString &, const QString &)), this, SLOT(rename(const QString &, const QString &, const QString &)));
}

void DirModel::rename(const QString &path, const QString &old, const QString &nxt)
{
    std::cout << "rename log: " << path.toStdString() << " " << old.toStdString() << " -> " << nxt.toStdString() << std::endl;
}

void DirModel::open(QModelIndex &idx)
{
    QFileInfo info = fileInfo(idx);
    if (info.isDir())
    {
        return;
    }
    std::string str = info.absoluteFilePath().toStdString();

    size_t len = str.length();
    char *const file = (char *)malloc(len + 1);
    memcpy(file, str.c_str(), len);
    file[len] = 0;
    pid_t pid = 0;


#ifndef _WIN32
    char cmd[] = "open";
    char *argv[3] = { cmd, file, NULL };
    posix_spawnp(&pid, "open", NULL, NULL, argv, NULL);
#endif
    if (!pid)
    {
        printf("open faild: %s\n", file);
    }

    free(file);
}

QModelIndex DirModel::mkfile(const QModelIndex &dstDir, const QString &name)
{
    QModelIndex ret;
    std::string filename = (filePath(dstDir) + '/' + name).toStdString();
    std::cout << filename << std::endl;
    int fd = ::open(filename.c_str(), O_WRONLY | O_CREAT | O_EXCL, 0666);
    if (-1 != fd)
    {
        close(fd);
    }
    else
    {
        perror("create file faild");
    }
    return ret;
}

QList<QString> DirModel::moveToTrash(QModelIndexList &idxList)
{
    QList<QString> faildList;
    if (!idxList.length()) return faildList;

    for (int i = 0; i < idxList.length(); i++)
    {
        QString filename = filePath(idxList[i]);
        if (!QFile::moveToTrash(filename))
            faildList.push_back(filename);
    }
    return faildList;
}

QList<QString> DirModel::paste(QModelIndex &dst)
{
    QString dstDir = filePath(dst) + "/";
    QList<QUrl> list = QApplication::clipboard()->mimeData()->urls();
    QList<QString> faildList;

    for (int i = 0; i < list.size(); i++)
    {
        QUrl &url = list[i];
        if (!QFile::copy(url.path(), dstDir + url.fileName()))
            faildList.push_back(url.path());
    }
    return faildList;
}

void DirModel::setClip(QModelIndexList &idxList)
{
    if (!idxList.length()) return;

    QClipboard *clipboard = QApplication::clipboard();
    QMimeData *mime = new QMimeData();
    QList<QUrl> urls;
    QString txt;


    for (int i = 0; i < idxList.length(); i++)
    {
        QFileInfo info = fileInfo(idxList[i]);
        txt += '\x0d' + info.fileName();
        urls.push_back("file://" + info.filePath());
    }

    mime->setText(txt.sliced(1));
    mime->setUrls(urls);
    clipboard->setMimeData(mime);
}
