
// WSCADDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "WSCAD.h"
#include "WSCADDlg.h"
#include "afxdialogex.h"
#include "math.h"
#include "C:\Program Files\ASCON\KOMPAS-3D v21 Study\SDK\Include\ksConstants.h"
#include "C:\Program Files\ASCON\KOMPAS-3D v21 Study\SDK\Include\ksConstants3D.h"
//#include "C:\Program Files\ASCON\KOMPAS-3D v21 Study\SDK\Include\kapi5.h"
#include <atlsafe.h>
//#include <C:\Program Files\ASCON\KOMPAS-3D v21 Study\SDK\Include\Ks_TLB.h>

#include <comutil.h>



#define PI 4*atan(1)
#define SINCOS_PI_4 0.70710678118

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma once


#import "C:\Program Files\ASCON\KOMPAS-3D v21 Study\SDK\lib\kAPI5.tlb"



using namespace Kompas6API5;
//using namespace KompasAPI5;


KompasObjectPtr pKompasApp5;
//KompasObjectPtr pKompasApp5;

ksPartPtr pPart;// = PartDoc->GetTopPart();
ksDocument3DPtr pDoc;



//IModelContainerPtr pModelContainer;// (pPart);





//using namespace InventorNative;
//
//CComPtr<Application> pInvApp; //приложение
//
//PartDocumentPtr pPartDoc;  //документ
//PartComponentDefinition *pPartComDef;//компоненты детали
//TransientGeometry *pTransGeom; //геометрия детали
//Transaction *pTrans; //операции
//
//TransactionManagerPtr pTransManager; //менеджер операций
//
//
//PlanarSketches *sketches; // эскизы
//PartFeatures *ft; //элементы детали 
//
//WorkPlanes *wp; //рабочие плоскости
//WorkAxes *wax;//рабочие оси
//WorkPoints *wpt;//рабочие точки


// диалоговое окно CWSCADDlg



