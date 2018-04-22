#ifndef USERMANAGE_H
#define USERMANAGE_H

#include <QWidget>

class UserManage : public QWidget
{
    Q_OBJECT
public:
    explicit UserManage(QWidget * _parent = nullptr);
    ~UserManage();

public:
    void loadConfig(const QString & _path);

private:
    struct UserManagePrivate;
    UserManagePrivate * data;
};

#endif // USERMANAGE_H
