#pragma once

#ifndef OCTOPRESS_GUI_H
#define OCTOPRESS_GUI_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QFileDialog>
#include <QDockWidget>
#include <QMessageBox>
#include <QTextEdit>

#include "blogStyle.h"
#include "postList.h"


class octopress_gui : public QMainWindow {
	Q_OBJECT
private:
	QMenu                   *setupFileMenu(void);
    QMenu                   *setupEditMenu(void);
    QMenu                   *setupViewMenu(void);
    QMenu                   *setupHelpMenu(void);
    std::string             exec(const char* cmd);
protected:
	QMenuBar                *myMenu;
    QFileDialog             *myBlogDialog;
    QTextEdit               *myMainWidget;
    QDockWidget             *blogPostsWidget;
    QDockWidget             *blogStyleWidget;
public:
	/**
	 * @brief std. ctor
	 */
	octopress_gui(void);
public slots:
	/**
     * @brief This function shows a messagebox.
     * @details At the moment there is only a `about`-box implemented.
     */
    void messageBox(void) {
        QMessageBox::about(this, "octopress-GUI", "octopress-GUI is a graphical interface for the command-line-tool Octopress\n\n\t(C) by Michael Riedel, 2014");
    }
    void setupMainWidget(void);
    void setupBlogPosts(void);
    void setupBlogStyle(void);
    void importFile(const QString& name);
};

#endif // OCTOPRESS_GUI_H