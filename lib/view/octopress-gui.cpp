#include "view/octopress-gui.h"

octopress_gui::octopress_gui() : QMainWindow(NULL) {
	setWindowTitle("New Blog - octopress_gui");

	myMenu = new QMenuBar(this);
    myMenu->addMenu(setupFileMenu());
    myMenu->addMenu(setupEditMenu());
    myMenu->addMenu(setupViewMenu());
    myMenu->addMenu(setupHelpMenu());
    this->setMenuBar(myMenu);

    setupBlogPosts();
    setupMainWidget();
    setupBlogStyle();
    this->setCentralWidget(myMainWidget);
}

/*
 *
 * SETUP ALL MENUS
 *
 */

QMenu *octopress_gui::setupFileMenu(void) {
    // Install Project Dialog
    myBlogDialog = new QFileDialog(this);
    myBlogDialog->setFileMode(QFileDialog::Directory);
    myBlogDialog->setOption(QFileDialog::ShowDirsOnly);
    
    QMenu *myFileMenu  = new QMenu("File", this);

    QAction *a_openBlog = new QAction("Open Blog", this);
    a_openBlog->setShortcut(Qt::CTRL + Qt::Key_O);
    connect (a_openBlog, SIGNAL(triggered()), myBlogDialog, SLOT(exec()));
    a_openBlog->setEnabled(true);

    myFileMenu->addAction(a_openBlog);
    myFileMenu->addAction("Save Blog", this, SLOT(saveBlog()), Qt::CTRL + Qt::Key_S);
    myFileMenu->addSeparator();
    myFileMenu->addAction("Close", this, SLOT(close()), Qt::CTRL + Qt::Key_Q);
    
    return myFileMenu;
}

QMenu *octopress_gui::setupEditMenu(void) {
    QMenu *myEditMenu  = new QMenu("Edit", this);
    myEditMenu->addAction("Undo", this, SLOT(showFullScreen()), Qt::CTRL + Qt::Key_Z);
    myEditMenu->addAction("Repeat", this, SLOT(showNormal()), Qt::CTRL + Qt::Key_Y);
    return myEditMenu;
}

QMenu *octopress_gui::setupViewMenu(void) {
    QMenu *myViewMenu  = new QMenu("View", this);
    myViewMenu->addAction("Fullscreen", this, SLOT(showFullScreen()), Qt::CTRL + Qt::Key_F);
    myViewMenu->addAction("Windowed", this, SLOT(showNormal()), Qt::CTRL + Qt::Key_N);
    return myViewMenu;
}

QMenu *octopress_gui::setupHelpMenu(void) {
    QMenu *myHelpMenu  = new QMenu("Help", this);
    myHelpMenu->addAction("About...", this, SLOT(messageBox()), Qt::CTRL + Qt::Key_H);
    return myHelpMenu;
}

/**
 *
 * SETUP THE POST-BROWSER
 *
 */

void octopress_gui::setupBlogPosts(void) {
    blogPostsWidget = new QDockWidget(tr("Posts"), this);
    blogPostsWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea, blogPostsWidget);

    postList *posts = new postList(this);
    blogPostsWidget->setWidget(posts);
}

/**
 *
 * SETUP THE BLOG-STYLE-MANAGER
 *
 */

void octopress_gui::setupBlogStyle(void) {
    blogStyleWidget = new QDockWidget(tr("Blog-Style"), this);
    blogStyleWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea, blogStyleWidget);

    blogStyle *style = new blogStyle(this);
    blogStyleWidget->setWidget(style);
}

/**
 *
 * SETUP THE MAIN-WIDGET
 *
 */

void octopress_gui::setupMainWidget(void) {
    myMainWidget = new QTextEdit;
    myMainWidget->setText("Hallo Welt");
}

void octopress_gui::importFile(const QString& name) {
    std::string import = "file " + name.toStdString();
    QString output = QString::fromStdString(exec(import.c_str()));
    myMainWidget->append(output);
}

std::string octopress_gui::exec(const char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
        if(fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result;
}