CWSCADDlg::CWSCADDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_WSCAD_DIALOG, pParent)
	//, m_Dverh(110)
	//, m_Dcentrotv(75)
	//, m_Dcentr(19)
	//, m_Dotv(15)
	//, m_Dosn(50)
	//, m_GlubinaPaza(3)
	//, m_ShirinaPaza(5)
	//, m_Lpaza(20)
	//, m_OtstupPaza(8)
	//, m_DVireza(25)
	//, m_GlubinaVireza(5)
	//, m_nZ(40)
	//, m_UgolNaklona(2)
	//, m_Lobsh(60)
	//, m_Losn(40)
	//, m_NOtv(10)
	, m_D(100)
	, m_L(200)
	, m_l(40)
	, m_d1(12)
	, m_c(2.5)
	, m_d(70)
	, m_b(20)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWSCADDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT1, m_Dverh);
	//DDV_MinMaxDouble(pDX, m_Dverh, 0, 10000);
	//DDX_Text(pDX, IDC_EDIT2, m_Dcentrotv);
	//DDV_MinMaxDouble(pDX, m_Dcentrotv, 0, 10000);
	//DDX_Text(pDX, IDC_EDIT3, m_Dcentr);
	//DDV_MinMaxDouble(pDX, m_Dcentr, 0, 10000);
	//DDX_Text(pDX, IDC_EDIT4, m_Dotv);
	//DDV_MinMaxDouble(pDX, m_Dotv, 0, 10000);
	//DDX_Text(pDX, IDC_EDIT6, m_Dosn);
	//DDV_MinMaxDouble(pDX, m_Dosn, 0, 10000);
	//DDX_Text(pDX, IDC_EDIT7, m_GlubinaPaza);
	//DDV_MinMaxDouble(pDX, m_GlubinaPaza, 0, 10000);
	//DDX_Text(pDX, IDC_EDIT8, m_ShirinaPaza);
	//DDV_MinMaxDouble(pDX, m_ShirinaPaza, 0, 10000);
	//DDX_Text(pDX, IDC_EDIT9, m_Lpaza);
	//DDV_MinMaxDouble(pDX, m_Lpaza, 0, 10000);
	//DDX_Text(pDX, IDC_EDIT10, m_OtstupPaza);
	//DDV_MinMaxDouble(pDX, m_OtstupPaza, 0, 10000);
	//DDX_Text(pDX, IDC_EDIT5, m_DVireza);
	//DDV_MinMaxDouble(pDX, m_DVireza, 0, 10000);
	//DDX_Text(pDX, IDC_EDIT11, m_GlubinaVireza);
	//DDV_MinMaxDouble(pDX, m_GlubinaVireza, 0, 10000);
	//DDX_Text(pDX, IDC_EDIT12, m_nZ);
	//DDV_MinMaxInt(pDX, m_nZ, 0, 10000);
	//DDX_Text(pDX, IDC_EDIT13, m_UgolNaklona);
	//DDV_MinMaxDouble(pDX, m_UgolNaklona, 0, 90);
	//DDX_Text(pDX, IDC_EDIT14, m_Lobsh);
	//DDV_MinMaxDouble(pDX, m_Lobsh, 0, 10000);
	//DDX_Text(pDX, IDC_EDIT15, m_Losn);
	//DDV_MinMaxDouble(pDX, m_Losn, 0, 10000);
	//DDX_Text(pDX, IDC_EDIT16, m_NOtv);
	//DDV_MinMaxInt(pDX, m_NOtv, 1, 20);

	DDX_Text(pDX, IDC_EDIT_D, m_D);
	DDV_MinMaxDouble(pDX, m_D, 38, 10000);
	DDX_Text(pDX, IDC_EDIT_L, m_L);
	DDV_MinMaxDouble(pDX, m_L, 45, 10000);
	DDX_Text(pDX, IDC_EDIT_d1, m_d1);
	DDV_MinMaxDouble(pDX, m_d1, 0, 16);
	DDX_Text(pDX, IDC_EDIT_L_SMALL, m_l);
	DDV_MinMaxDouble(pDX, m_l, m_d1, m_L - m_d1);
	DDX_Text(pDX, IDC_EDIT_C_SMALL, m_c);
	DDV_MinMaxDouble(pDX, m_c, 0.1, 5);
	DDX_Text(pDX, IDC_EDIT_D_SMALL, m_d);
	DDV_MinMaxDouble(pDX, m_d, 16, m_D - m_c);
	DDX_Text(pDX, IDC_EDIT_B_SMALL, m_b);
	DDV_MinMaxDouble(pDX, m_b, 0.01, 50);
}

BEGIN_MESSAGE_MAP(CWSCADDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CWSCADDlg::OnBnClickedButton1)
	//ON_BN_CLICKED(IDC_BUTTON2, &CWSCADDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &CWSCADDlg::OnBnClickedOk)
	//ON_EN_CHANGE(IDC_EDIT_C_SMALL, &CWSCADDlg::OnEnChangeEditCSmall)
END_MESSAGE_MAP()


// обработчики сообщений CWSCADDlg

BOOL CWSCADDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CWSCADDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CWSCADDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

