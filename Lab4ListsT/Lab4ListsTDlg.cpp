
// Lab4ListsTDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "Lab4ListsT.h"
#include "Lab4ListsTDlg.h"
#include "afxdialogex.h"
#include <cstdlib>
#include <ctime>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CLab4ListsTDlg



CLab4ListsTDlg::CLab4ListsTDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB4LISTST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab4ListsTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLab4ListsTDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_ALL_HIGH, &CLab4ListsTDlg::OnBnClickedAllHigh)
	ON_BN_CLICKED(IDC_ALL_BOTTOM, &CLab4ListsTDlg::OnClickedAllBottom)
	ON_BN_CLICKED(IDC_ALL_HIGH, &CLab4ListsTDlg::OnClickedAllHigh)
	ON_BN_CLICKED(IDC_DELETE, &CLab4ListsTDlg::OnClickedDelete)
	ON_BN_CLICKED(IDC_EXTRACT, &CLab4ListsTDlg::OnClickedExtract)
	ON_BN_CLICKED(IDC_MOVE_BOTTOM, &CLab4ListsTDlg::OnClickedMoveBottom)
	ON_BN_CLICKED(IDC_MOVE_HIGH, &CLab4ListsTDlg::OnClickedMoveHigh)
	ON_BN_CLICKED(IDC_PUSH_BACK, &CLab4ListsTDlg::OnClickedPushBack)
	ON_BN_CLICKED(IDC_GENERATE_DATA, &CLab4ListsTDlg::OnBnClickedGenerateData)
	ON_BN_CLICKED(IDC_GENERATE_DATA2, &CLab4ListsTDlg::OnBnClickedGenerateData2)
END_MESSAGE_MAP()


// Обработчики сообщений CLab4ListsTDlg

BOOL CLab4ListsTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	//
	CDialog::OnInitDialog();

	// Получаем указатель на объект списка (LISTBOX)
	CListBox* pListBoxHigh = (CListBox*)GetDlgItem(IDC_LIST_HIGH);

	// Инициализируем генератор случайных чисел
	srand((unsigned)time(0));

	// Добавляем 10 случайных чисел в список
	for (int i = 0; i < 10; i++)
	{
		int randomNumber = rand() % 100; // Генерируем случайное число от 0 до 99
		CString number;
		number.Format(_T("%d"), randomNumber);
		pListBoxHigh->AddString(number);
	}

	//////////////////////////////////////////////////////////////////////////////////
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CLab4ListsTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CLab4ListsTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CLab4ListsTDlg::OnBnClickedAllHigh()
//{
//	// TODO: добавьте свой код обработчика уведомлений
//}


void CLab4ListsTDlg::OnClickedAllBottom()
{
	CListBox* pListBoxHigh = (CListBox*)GetDlgItem(IDC_LIST_HIGH);
	CListBox* pListBoxBottom = (CListBox*)GetDlgItem(IDC_LIST_BOTTOM);

	// Переносим все элементы из IDC_LIST_HIGH в IDC_LIST_BOTTOM
	int count = pListBoxHigh->GetCount();
	for (int i = 0; i < count; i++)
	{
		// Получаем текст элемента
		CString text;
		pListBoxHigh->GetText(i, text);

		// Добавляем текст в IDC_LIST_BOTTOM
		pListBoxBottom->AddString(text);
	}

	// Очищаем IDC_LIST_HIGH
	pListBoxHigh->ResetContent();
}


void CLab4ListsTDlg::OnClickedAllHigh()
{
	CListBox* pListBoxHigh = (CListBox*)GetDlgItem(IDC_LIST_BOTTOM);
	CListBox* pListBoxBottom = (CListBox*)GetDlgItem(IDC_LIST_HIGH);

	// Переносим все элементы из IDC_LIST_HIGH в IDC_LIST_BOTTOM
	int count = pListBoxHigh->GetCount();
	for (int i = 0; i < count; i++)
	{
		// Получаем текст элемента
		CString text;
		pListBoxHigh->GetText(i, text);

		// Добавляем текст в IDC_LIST_BOTTOM
		pListBoxBottom->AddString(text);
	}

	// Очищаем IDC_LIST_HIGH
	pListBoxHigh->ResetContent();
}


void CLab4ListsTDlg::OnClickedDelete()
{
		// Получаем указатель на объект списка (LISTBOX)
		CListBox* pListBoxHigh = (CListBox*)GetDlgItem(IDC_LIST_HIGH);

		// Получаем количество выбранных элементов в IDC_LIST_HIGH
		int count = pListBoxHigh->GetSelCount();
		if (count == 0)
		{
			// Нет выбранных элементов, выходим
			return;
		}

		// Создаем массив для хранения индексов выбранных элементов
		CArray<int, int> selectedIndices;
		selectedIndices.SetSize(count);

		// Получаем индексы выбранных элементов в IDC_LIST_HIGH
		pListBoxHigh->GetSelItems(count, selectedIndices.GetData());

		// Удаляем выбранные элементы из IDC_LIST_HIGH
		for (int i = count - 1; i >= 0; i--)
		{
			pListBoxHigh->DeleteString(selectedIndices[i]);
		}

}


