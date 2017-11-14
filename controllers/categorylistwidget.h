#ifndef CATEGORYLISTWIDGET_H
#define CATEGORYLISTWIDGET_H

#include "notemodel.h"
#include "groupmodel.h"
#include "grouptreewidget.h"
#include "notelistwidget.h"
#include "markdowneditorwidget.h"

#include <QDialog>
#include <QPropertyAnimation>
#include <QDesktopWidget>
#include <QListWidgetItem>

class MarkdownEditorWidget;

namespace Ui
{
    class CategoryListWidget;
}

class CategoryListWidget : public QDialog
{
Q_OBJECT

public:
    explicit CategoryListWidget(QWidget *parent = 0);

    ~CategoryListWidget();

    void init(GroupTreeWidget *groupTreeWidget, NoteModel *noteModel, MarkdownEditorWidget *markdownEditorWidget);

private slots:

    void on_pushButton_addCategory_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_listWidget_data_doubleClicked(const QModelIndex &index);

    void on_buttonBox_accepted();

    void on_listWidget_data_itemClicked(QListWidgetItem *item);

private:

    void setCategoryList(QList<GroupModel *> categoryModelList, const QString &category);

    void filtrateCategoryList();

private:
    Ui::CategoryListWidget *ui;
    GroupTreeWidget *mGroupTreeWidget;
    MarkdownEditorWidget *mMarkdownEditorWidget;
    NoteModel *mNoteModel;
    GroupModel *oldGroupModel;
    GroupModel *newGroupModel;

};

#endif // CATEGORYLISTWIDGET_H
