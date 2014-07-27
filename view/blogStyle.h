#ifndef BLOG_STYLE_H
#define BLOG_STYLE_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QPlainTextEdit>

class blogStyle : public QWidget {
	Q_OBJECT
private:
	void			setHeight(QPlainTextEdit* edit, int nRows);
protected:
	QMainWindow		*thisParent;
	QVBoxLayout		*blogLayout;
    QLabel			*blogTitleLabel;
    QLabel			*blogSubtitleLabel;
    QPlainTextEdit	*blogTitle;
    QPlainTextEdit	*blogSubtitle;
public:
	blogStyle(QMainWindow *parent = 0);
};

#endif // BLOG_STYLE_H