void CLab4ListsTDlg::OnClickedExtract()
{
	// Получаем указатели на объекты списков (LISTBOX) и редактор (EDIT)
	CListBox* pListBoxHigh = (CListBox*)GetDlgItem(IDC_LIST_HIGH);
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_MAIN_EDIT);

	// Получаем индекс выбранного элемента в IDC_LIST_HIGH
	nIndex = pListBoxHigh->GetCurSel();
	if (nIndex == LB_ERR)
	{
		// Нет выбранного элемента, выходим
		return;
	}

	// Получаем текст выбранного элемента
	CString selectedItem;
	pListBoxHigh->GetText(nIndex, selectedItem);

	// Помещаем текст выбранного элемента в редактор IDC_MAIN_EDIT
	pEdit->SetWindowText(selectedItem);

	// Удаляем выбранный элемент из IDC_LIST_HIGH
	pListBoxHigh->DeleteString(nIndex);
}

void CLab4ListsTDlg::OnClickedPushBack()
{
	// Получаем указатели на объекты списков (LISTBOX) и редактор (EDIT)
	CListBox* pListBoxHigh = (CListBox*)GetDlgItem(IDC_LIST_HIGH);
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_MAIN_EDIT);

	// Получаем текст из редактора IDC_MAIN_EDIT
	CString updatedItem;
	pEdit->GetWindowText(updatedItem);

	// Получаем индекс выбранного элемента в IDC_LIST_HIGH
	nIndex = pListBoxHigh->GetCurSel();
	if (nIndex == LB_ERR)
	{
		// Нет выбранного элемента, выходим
		return;
	}

	// Вставляем обновленный элемент обратно в IDC_LIST_HIGH по тому же индексу
	pListBoxHigh->InsertString(nIndex, updatedItem);
}

void CLab4ListsTDlg::OnClickedMoveBottom()
{

	CListBox* pListBoxHigh = (CListBox*)GetDlgItem(IDC_LIST_HIGH);
	CListBox* pListBoxBottom = (CListBox*)GetDlgItem(IDC_LIST_BOTTOM);

	// Получаем количество выбранных элементов в IDC_LIST_HIGH
	int count = pListBoxHigh->GetSelCount();
	if (count == 0)
	{
		// Нет выбранных элементов, выходим
		return;
	}

	// Создаем массив для хранения индексов выбранных элементов
	CArray<int, int> selectedIndices;
	selectedIndices.SetSize(count);

	// Получаем индексы выбранных элементов в IDC_LIST_HIGH
	pListBoxHigh->GetSelItems(count, selectedIndices.GetData());

	// Перемещаем выбранные элементы в IDC_LIST_BOTTOM
	for (int i = count - 1; i >= 0; i--)
	{
		CString itemText;
		pListBoxHigh->GetText(selectedIndices[i], itemText);
		pListBoxBottom->AddString(itemText);
	}
}


void CLab4ListsTDlg::OnClickedMoveHigh()
{

	CListBox* pListBoxHigh = (CListBox*)GetDlgItem(IDC_LIST_BOTTOM);
	CListBox* pListBoxBottom = (CListBox*)GetDlgItem(IDC_LIST_HIGH);

	// Получаем количество выбранных элементов в IDC_LIST_HIGH
	int count = pListBoxHigh->GetSelCount();
	if (count == 0)
	{
		// Нет выбранных элементов, выходим
		return;
	}

	// Создаем массив для хранения индексов выбранных элементов
	CArray<int, int> selectedIndices;
	selectedIndices.SetSize(count);

	// Получаем индексы выбранных элементов в IDC_LIST_HIGH
	pListBoxHigh->GetSelItems(count, selectedIndices.GetData());

	// Перемещаем выбранные элементы в IDC_LIST_BOTTOM
	for (int i = count - 1; i >= 0; i--)
	{
		CString itemText;
		pListBoxHigh->GetText(selectedIndices[i], itemText);
		pListBoxBottom->AddString(itemText);
	}
}




void CLab4ListsTDlg::OnBnClickedGenerateData()
{
		
		CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST_HIGH);
		pListBox->ResetContent();

		const int numItems = 10; 

		for (int i = 0; i < numItems; ++i)
		{
			int randomNum = rand(); 
			CString strItem;
			strItem.Format(_T("%d"), randomNum);
			pListBox->AddString(strItem); 
		}
	
}


void CLab4ListsTDlg::OnBnClickedGenerateData2()
{
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST_BOTTOM);
	pListBox->ResetContent();

	const int numItems = 100;

	for (int i = 0; i < numItems; ++i)
	{
		int randomNum = rand();
		CString strItem;
		strItem.Format(_T("%d"), randomNum);
		pListBox->AddString(strItem);
	}
}
