#include "mappingdialog.h"
#include "ui_mappingdialog.h"

#define DEFAULT_CELL_SIZE 32

mappingdialog::mappingdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mappingdialog)
{
    ui->setupUi(this);
    ui->sliderCell->setValue(DEFAULT_CELL_SIZE);
}

mappingdialog::~mappingdialog()
{
    delete ui;
}

void mappingdialog::on_buttonAccept_clicked()
{
    if((m_width/m_cellSize == 0) || (m_height/m_cellSize == 0))
        this->reject();
    else
        this->accept();
}

void mappingdialog::on_buttonReject_clicked()
{
    this->reject();
}

void mappingdialog::setImageHeight(int value)
{
    m_height = value;
    ui->editHeightImage->setText(QString::number(value));
    ui->editHeightMap->setText(QString::number(m_height/m_cellSize));
}

void mappingdialog::setImageWidth(int value)
{
    m_width = value;
    ui->editWidthImage->setText(QString::number(value));
    ui->editWidthMap->setText(QString::number(m_width/m_cellSize));
}

void mappingdialog::on_sliderCell_valueChanged(int value)
{
    m_cellSize = value;
    ui->editCell->setText(QString::number(value));
    ui->editWidthMap->setText(QString::number(m_width/m_cellSize));
    ui->editHeightMap->setText(QString::number(m_height/m_cellSize));
}

quint16 mappingdialog::getMapWidth()
{
    return m_width/m_cellSize;
}

quint16 mappingdialog::getMapHeight()
{
    return m_height/m_cellSize;

}

quint16 mappingdialog::getCellSize()
{
    return m_cellSize;
}
