#include <QHBoxLayout>

#include "view/blogStyle.h"

blogStyle::blogStyle(QMainWindow *parent) {
	thisParent = parent;

	// Setup all Labels
	int fixedWidth = 100;
	blogTitleLabel = new QLabel("Title:", this);
	blogTitleLabel->setFixedWidth(fixedWidth);
	blogSubtitleLabel = new QLabel("Subtitle:", this);
	blogSubtitleLabel->setFixedWidth(fixedWidth);

	// set-up all input-areas
	blogTitle = new QPlainTextEdit(this);
    blogTitle->setPlainText("The title of the blog");
	setHeight(blogTitle, 2);
	blogSubtitle = new QPlainTextEdit(this);
    blogSubtitle->setPlainText("The subtitle of the blog");
	setHeight(blogSubtitle, 2);

	// middle-layouts
	QHBoxLayout *title = new QHBoxLayout();
	title->addWidget(blogTitleLabel);
	title->addWidget(blogTitle);
	QHBoxLayout *subtitle = new QHBoxLayout();
	subtitle->addWidget(blogSubtitleLabel);
	subtitle->addWidget(blogSubtitle);

    // layout for document-browser
    blogLayout = new QVBoxLayout();
    blogLayout->addLayout(title);
    blogLayout->addLayout(subtitle);


    this->setLayout(blogLayout);
}

/*
 *
 * WIDGET-SETTINGS
 *
 */

void blogStyle::setHeight(QPlainTextEdit* edit, int nRows) {
	QFontMetrics m(edit->font());
	int rowHeight = m.lineSpacing();
	edit -> setFixedHeight(nRows * rowHeight);
}