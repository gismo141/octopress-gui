#ifndef POST_LIST_H
#define POST_LIST_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QTreeWidget>

class postList : public QWidget {
	Q_OBJECT
private:
protected:
	QMainWindow	*thisParent;
	QVBoxLayout	*postLayout;
    QLabel		*postListLabel;
    QTreeWidget	*postTree;
public:
	postList(QMainWindow *parent = 0);
};

#endif // POST_LIST_H