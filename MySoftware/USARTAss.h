/*
 * @Description:
 * @Version: v1.0.0
 * @Author: isidore-chen
 * @Date: 2025-05-04 20:59:47
 * @Copyright: Copyright (c) 2025 CAUC
 */
#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_USARTAss.h"
#include "Chart.h" // Include Chart header
#include "ThreadProcess.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QtWidgets/QDialog>
#include <QtCore/QtGlobal>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtCharts/QChartView> // 添加此行以包含 QChartView 的定义
#include <vector>
#include <memory>

QT_BEGIN_NAMESPACE
namespace UI
{
	class USARTAss;
}
QT_END_NAMESPACE

/**
 * @brief USARTAss类是应用程序的主窗口类。
 *
 * 它继承自QMainWindow，并管理UI交互、串口通信逻辑和图表显示。
 * 此类处理用户输入，如打开/关闭串口、刷新串口列表、发送数据等，
 * 并通过SerialInfo类与物理串口交互，通过Chart类显示数据。
 */
	class USARTAss : public QMainWindow
{
	Q_OBJECT

public:
	/**
	 * @brief USARTAss类的构造函数。
	 * @param parent 父QWidget对象，默认为nullptr。
	 */
	USARTAss(QWidget* parent = nullptr);
	/**
	 * @brief USARTAss类的析构函数。
	 */
	~USARTAss();

signals:
	void DataProcessStart();

private slots:
	/**
	 * @brief 处理打开/关闭串口按钮点击事件的槽函数。
	 */
	void OpenCloseUSART_clicked();
	/**
	 * @brief 处理刷新串口列表按钮点击事件的槽函数。
	 */
	void RefreshUSART_clicked();
	/**
	 * @brief 处理清空发送区按钮点击事件的槽函数。
	 */
	void ClearSendSpace_clicked();
	/**
	 * @brief 处理发送消息按钮点击事件的槽函数。
	 */
	void SendMessage_clicked();
	/**
	 * @brief 处理串口接收到数据时的readyRead信号的槽函数。
	 */
	void RecvMessage_clicked();
	/**
	 * @brief 更新UI上显示鼠标悬停坐标的标签的槽函数。
	 * @param chartIndex 发生悬停事件的图表的索引。
	 * @param point 悬停点的QPointF坐标。
	 */
	void updateHoveredCoordinates(int chartIndex, QPointF point);

	/**
	 * @brief 处理打开帧检查复选框点击事件的槽函数。
	 */
	void OpenfraemCheck_on_click();
	/**
	 * @brief 处理关闭帧检查复选框点击事件的槽函数。
	 */
	void ClosefraemCheck_on_click();
	/**
	 * @brief 处理设置图表帧按钮点击事件的槽函数。
	 */
	void on_SetChartFrame_clicked();

	void ProcessedOver();

private:
	/**
	 * @brief 连接所有UI控件的信号到相应的槽函数。
	 */
	void TotalConnect();

	/**
	 * @brief 从UI读取用户设置的串口配置信息。
	 */
	void ReadUsrSerialInfo();
	/**
	 * @brief 根据串口打开状态更改打开/关闭按钮的文本。
	 * @param serialOpened 布尔值，指示串口是否已打开。
	 */
	void ChangeSerialButtonText(bool serialOpened);
	/**
	 * @brief 在UI上显示已接收的总字节数。
	 */
	void ShowRecvBytesCount();

	/**
	 * @brief 初始化并显示应用程序中的图表。
	 */
	void ShowChart();

	/**
	 * @brief 从UI中获取并设置图表起始帧。
	 */
	void GetChartStartFrame();

private:
	Ui::USARTAss ui; /**< 指向通过Qt Designer生成的UI类的实例。 */

	bool RecvCheck;
	bool serialOpened;		   /**< 布尔标志，指示串口是否已打开。 */
	QString serialSendMessage; /**< 存储待发送的串口消息。 */
	QByteArray buffer;		   /**< 用于存储从串口接收到的原始数据的缓冲区。 */
	qint64 totalBytes;		   /**< 记录从串口接收到的总字节数。 */

	ThreadProcess* threadProcess;
};
