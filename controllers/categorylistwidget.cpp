#include "ui_categorylistwidget.h"

#include "categorylistwidget.h"
#include "mainwindow.h"
#include "tools.h"
#include "globals.h"

CategoryListWidget::CategoryListWidget(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::CategoryListWidget),
        newGroupModel(nullptr)
{
    ui->setupUi(this);

    ui->listWidget_data->setAttribute(Qt::WA_MacShowFocusRect, 0);
}

CategoryListWidget::~CategoryListWidget()
{
    delete ui;
}

void CategoryListWidget::init(GroupTreeWidget *groupTreeWidget, NoteModel *noteModel, MarkdownEditorWidget *markdownEditorWidget)
{
    mGroupTreeWidget = groupTreeWidget;
    mMarkdownEditorWidget = markdownEditorWidget;
    mNoteModel = noteModel;
    setCategoryList(groupTreeWidget->getGroupModelList(Gitnoter::Category), noteModel->getCategory());
    ui->lineEdit->clear();
    ui->pushButton_addCategory->setHidden(true);
}

void CategoryListWidget::setCategoryList(QList<GroupModel *> groupModelList, const QString &category)
{
    ui->listWidget_data->clear();
    for (int i = 0; i < groupModelList.length(); ++i) {
        if (groupModelList[i]->getName().isEmpty()) {
            continue;
        }
        QListWidgetItem *listWidgetItem = new QListWidgetItem(groupModelList[i]->getName());
        listWidgetItem->setData(Qt::UserRole, QVariant::fromValue(groupModelList[i]));
        ui->listWidget_data->addItem(listWidgetItem);
        if (category == groupModelList[i]->getName()) {
            oldGroupModel = groupModelList[i];
            ui->listWidget_data->setItemSelected(listWidgetItem, true);
        }
    }
}

void CategoryListWidget::filtrateCategoryList()
{
    const QString text = ui->lineEdit->text();
    int showCount = 0;
    for (int i = 0; i < ui->listWidget_data->count(); ++i) {
        QListWidgetItem *listWidgetItem = ui->listWidget_data->item(i);
        if (listWidgetItem->text().indexOf(text, 0, Qt::CaseInsensitive) == -1) {
            listWidgetItem->setHidden(true);
        }
        else {
            listWidgetItem->setHidden(false);
            showCount += 1;
        }
    }

    ui->pushButton_addCategory->setHidden(!(!text.isEmpty() && showCount == 0));
}

void CategoryListWidget::on_listWidget_data_doubleClicked(const QModelIndex &)
{
    on_buttonBox_accepted();
    emit accept();
}

void CategoryListWidget::on_pushButton_addCategory_clicked()
{
    const QString text = ui->lineEdit->text();
    if (!text.isEmpty()) {
        mMarkdownEditorWidget->appendCategory(text);
        setCategoryList(mGroupTreeWidget->getGroupModelList(Gitnoter::Category), oldGroupModel->getName());
        filtrateCategoryList();
        ui->listWidget_data->sortItems(Qt::AscendingOrder);
    }
}

void CategoryListWidget::on_lineEdit_textChanged(const QString &)
{
    filtrateCategoryList();
}

void CategoryListWidget::on_listWidget_data_itemClicked(QListWidgetItem *item)
{
    newGroupModel = item->data(Qt::UserRole).value<GroupModel *>();
}

void CategoryListWidget::on_buttonBox_accepted()
{
    if (oldGroupModel != newGroupModel) {
        oldGroupModel->setCount(oldGroupModel->getCount() - 1);
        newGroupModel->setCount(newGroupModel->getCount() + 1);

        mMarkdownEditorWidget->changeCategory(newGroupModel->getName());
    }
}
