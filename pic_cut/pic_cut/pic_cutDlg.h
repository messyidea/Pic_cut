
// pic_cutDlg.h : 头文件
//

#pragma once

//峰值构造，用于模糊分割
struct Peack  
{  
    int nStat;  
    int nEnd;  
    int nValue;  
    Peack():nStat(0),nEnd(0),nValue(0)  
    {}  
};  
// Cpic_cutDlg 对话框
class Cpic_cutDlg : public CDialogEx
{
// 构造
public:
	Cpic_cutDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_PIC_CUT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


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
//	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	CString picpath;
	IplImage *yuanshi;
	IplImage *xianzhu;
	IplImage *mohu;
	IplImage *final_merge;



	//定义函数
	Mat GetFT(const Mat &img3f);			//计算显著性 FT频方取值法
	Mat GetHC(const Mat &img3f);			//计算显著性 HC直方取值法
	Mat Blur_LCK(const Mat &img3f);			//计算模糊核
	Mat blur(Mat sal);						//自适应模糊分割
	Mat  Merge(Mat& blurImg,Mat& salImage); //融合函数

	void Cpic_cutDlg::DrawPicToHDC(IplImage *img, UINT ID);
	
	static void GetHC(const Mat &binColor3f, const Mat &weights1f, Mat &colorSaliency);
	static void SmoothSaliency(const Mat &binColor3f, Mat &sal1d, float delta, const vector<vector<CostfIdx>> &similar);
	static int Quantize(const Mat& img3f, Mat &idx1i, Mat &_color3f, Mat &_colorNum, double ratio = 0.95); //自适应模糊分割
	void GetPeaks(const int pTistogram[256], const int nLowValue,vector<Peack> &vctPeak);  //自适应模糊分割
	double MemshipFunc(int nGray,const int& nWinCent,const int& nWinWidth) ;//显著性功能函数
	void solve(Mat& sal,Mat& sal2,int n);				//图像分割并合并显著性都和模糊核
	Mat solve(Mat& sal,Mat& sal2);                      //融合图像的分割

	//double MemshipFunc(int nGray,const int& nWinCent,const int& nWinWidth);  
	afx_msg void OnBnClickedButton2();
	afx_msg void OnStnClickedMohu();
};