bool CWSCADDlg::CheckData()
{
	if (!UpdateData())
		return false;

	 /*m_Dverh /=10;
	 m_Dcentrotv /= 10;
	 m_Dcentr /= 10;
	 m_Dotv /= 10;
	 m_Dosn /= 10;
	 m_GlubinaPaza /= 10;
	 m_ShirinaPaza /= 10;
	 m_Lpaza /= 10;
	 m_OtstupPaza /= 10;
	 m_DVireza /= 10;
	 m_GlubinaVireza /= 10;
	 m_Lobsh /= 10;
	 m_Losn /= 10;*/

	 return true;
}
//IKompasDocument3DPtr PartDoc;
void CWSCADDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	BeginWaitCursor();

	if (!CheckData())
		return;

	CComPtr<IUnknown> pKompasAppUnk = nullptr;
	if (!pKompasApp5)
	{
		// Получаем CLSID для Компас
		CLSID InvAppClsid;
		HRESULT hRes = CLSIDFromProgID(L"Kompas.Application.5", &InvAppClsid);
		if (FAILED(hRes)) {
			pKompasApp5 = nullptr;
			return;
		}

		// Проверяем есть ли запущенный экземпляр Компас
		//если есть получаем IUnknown
		hRes = ::GetActiveObject(InvAppClsid, NULL, &pKompasAppUnk);
		if (FAILED(hRes)) {
			// Приходится запускать Компас самим так как работающего нет
			// Также получаем IUnknown для только что запущенного приложения Компас
			TRACE(L"Could not get hold of an active Inventor, will start a new session\n");
			hRes = CoCreateInstance(InvAppClsid, NULL, CLSCTX_LOCAL_SERVER, __uuidof(IUnknown), (void**)&pKompasAppUnk);
			if (FAILED(hRes)) {
				pKompasApp5 = nullptr;
				return;
			}
		}

		// Получаем интерфейс приложения Компас
		hRes = pKompasAppUnk->QueryInterface(__uuidof(KompasObject), (void**)&pKompasApp5);
		if (FAILED(hRes)) {
			return;
		}
	}

	// делаем Компас видимым
	pKompasApp5->Visible = true;

	pDoc = pKompasApp5->Document3D();

	pDoc->Create(false, true);

	pPart = pDoc->GetPart(pTop_Part);

	ksEntityPtr pSketch = pPart->NewEntity(o3d_sketch);

	ksSketchDefinitionPtr pSketchDef = pSketch->GetDefinition();

	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOY));

	pSketch->Create();

	ksDocument2DPtr p2DDoc = pSketchDef->BeginEdit();

	//double point[8][2];
	//point[0][0] = 0;
	//point[0][1] = m_Dcentr / 2.f;
	//point[1][0] = 0;
	//point[1][1] = m_Dverh / 2.f - m_HZuba;
	//point[2][0] = m_Lobsh - m_Losn;
	//point[2][1] = m_Dverh / 2.f - m_HZuba;
	//point[3][0] = m_Lobsh - m_Losn;
	//point[3][1] = m_Dverh / 2.f - (m_Dverh - m_Dosn) / 2.f;
	//point[4][0] = m_Lobsh;
	//point[4][1] =  m_Dverh / 2.f - (m_Dverh - m_Dosn) / 2.f;
	//point[5][0] = m_Lobsh;
	//point[5][1] = (m_Dosn - m_Dcentr) / 2.f;
	//point[6][0] = m_Lobsh - m_GlubinaVireza;
	//point[6][1] = (m_Dosn - m_Dcentr) / 2.f;
	//point[7][0] = m_Lobsh - m_GlubinaVireza;
	//point[7][1] = m_Dcentr / 2.f;

	//p2DDoc->ksLineSeg(point[0][0], point[0][1], point[1][0], point[1][1], 1);
	//p2DDoc->ksLineSeg(point[1][0], point[1][1], point[2][0], point[2][1], 1);
	//p2DDoc->ksLineSeg(point[2][0], point[2][1], point[3][0], point[3][1], 1);
	//p2DDoc->ksLineSeg(point[3][0], point[3][1], point[4][0], point[4][1], 1);
	//p2DDoc->ksLineSeg(point[4][0], point[4][1], point[5][0], point[5][1], 1);
	//p2DDoc->ksLineSeg(point[5][0], point[5][1], point[6][0], point[6][1], 1);
	//p2DDoc->ksLineSeg(point[6][0], point[6][1], point[7][0], point[7][1], 1);
	//p2DDoc->ksLineSeg(point[7][0], point[7][1], point[0][0], point[0][1], 1);
	
	//double D = 100;
	//double L = 200;
	//double l = 45;
	//double d1 = 8;
	//double c = 2.5;
	//double d = 60;
	//double b = 20;
	double D = m_D;
	double L = m_L;
	double l = m_l;
	double d1 = m_d1;
	double c = m_c;
	double d = m_d;
	double b = m_b;
	double point[8][2];
	point[0][0] = 0;
	point[0][1] = D / 2 - c;
	point[1][0] = c;
	point[1][1] = D / 2;
	point[2][0] = L - c;
	point[2][1] = D / 2;
	point[3][0] = L;
	point[3][1] = D / 2 - c;
	point[4][0] = L;
	point[4][1] = d / 2 + c;
	point[5][0] = L - c;
	point[5][1] = d / 2;
	point[6][0] = c;
	point[6][1] = d / 2;
	point[7][0] = 0;
	point[7][1] = d / 2 + c;
	p2DDoc->ksLineSeg(point[0][0], point[0][1], point[1][0], point[1][1], 1);
	p2DDoc->ksLineSeg(point[1][0], point[1][1], point[2][0], point[2][1], 1);
	p2DDoc->ksLineSeg(point[2][0], point[2][1], point[3][0], point[3][1], 1);
	p2DDoc->ksLineSeg(point[3][0], point[3][1], point[4][0], point[4][1], 1);
	p2DDoc->ksLineSeg(point[4][0], point[4][1], point[5][0], point[5][1], 1);
	p2DDoc->ksLineSeg(point[5][0], point[5][1], point[6][0], point[6][1], 1);
	p2DDoc->ksLineSeg(point[6][0], point[6][1], point[7][0], point[7][1], 1);
	p2DDoc->ksLineSeg(point[7][0], point[7][1], point[0][0], point[0][1], 1);

	p2DDoc->ksLineSeg(-10, 0, 10, 0, 3);


	pSketchDef->EndEdit();

	ksEntityPtr pRotate = pPart->NewEntity(o3d_bossRotated);

	ksBossRotatedDefinitionPtr pRotDef = pRotate->GetDefinition();
	pRotDef->SetSketch(pSketch);
	pRotDef->SetSideParam(TRUE, 360);


	pRotate->Create();

	ksEntityPtr pSketch1 = pPart->NewEntity(o3d_sketch);

	pSketchDef = pSketch1->GetDefinition();

	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeYOZ));

	pSketch1->Create();

	p2DDoc = pSketchDef->BeginEdit();

	// p2DDoc->ksCircle(0, m_Dcentrotv / 2.f, m_Dotv / 2.f,1);

	//p2DDoc->ksCircle(0, 0, d / 2 + c, 1);

	//double point1[8][2];
	point[0][1] = -b / 2;
	point[0][0] = 0;
	point[1][1] = -b / 2;
	point[1][0] = -(d / 2 + c);
	point[2][1] = b / 2;
	point[2][0] = -(d / 2 + c);
	point[3][1] = b / 2;
	point[3][0] = 0;
	p2DDoc->ksLineSeg(point[0][0], point[0][1], point[1][0], point[1][1], 1);
	p2DDoc->ksLineSeg(point[1][0], point[1][1], point[2][0], point[2][1], 1);
	p2DDoc->ksLineSeg(point[2][0], point[2][1], point[3][0], point[3][1], 1);
	p2DDoc->ksLineSeg(point[3][0], point[3][1], point[0][0], point[0][1], 1);

	pSketchDef->EndEdit();



	ksEntityPtr pExtrude = pPart->NewEntity(o3d_cutExtrusion);

	ksCutExtrusionDefinitionPtr pExDef = pExtrude->GetDefinition();
	pExDef->directionType = dtNormal;


	pExDef->SetSketch(pSketch1);
	pExDef->SetSideParam(true, etThroughAll, 0, 0, false);


	pExtrude->Create();


	ksEntityPtr pSketch2 = pPart->NewEntity(o3d_sketch);

	pSketchDef = pSketch2->GetDefinition();

	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeYOZ));

	pSketch2->Create();

	p2DDoc = pSketchDef->BeginEdit();

	//double point[8][2];
	point[0][1] = -b / 2;
	point[0][0] = -b / 2;
	point[1][1] = (d / 2 + c - b / 2);
	point[1][0] = -(d / 2 + c + b / 2);
	point[2][1] = (d / 2 + c + b / 2);
	point[2][0] = -(d / 2 + c - b / 2);
	point[3][1] = b / 2;
	point[3][0] = b / 2;
	for (int i = 0; i != 4; ++i)
	{
		point[i][0] *= SINCOS_PI_4;
		point[i][1] *= SINCOS_PI_4;
	}
	p2DDoc->ksLineSeg(point[0][0], point[0][1], point[1][0], point[1][1], 1);
	p2DDoc->ksLineSeg(point[1][0], point[1][1], point[2][0], point[2][1], 1);
	p2DDoc->ksLineSeg(point[2][0], point[2][1], point[3][0], point[3][1], 1);
	p2DDoc->ksLineSeg(point[3][0], point[3][1], point[0][0], point[0][1], 1);

	pSketchDef->EndEdit();



	ksEntityPtr pExtrude1 = pPart->NewEntity(o3d_cutExtrusion);

	ksCutExtrusionDefinitionPtr pExDef1 = pExtrude1->GetDefinition();
	pExDef1->directionType = dtNormal;


	pExDef1->SetSketch(pSketch2);
	pExDef1->SetSideParam(true, etThroughAll, 0, 0, false);


	pExtrude1->Create();


	ksEntityPtr pSketch3 = pPart->NewEntity(o3d_sketch);

	pSketchDef = pSketch3->GetDefinition();

	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOY));

	pSketch3->Create();

	p2DDoc = pSketchDef->BeginEdit();
	p2DDoc->ksCircle(L - l, 0, d1, 1);
	pSketchDef->EndEdit();

	ksEntityPtr pExtrude2 = pPart->NewEntity(o3d_cutExtrusion);

	ksCutExtrusionDefinitionPtr pExDef2 = pExtrude2->GetDefinition();
	pExDef2->directionType = dtReverse;


	pExDef2->SetSketch(pSketch3);
	pExDef2->SetSideParam(false, etThroughAll, 0, 0, false);


	pExtrude2->Create();
	// ksEntityPtr pFillet = pPart->NewEntity(o3d_fillet);
	// ksFilletDefinitionPtr pFilletDef = pFillet->GetDefinition();
	//ksEntityCollectionPtr fl = pFilletDef->array();
	ksEntityCollectionPtr fledges = pPart->EntityCollection(o3d_edge);
	for (int i = 0; i < fledges->GetCount(); i++)
	{
		ksEntityPtr ed = fledges->GetByIndex(i);
		ksEdgeDefinitionPtr def = ed->GetDefinition();

		if (def->GetOwnerEntity() == pRotate)
		{
			if (def->IsCircle())
			{
				ksVertexDefinitionPtr p1 = def->GetVertex(true);
				ksVertexDefinitionPtr p2 = def->GetVertex(false);
				double x1, y1, z1;

				p1->GetPoint(&x1, &y1, &z1);
				if (x1 == 0 && y1 == (D / 2.0 - c) && z1 == 0)
				{
					ksFaceDefinitionPtr f =
						def->GetAdjacentFace(false);
					ksEntityPtr face = f->GetEntity();
					face->Putname("Face4Assembly0");
					face->Update();
				}

			}
		}
	}
	ksEntityCollectionPtr flFaces = pPart->EntityCollection(o3d_face);
	for (int i = 0; i < flFaces->GetCount(); i++)
	{
		ksEntityPtr face = flFaces->GetByIndex(i);
		ksFaceDefinitionPtr def = face->GetDefinition();
		if (def->GetOwnerEntity() == pRotate)
		{
			if (def->IsCylinder()) {
				double h, r;
				def->GetCylinderParam(&h, &r);
				if (r == D / 2.0)
				{
					face->Putname("Cylinder4Assembly0");
					face->Update();
				}
			}
		}
	}



	pDoc->SaveAs("C:\\KompasAssembly\\Vtulka_4.m3d");

	pDoc = pKompasApp5->Document3D();

	pDoc->Create(false, true);

	pPart = pDoc->GetPart(pTop_Part);

	ksEntityPtr pSketch4 = pPart->NewEntity(o3d_sketch);

	pSketchDef = pSketch4->GetDefinition();

	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));

	pSketch4->Create();
	p2DDoc = pSketchDef->BeginEdit();

	point[0][0] = 0;
	point[0][1] = d / 2 - c;
	point[1][0] = c;
	point[1][1] = d / 2;
	point[2][0] = L - c;
	point[2][1] = d / 2;
	point[3][0] = L;
	point[3][1] = d / 2 - c;
	point[4][0] = L;
	point[4][1] = 0;
	point[5][0] = 0;
	point[5][1] = 0;
	p2DDoc->ksLineSeg(point[0][0], point[0][1], point[1][0], point[1][1], 1);
	p2DDoc->ksLineSeg(point[1][0], point[1][1], point[2][0], point[2][1], 1);
	p2DDoc->ksLineSeg(point[2][0], point[2][1], point[3][0], point[3][1], 1);
	p2DDoc->ksLineSeg(point[3][0], point[3][1], point[4][0], point[4][1], 1);
	p2DDoc->ksLineSeg(point[4][0], point[4][1], point[5][0], point[5][1], 1);
	p2DDoc->ksLineSeg(point[5][0], point[5][1], point[0][0], point[0][1], 1);

	p2DDoc->ksLineSeg(-10, 0, 10, 0, 3);


	pSketchDef->EndEdit();

	ksEntityPtr pRotate1 = pPart->NewEntity(o3d_bossRotated);

	ksBossRotatedDefinitionPtr pRotDef1 = pRotate1->GetDefinition();
	pRotDef1->SetSketch(pSketch4);
	pRotDef1->SetSideParam(TRUE, 360);


	pRotate1->Create();
	fledges = pPart->EntityCollection(o3d_edge);
	for (int i = 0; i < fledges->GetCount(); i++)
	{
		ksEntityPtr ed = fledges->GetByIndex(i);
		ksEdgeDefinitionPtr def = ed->GetDefinition();

		if (def->GetOwnerEntity() == pRotate1)
		{
			if (def->IsCircle())
			{
				ksVertexDefinitionPtr p1 = def->GetVertex(true);
				ksVertexDefinitionPtr p2 = def->GetVertex(false);
				double x1, y1, z1;

				p1->GetPoint(&x1, &y1, &z1);
				if (abs(x1) < 1 && abs(y1) < 1 && z1 == -(d / 2 - c))
				{
					ksFaceDefinitionPtr f =
						def->GetAdjacentFace(false);
					ksEntityPtr face = f->GetEntity();
					face->Putname("Face4Assembly1");
					face->Update();
				}

			}

		}
	}
	flFaces = pPart->EntityCollection(o3d_face);
	for (int i = 0; i < flFaces->GetCount(); i++)
	{
		ksEntityPtr face = flFaces->GetByIndex(i);
		ksFaceDefinitionPtr def = face->GetDefinition();
		if (def->GetOwnerEntity() == pRotate1)
		{
			if (def->IsCylinder()) {
				double h, r;
				def->GetCylinderParam(&h, &r);
				if (r == d / 2.0)
				{
					face->Putname("Cylinder4Assembly1");
					face->Update();
				}
			}
		}
	}

	ksEntityPtr pPlane = pPart->NewEntity(o3d_planeOffset);
	ksPlaneOffsetDefinitionPtr pPlaneDef = pPlane->GetDefinition();

	pPlaneDef->direction = true;
	//pPlaneDef->offset = m_Dosn / 2.f;
	pPlaneDef->offset = (d / 2 ) + c;
	pPlaneDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOY));

	pPlane->Create();


	ksEntityPtr pSketch22 = pPart->NewEntity(o3d_sketch);

	pSketchDef = pSketch22->GetDefinition();

	pSketchDef->SetPlane(pPlane);

	pSketch22->Create();

	p2DDoc = pSketchDef->BeginEdit();

	double point1[6][2];
	//point1[0][0] = m_Lobsh - m_OtstupPaza - m_ShirinaPaza / 2.f;
	//point1[0][1] = m_ShirinaPaza / 2.f;

	point1[0][0] = L - (L / 4) - b / 2.f;
	point1[0][1] = b / 2.f;

	//point1[1][0] = m_Lobsh - m_OtstupPaza;
	//point1[1][1] = 0;
	point1[1][0] = L - (L / 4);
	point1[1][1] = 0;

	point1[2][0] = L - (L / 4) - b / 2.f;
	point1[2][1] = -b / 2.f;

	point1[3][0] = L - (L / 4) - (L / 1.5) + b / 2.f;
	point1[3][1] = b / 2.f;

	point1[4][0] = L - (L / 4) - (L / 1.5);
	point1[4][1] = 0;

	point1[5][0] = L - (L / 4) - (L / 1.5) + b / 2.f;
	point1[5][1] = -b / 2.f;


	p2DDoc->ksLineSeg(point1[0][0], point1[0][1], point1[3][0], point1[3][1], 1);
	p2DDoc->ksLineSeg(point1[2][0], point1[2][1], point1[5][0], point1[5][1], 1);

	p2DDoc->ksArcBy3Points(point1[0][0], point1[0][1], point1[1][0], point1[1][1], point1[2][0], point1[2][1], 1);
	p2DDoc->ksArcBy3Points(point1[3][0], point1[3][1], point1[4][0], point1[4][1], point1[5][0], point1[5][1], 1);


	pSketchDef->EndEdit();


	ksEntityPtr pExtrude11 = pPart->NewEntity(o3d_cutExtrusion);
	//ksEntityPtr pExtrude11 = pPart->NewEntity(o3d_bossExtrusion);

	pExDef = pExtrude11->GetDefinition();
	pExDef->directionType = dtNormal;

	pExDef->SetSketch(pSketch22);
	//pExDef->SetSideParam(true, etBlind, (m_GlubinaPaza), 0, false);
	pExDef->SetSideParam(true, etBlind, (d / 4 - c / 2), 0, false);
	pDoc->SaveAs("C:\\KompasAssembly\\Pipe_4.m3d");



	pExtrude11->Create();

	//pDoc = pKompasApp5->Document3D();

	//pDoc->Create(false, true);

	//pPart = pDoc->GetPart(pTop_Part);

	//ksEntityPtr pSketch44 = pPart->NewEntity(o3d_sketch);

	//pSketchDef = pSketch44->GetDefinition();
	//pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOY));

	//pSketch44->Create();
	//p2DDoc = pSketchDef->BeginEdit();

	//point1[0][0] = L - (L / 4) - b / 2.f;
	//point1[0][1] = b / 2.f;

	////point1[1][0] = m_Lobsh - m_OtstupPaza;
	////point1[1][1] = 0;
	//point1[1][0] = L - (L / 4);
	//point1[1][1] = 0;

	//point1[2][0] = L - (L / 4) - b / 2.f;
	//point1[2][1] = -b / 2.f;

	//point1[3][0] = L - (L / 4) - (L / 1.5) + b / 2.f;
	//point1[3][1] = b / 2.f;

	//point1[4][0] = L - (L / 4) - (L / 1.5);
	//point1[4][1] = 0;

	//point1[5][0] = L - (L / 4) - (L / 1.5) + b / 2.f;
	//point1[5][1] = -b / 2.f;

	//p2DDoc->ksLineSeg(point1[0][0], point1[0][1], point1[3][0], point1[3][1], 1);
	//p2DDoc->ksLineSeg(point1[2][0], point1[2][1], point1[5][0], point1[5][1], 1);

	//p2DDoc->ksArcBy3Points(point1[0][0], point1[0][1], point1[1][0], point1[1][1], point1[2][0], point1[2][1], 1);
	//p2DDoc->ksArcBy3Points(point1[3][0], point1[3][1], point1[4][0], point1[4][1], point1[5][0], point1[5][1], 1);


	//pSketchDef->EndEdit();


	//ksEntityPtr pExtrude111 = pPart->NewEntity(o3d_bossExtrusion);
	////ksEntityPtr pExtrude11 = pPart->NewEntity(o3d_bossExtrusion);

	//pExDef = pExtrude111->GetDefinition();
	//pExDef->directionType = dtNormal;

	//pExDef->SetSketch(pSketch44);
	////pExDef->SetSideParam(true, etBlind, (m_GlubinaPaza), 0, false);
	//pExDef->SetSideParam(true, etBlind, (d / 4 - c / 2), 0, false);


	//pExtrude111->Create();





	pDoc = pKompasApp5->Document3D();

	pDoc->Create(false, false);

	pPart = pDoc->GetPart(pTop_Part);

	ksPartPtr pBoss, pPipe1, pPipe2;//,pGear2;
	pDoc->SetPartFromFile("C:\\KompasAssembly\\Vtulka_4.m3d", pPart, true);
	pDoc->SetPartFromFile("C:\\KompasAssembly\\Pipe_4.m3d", pPart, true);
	pDoc->SetPartFromFile("C:\\KompasAssembly\\Pipe_4.m3d", pPart, true);
	//pDoc->SetPartFromFile("C:\\KompasAssembly\\Gear.m3d", pPart, true);

	pBoss = pDoc->GetPart(0);
	pPipe1 = pDoc->GetPart(1);
	pPipe2 = pDoc->GetPart(2);
	//pGear2 = pDoc->GetPart(2);
	ksEntityCollectionPtr col = pBoss->EntityCollection(o3d_face);

	ksEntityPtr Face4Assemly0 = col->GetByName("Face4Assembly0", true, true);
	ksEntityPtr Cylinder4Assemly0 = col->GetByName("Cylinder4Assembly0", true, true);

	col = pPipe1->EntityCollection(o3d_face);
	ksEntityPtr Face4Assemly1 = col->GetByName("Face4Assembly1", true, true);
	ksEntityPtr Cylinder4Assemly1 = col->GetByName("Cylinder4Assembly1", true, true);

	col = pPipe2->EntityCollection(o3d_face);
	ksEntityPtr Face4Assemly2 = col->GetByName("Face4Assembly1", true, true);
	ksEntityPtr Cylinder4Assemly2 = col->GetByName("Cylinder4Assembly1", true, true);

	pDoc->AddMateConstraint(mc_Concentric, Cylinder4Assemly0, Cylinder4Assemly1, 1, 1, 0);
	pDoc->AddMateConstraint(mc_Concentric, Cylinder4Assemly0, Cylinder4Assemly2, 1, 1, 0);
	pDoc->AddMateConstraint(mc_Distance, Face4Assemly0, Face4Assemly1, 1, 1, - (L / 2 + 1));
	pDoc->AddMateConstraint(mc_Distance, Face4Assemly0, Face4Assemly2, 1, 1, L / 2 + 1);



	//ksEntityCollectionPtr col = pBoss->EntityCollection(o3d_face);
	//
	//ksEntityPtr BossFace4Assemly0 = col->GetByName("Face4Assembly0",true,true);
	//ksEntityPtr BossFace4Assemly1 = col->GetByName("Face4Assembly1", true, true);

	//ksEntityPtr BossCylinder4Assemly0 = col->GetByName("Cylinder4Assembly0", true, true);
	//ksEntityPtr BossCylinder4Assemly1 = col->GetByName("Cylinder4Assembly1", true, true);


	//col = pGear1->EntityCollection(o3d_face);
	//ksEntityPtr Gear1Face4Assemly = col->GetByName("Face4Assembly", true, true);
	//

	//ksEntityPtr Gear1Cylinder4Assemly = col->GetByName("Cylinder4Assembly", true, true);

	//col = pGear2->EntityCollection(o3d_face);
	//ksEntityPtr Gear2Face4Assemly = col->GetByName("Face4Assembly", true, true);
	//ksEntityPtr Gear2Cylinder4Assemly = col->GetByName("Cylinder4Assembly", true, true);

	//pDoc->AddMateConstraint(mc_Concentric, BossCylinder4Assemly0, Gear1Cylinder4Assemly, 1, 1, 0);
	//pDoc->AddMateConstraint(mc_Concentric, BossCylinder4Assemly1, Gear2Cylinder4Assemly, -1, 1, 0);

	//pDoc->AddMateConstraint(mc_Coincidence, BossFace4Assemly0, Gear1Face4Assemly, -1, 1, 0);
	//pDoc->AddMateConstraint(mc_Coincidence, BossFace4Assemly1, Gear2Face4Assemly, -1, 1, 0);

	pDoc->RebuildDocument();

	pDoc->SaveAs("C:\\KompasAssembly\\Assembly.3d");
	
}


//void CWSCADDlg::OnBnClickedButton2()
//{
//	
//}


void CWSCADDlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	//if (pInvApp)
	//    pInvApp->MethodQuit();
 //   
	CDialog::OnOK();
}


//void CWSCADDlg::OnEnChangeEditCSmall()
//{
//	// TODO:  If this is a RICHEDIT control, the control will not
//	// send this notification unless you override the CDialog::OnInitDialog()
//	// function and call CRichEditCtrl().SetEventMask()
//	// with the ENM_CHANGE flag ORed into the mask.
//
//	// TODO:  Add your control notification handler code here
//}
