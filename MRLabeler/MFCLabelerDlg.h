
// MFCLabelerDlg.h : 头文件
//

#pragma once

#include "opencv2/opencv.hpp"
#include "../VOCUtil/DataSetConfig.h"
#include "../VOCUtil/AnnotationFile.h"
#include "vector"
#include "afxwin.h"
#include "ColorRectTracker.h"
class CRelativeRect
{
public:
	CString strName;
	cv::Point2f ptStart;
	cv::Point2f ptEnd;
};
// CMFCLabelerDlg 对话框
class CMFCLabelerDlg : public CDialogEx
{
// 构造
public:
	CMFCLabelerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCLABELER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	void ResizeBottomButton(int nID);
	void ResizeBottomStatic(int nID);
	void ShowImageOfIndex();
	void UpdateView();
	void UpdateTrackers();
	void LoadAnnotationFile(const string xmlannopath);
	bool SaveAnnotationFile(const string xmlannopath);
	void ConvertRel2Tracker();
	DatasetConfig voc;
	CRect dlg_rect;
	CRect m_Picrect;
	bool m_bDragMode = false;
	vector<CRelativeRect>m_relrects;
	vector<CColorRectTracker>m_trackers;
	cv::Mat m_img;
	cv::Mat m_showimg;
	CComboBox m_comboxclassnames;
	CString m_currentselectedclassname;
	std::string m_imgdir;
	std::vector<std::string>m_files;
	int m_imgindex;

	double m_zoomratio = 1.0f;
	cv::Point2f m_ptRoomCenter;
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonPrev();
	afx_msg void OnBnClickedButtonNext();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonAddrectangle();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnCbnSelchangeComboClassnames();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};
