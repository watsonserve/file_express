#ifndef CLIPBOARD_HPP
#define CLIPBOARD_HPP

#include <QApplication>

class ClipBoard : public QObject
{
    Q_OBJECT
    QClipboard *clip;
public:
    explicit ClipBoard(QObject *parent = nullptr);
    virtual ~ClipBoard();
    void set(QList<QUrl> urls);
    void set(QList<QImage> imgs);
    QList<QUrl> getUrls();
    void pasteTo();

signals:

};

#endif // CLIPBOARD_HPP
