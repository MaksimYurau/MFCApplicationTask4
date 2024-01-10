
// Lab4ListsTDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CLab4ListsTDlg
class CLab4ListsTDlg : public CDialogEx
{
// Создание
public:
	CLab4ListsTDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB4LISTST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	int nIndex;
public:
//	afx_msg void OnBnClickedAllHigh();
	afx_msg void OnClickedAllBottom();
	afx_msg void OnClickedAllHigh();
	afx_msg void OnClickedDelete();
	afx_msg void OnClickedExtract();
	afx_msg void OnClickedMoveBottom();
	afx_msg void OnClickedMoveHigh();
	afx_msg void OnClickedPushBack();
	afx_msg void OnBnClickedGenerateData();
	afx_msg void OnBnClickedGenerateData2();
};
