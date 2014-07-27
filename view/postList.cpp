#include "postList.h"

postList::postList(QMainWindow *parent) {
	thisParent = parent;

	// create document-browser
    postTree = new QTreeWidget(thisParent);
    postTree->setColumnCount(2);
    QStringList postheaders;
    postheaders << tr("Posts") << tr("published");
    postTree->setHeaderLabels(postheaders);
    // layout for document-browser
    postLayout = new QVBoxLayout();
    postLayout->addWidget(postTree);

    this->setLayout(postLayout);
}