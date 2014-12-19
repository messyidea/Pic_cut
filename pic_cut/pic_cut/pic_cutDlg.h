
// pic_cutDlg.h : ͷ�ļ�
//

#pragma once

//��ֵ���죬����ģ���ָ�
struct Peack  
{  
    int nStat;  
    int nEnd;  
    int nValue;  
    Peack():nStat(0),nEnd(0),nValue(0)  
    {}  
};  
// Cpic_cutDlg �Ի���
class Cpic_cutDlg : public CDialogEx
{
// ����
public:
	Cpic_cutDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PIC_CUT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	CString picpath;
	IplImage *yuanshi;
	IplImage *xianzhu;
	IplImage *mohu;
	IplImage *final_merge;



	//���庯��
	Mat GetFT(const Mat &img3f);			//���������� FTƵ��ȡֵ��
	Mat GetHC(const Mat &img3f);			//���������� HCֱ��ȡֵ��
	Mat Blur_LCK(const Mat &img3f);			//����ģ����
	Mat blur(Mat sal);						//����Ӧģ���ָ�
	Mat  Merge(Mat& blurImg,Mat& salImage); //�ںϺ���

	void Cpic_cutDlg::DrawPicToHDC(IplImage *img, UINT ID);
	
	static void GetHC(const Mat &binColor3f, const Mat &weights1f, Mat &colorSaliency);
	static void SmoothSaliency(const Mat &binColor3f, Mat &sal1d, float delta, const vector<vector<CostfIdx>> &similar);
	static int Quantize(const Mat& img3f, Mat &idx1i, Mat &_color3f, Mat &_colorNum, double ratio = 0.95); //����Ӧģ���ָ�
	void GetPeaks(const int pTistogram[256], const int nLowValue,vector<Peack> &vctPeak);  //����Ӧģ���ָ�
	double MemshipFunc(int nGray,const int& nWinCent,const int& nWinWidth) ;//�����Թ��ܺ���
	void solve(Mat& sal,Mat& sal2,int n);				//ͼ��ָ�ϲ������Զ���ģ����
	Mat solve(Mat& sal,Mat& sal2);                      //�ں�ͼ��ķָ�

	//double MemshipFunc(int nGray,const int& nWinCent,const int& nWinWidth);  
	afx_msg void OnBnClickedButton2();
	afx_msg void OnStnClickedMohu();
};
