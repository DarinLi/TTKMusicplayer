#ifndef MUSICVOLUMEGAINWIDGET_H
#define MUSICVOLUMEGAINWIDGET_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "musicabstractmovewidget.h"
#include "musicabstracttablewidget.h"

/*! @brief The class of the volume gain table widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_WIDGET_EXPORT MusicVolumeGainTableWidget : public MusicAbstractTableWidget
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit MusicVolumeGainTableWidget(QWidget *parent = 0);

    virtual ~MusicVolumeGainTableWidget();

    /*!
     * Get class object name.
     */
    static QString getClassName();

public Q_SLOTS:
    /*!
     * Table widget list cell click.
     */
    virtual void listCellClicked(int row, int column) override;

};


namespace Ui {
class MusicVolumeGainWidget;
}
class QProcess;
/*! @brief The class of the volume gain widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_TOOLSET_EXPORT MusicVolumeGainWidget : public MusicAbstractMoveWidget
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit MusicVolumeGainWidget(QWidget *parent = 0);

    virtual ~MusicVolumeGainWidget();

    /*!
     * Get class object name.
     */
    static QString getClassName();

Q_SIGNALS:
    /*!
     * Reset window open flag.
     */
    void resetFlag(MusicObject::ToolsType flag);

public Q_SLOTS:
    /*!
     * Override show function.
     */
    void show();

private Q_SLOTS:
    /*!
     * Add input file button clicked.
     */
    void addFileButtonClicked();
    /*!
     * Add input files button clicked.
     */
    void addFilesButtonClicked();
    /*!
     * Remove input file button clicked.
     */
    void rmFileButtonClicked();
    /*!
     * Remove input files button clicked.
     */
    void rmFilesButtonClicked();
    /*!
     * Analysis input files button clicked.
     */
    void analysisButtonClicked();
    /*!
     * Apply input files button clicked.
     */
    void applyButtonClicked();
    /*!
     * Music gain volume input value changed.
     */
    void volumeLineTextChanged(const QString &text);
    /*!
     * Analysis output by process.
     */
    void analysisOutput();
    /*!
     * Apply output by process.
     */
    void applyOutput();

protected:
    /*!
     * Override the widget event.
     */
    virtual void closeEvent(QCloseEvent *event) override;
    /*!
     * Create table item finished.
     */
    void createItemFinished(const QString &track, const QString &album);
    /*!
     * Enable or disable control state.
     */
    void setControlEnable(bool enable);

    Ui::MusicVolumeGainWidget *m_ui;
    QProcess *m_process;
    QStringList m_paths;
    int m_currentIndex;

};

#endif // MUSICVOLUMEGAINWIDGET_H