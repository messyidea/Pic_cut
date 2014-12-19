
// pic_cutDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "pic_cut.h"
#include "pic_cutDlg.h"
#include "afxdialogex.h"
#include "string"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cpic_cutDlg �Ի���




Cpic_cutDlg::Cpic_cutDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cpic_cutDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cpic_cutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cpic_cutDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//	ON_BN_CLICKED(IDOK, &Cpic_cutDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Cpic_cutDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &Cpic_cutDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cpic_cutDlg::OnBnClickedButton2)
	ON_STN_CLICKED(IDC_MOHU, &Cpic_cutDlg::OnStnClickedMohu)
END_MESSAGE_MAP()


// Cpic_cutDlg ��Ϣ�������

BOOL Cpic_cutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cpic_cutDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cpic_cutDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cpic_cutDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void Cpic_cutDlg::OnBnClickedOk()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	CDialogEx::OnOK();
//}


void Cpic_cutDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void Cpic_cutDlg::OnBnClickedButton1()
{

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog opendialog(TRUE);
	CString temp;
	if (opendialog.DoModal() == IDOK)
	{
		//opendialog.SetWindowTextW(opendialog.GetPathName());
		//MessageBox(opendialog.GetPathName());
		//CString temp;
		temp = opendialog.GetPathName();
		//picpath = temp.GetBuffer(0);;
	}

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	IplImage *image=NULL; //ԭʼͼ��
	//Mat ima;
	if(&image) cvReleaseImage(&image);
	const size_t strsize=(temp.GetLength()+1)*2; // ���ַ��ĳ���;
	char * pstr= new char[strsize]; //����ռ�;
	size_t sz=0;
	wcstombs_s(&sz,pstr,strsize,temp,_TRUNCATE);
	//MessageBox(temp);
	//imread(pstr,CV_LOAD_IMAGE_GRAYSCALE);
	//int n=(atoi(std::char * pstr); // �ַ����Ѿ���ԭ����CString ת������ const char*
	image = cvLoadImage(pstr,1); //��ʾͼƬ
	yuanshi = image;
	//IplImage* image= &IplImage(ima); 
	DrawPicToHDC(image, IDC_STATIC);
}

void Cpic_cutDlg::DrawPicToHDC(IplImage *img, UINT ID)
{
	CDC *pDC = GetDlgItem(ID)->GetDC();
	HDC hDC= pDC->GetSafeHdc();
	CRect rect;
	GetDlgItem(ID)->GetClientRect(&rect);
	CvvImage cimg;
	cimg.CopyOf( img ); // ����ͼƬ
	cimg.DrawToHDC( hDC, &rect ); // ��ͼƬ���Ƶ���ʾ�ؼ���ָ��������
	ReleaseDC( pDC );
}

void Cpic_cutDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/*yuanshi		:ԭʼͼ�� IplImage����
	* OriginImage   :ԭʼͼ���Mat����
	*/
	Mat OriginImage(yuanshi,1);
	
	Mat temp = OriginImage;
	Mat imgbl = OriginImage;
	Mat imgsl = OriginImage;
	
		/*ת����ɫ�ռ���32λ�������й�һ��*/
	imgsl.convertTo	(imgsl, CV_32FC3, 1.0/255);				/* ���Ų�ת������������� 
															 * ��һ��������Դͼ�� 
															 * �ڶ���������RGBͨ���ĸ�ʽ CV_32FC3:3ͨ��32λ��������ʾ
															 * ��������������ͼ�񰴱�����С����һ��
															 */
	
	//Mat salFT = GetFT(img3f);
	Mat salHC =	GetHC(imgsl);
	//imshow("HC_Saliency",salHC);
	xianzhu = &IplImage(salHC);
	//MessageBox(_T("haha"));
	DrawPicToHDC(xianzhu, IDC_XIANZHU);
	//imshow("HC_Saliency",salHC);


	/*����һ��ģ��ֵ�ļ��㲢���л���ģ����ֵ�ķָ�*/
	Mat imblur;
	imblur=blur(imgbl);
	mohu = &IplImage(imblur);
	DrawPicToHDC(mohu, IDC_MOHU);
	//imshow( "Blur", imblur );
	

	                                     
	//�ں�ģ���Ⱥ�������
	Mat mergeImage = Merge(imblur ,salHC);
	//imshow("11",mergeImage);
	//imshow("22",temp);
	Mat finalImage=solve(mergeImage,temp);
	final_merge = &IplImage(finalImage);
	DrawPicToHDC(final_merge,IDC_FINAL);
	//imshow("MergeImage",mergeImage);
	
	//�ֱ���FT�㷨��HC�㷨����ͼ��ָ�
	/*solve(salFT,temp,1);
	
	Mat salHCTem=salHC;
	threshold(salHCTem,salHCTem, 0.36, 1,CV_THRESH_BINARY);

	solve(salHCTem,temp,2);
	solve(mergeImage,temp,3);*/
					/*
					* solve��������
					* ǰ��һ��Mat:������ͼ
					* ����һ��Mat:ԭͼ
					*/
	
	
	//����Ϊ���鲻�õ�
	//Mat ys3 = ys;
	//ys3.convertTo(ys3, CV_32FC3, 1.0/255);	//���Ų�ת�������������
	//imshow("1",ys);
	//Mat ys2 = GetFT(ys3);
	//imshow("2",ys2);
	//xianzhu = &IplImage(ys2);
	//Mat mh = blur(ys);
	//mohu = &IplImage(mh);
	//DrawPicToHDC(xianzhu, IDC_XIANZHU);
	//Mat mh = blur(ys);
	//DrawPicToHDC(mohu, IDC_MOHU);
}

//FT�������㷨
Mat Cpic_cutDlg::GetFT(const Mat &img3f)
{
	int r,c;
	
	CV_Assert(img3f.data != NULL && img3f.type() == CV_32FC3);	//CV_Assert�����������еı��ʽֵΪfalse���򷵻�һ��������Ϣ��ȷ���õ���ͼ���������ȷ��
	Mat sal(img3f.size(), CV_32F), tImg;						//���建�����sal��tImg
	GaussianBlur(img3f, tImg, Size(3, 3), 0);					//��˹�˲�,�޳�����
	cvtColor(tImg, tImg, CV_BGR2Lab);                           //ת����ɫ�ռ�
	Scalar colorM = mean(tImg);	                                //Scalar��һ��short��vector�ṹ�����ݣ�����colorM�洢

	cout<<"FT >> col:"<<tImg.cols<<" row:"<<tImg.rows<<endl;

	for (int r = 0; r < tImg.rows; r++)
	{
		float *s = sal.ptr<float>(r);
		float *lab = tImg.ptr<float>(r);
		for (int c = 0; c < tImg.cols; c++, lab += 3)
			s[c] = (float)(sqr(colorM[0] - lab[0]) + sqr(colorM[1] - lab[1]) + sqr(colorM[2] - lab[2]));
	}
	normalize(sal, sal, 0.0, 1.0, NORM_MINMAX);//�����һ��
	//imshow("FC_Saliency",sal);
	threshold(sal, sal,0.34, 1.0,CV_THRESH_BINARY);

	/*
	* opencv��ֵ������ ��ԭʼ���飬������飬��ֵ�����ֵ����ֵ���ͣ�
	* threshold_type=CV_THRESH_BINARY:
	* dst(x,y) = max_value, if src(x,y)>threshold 0, otherwise.
	*/
	return sal;
}

//HC�������㷨
void Cpic_cutDlg::GetHC(const Mat &binColor3f, const Mat &weight1f, Mat &_colorSal)
{
	int binN = binColor3f.cols; 
	_colorSal = Mat::zeros(1, binN, CV_32F);
	float* colorSal = (float*)(_colorSal.data);
	vector<vector<CostfIdx>> similar(binN); // Similar color: how similar and their index
	Vec3f* color = (Vec3f*)(binColor3f.data);
	float *w = (float*)(weight1f.data);
	for (int i = 0; i < binN; i++)
	{
		vector<CostfIdx> &similari = similar[i];
		similari.push_back(make_pair(0.f, i));
		for (int j = 0; j < binN; j++)
		{
			if (i == j)
				continue;
			float dij = vecDist3<float>(color[i], color[j]);
			similari.push_back(make_pair(dij, j));
			colorSal[i] += w[j] * dij;
		}
		sort(similari.begin(), similari.end());
	}

	SmoothSaliency(binColor3f, _colorSal, 4.0f, similar);
}

void Cpic_cutDlg::SmoothSaliency(const Mat &binColor3f, Mat &sal1d, float delta, const vector<vector<CostfIdx>> &similar)
{
	if (sal1d.cols < 2)
		return;
	CV_Assert(binColor3f.size() == sal1d.size() && sal1d.rows == 1);
	int binN = binColor3f.cols;
	Vec3f* color = (Vec3f*)(binColor3f.data);
	Mat tmpSal;
	sal1d.copyTo(tmpSal);
	float *sal = (float*)(tmpSal.data);
	float *nSal = (float*)(sal1d.data);

	//* Distance based smooth
	int n = max(cvRound(binN/delta), 2);
	vecF dist(n, 0), val(n);
	for (int i = 0; i < binN; i++)
	{
		const vector<CostfIdx> &similari = similar[i];
		float totalDist = 0;

		val[0] = sal[i];
		for (int j = 1; j < n; j++)
		{
			int ithIdx =similari[j].second;
			dist[j] = similari[j].first;
			val[j] = sal[ithIdx];
			totalDist += dist[j];
		}
		float valCrnt = 0;
		for (int j = 0; j < n; j++)
			valCrnt += val[j] * (totalDist - dist[j]);

		nSal[i] =  valCrnt / ((n-1) * totalDist);
	}	
}

int  Cpic_cutDlg::Quantize(const Mat& img3f, Mat &idx1i, Mat &_color3f, Mat &_colorNum, double ratio)
{
	static const int clrNums[3] = {12, 12, 12};
	static const float clrTmp[3] = {clrNums[0] - 0.0001f, clrNums[1] - 0.0001f, clrNums[2] - 0.0001f};
	static const int w[3] = {clrNums[1] * clrNums[2], clrNums[2], 1};

	CV_Assert(img3f.data != NULL);
	idx1i = Mat::zeros(img3f.size(), CV_32S);
	int rows = img3f.rows, cols = img3f.cols;
	if (img3f.isContinuous() && idx1i.isContinuous())
	{
		cols *= rows;
		rows = 1;
	}

	// Build color pallet
	map<int, int> pallet;
	for (int y = 0; y < rows; y++)
	{
		const float* imgData = img3f.ptr<float>(y);
		int* idx = idx1i.ptr<int>(y);
		for (int x = 0; x < cols; x++, imgData += 3)
		{
			idx[x] = (int)(imgData[0]*clrTmp[0])*w[0] + (int)(imgData[1]*clrTmp[1])*w[1] + (int)(imgData[2]*clrTmp[2]);
			pallet[idx[x]] ++;
		}
	}

	// Fine significant colors
	int maxNum = 0;
	{
		int count = 0;
		vector<pair<int, int>> num; // (num, color) pairs in num
		num.reserve(pallet.size());
		for (map<int, int>::iterator it = pallet.begin(); it != pallet.end(); it++)
			num.push_back(pair<int, int>(it->second, it->first)); // (color, num) pairs in pallet
		sort(num.begin(), num.end(), std::greater<pair<int, int>>());

		maxNum = (int)num.size();
		int maxDropNum = cvRound(rows * cols * (1-ratio));
		for (int crnt = num[maxNum-1].first; crnt < maxDropNum && maxNum > 1; maxNum--)
			crnt += num[maxNum - 2].first;
		maxNum = min(maxNum, 256); // To avoid very rarely case
		if (maxNum < 10)
			maxNum = min((int)pallet.size(), 100);
		pallet.clear();
		for (int i = 0; i < maxNum; i++)
			pallet[num[i].second] = i; 

		vector<Vec3i> color3i(num.size());
		for (unsigned int i = 0; i < num.size(); i++)
		{
			color3i[i][0] = num[i].second / w[0];
			color3i[i][1] = num[i].second % w[0] / w[1];
			color3i[i][2] = num[i].second % w[1];
		}

		for (unsigned int i = maxNum; i < num.size(); i++)
		{
			int simIdx = 0, simVal = INT_MAX;
			for (int j = 0; j < maxNum; j++)
			{
				int d_ij = vecSqrDist3(color3i[i], color3i[j]);
				if (d_ij < simVal)
					simVal = d_ij, simIdx = j;
			}
			pallet[num[i].second] = pallet[num[simIdx].second];
		}
	}

	_color3f = Mat::zeros(1, maxNum, CV_32FC3);
	_colorNum = Mat::zeros(_color3f.size(), CV_32S);

	Vec3f* color = (Vec3f*)(_color3f.data);
	int* colorNum = (int*)(_colorNum.data);
	for (int y = 0; y < rows; y++) 
	{
		const Vec3f* imgData = img3f.ptr<Vec3f>(y);
		int* idx = idx1i.ptr<int>(y);
		for (int x = 0; x < cols; x++)
		{
			idx[x] = pallet[idx[x]];
			color[idx[x]] += imgData[x];
			colorNum[idx[x]] ++;
		}
	}
	for (int i = 0; i < _color3f.cols; i++){
		color[i].val[0] /= colorNum[i];
		color[i].val[1] /= colorNum[i];
		color[i].val[2] /= colorNum[i];
	}

	return _color3f.cols;
}

Mat  Cpic_cutDlg::GetHC(const Mat &img3f)
{
	// Quantize colors and
	cout<<"<--����HC�㷨-->"<<endl;
	Mat idx1i, binColor3f, colorNums1i, weight1f, _colorSal;
	Quantize(img3f, idx1i, binColor3f, colorNums1i);
	cvtColor(binColor3f, binColor3f, CV_BGR2Lab);

	normalize(colorNums1i, weight1f, 1, 0, NORM_L1, CV_32F);
	GetHC(binColor3f, weight1f, _colorSal);
	float* colorSal = (float*)(_colorSal.data);
	Mat salHC1f(img3f.size(), CV_32F);
	for (int r = 0; r < img3f.rows; r++)
	{
		float* salV = salHC1f.ptr<float>(r);
		int* _idx = idx1i.ptr<int>(r);
		for (int c = 0; c < img3f.cols; c++)
			salV[c] = colorSal[_idx[c]];
	}
	GaussianBlur(salHC1f, salHC1f, Size(3, 3), 0);
	normalize(salHC1f, salHC1f, 0, 1, NORM_MINMAX);
	//threshold(salHC1f, salHC1f, 0.4, 1,CV_THRESH_BINARY);
	return salHC1f;
}

/*����λ�ø���Ȩ��*/
Mat Position_solve(Mat &sal)
{
	int r;int c;
	//���Խ׶Σ����㼸������
	float col_w=0.0,row_w=0.0;
	float sum=0.0;
	//�������ĵ�����
	Mat salTem = sal;

	threshold(salTem, salTem,0.15, 1.0,CV_THRESH_BINARY);

	for (r = 0; r < sal.rows; r++)
	{
		float *ss = salTem.ptr<float>(r);
		for (c = 0; c < sal.cols; c++)
		{
			//ss[c]/=(float)(sqr((tImg.rows/2.0)-r)/tImg.rows)*(float)(sqr((tImg.cols/2.0)-c)/tImg.cols);		//����λ�õ�Ȩ��
			//cout<<"ss: "<<ss[c]<<endl;
			if(ss[c]!=0){
				col_w+=c;row_w+=r;sum++;
			}
		}
	}
	cout<<"col_w:"<<col_w<<"  row_w:"<<row_w<<"  sum:"<<sum<<endl;
	cout<<"col_w/sum:"<<(float)col_w/sum<<"  row_w/sum:"<<(float)row_w/sum<<"  sum:"<<sum<<endl;
	col_w=(float)col_w/sum;
	row_w=(float)row_w/sum;
	
	//���ݼ������ĸ���Ȩ��
	imshow("s",sal);
	float d;								//�������ص���뼸������
	for (r = 0; r < sal.rows; r++)
	{
		float *sss = sal.ptr<float>(r);
		for (c = 0; c <sal.cols; c++)
		{
			float num1=(float)(sqr(row_w-r));
			float num2=(float)(sqr(col_w-c));
			d=sqrt(num1*num1+num2*num2+1);
			sss[c]=sss[c]*1000/d;       	//����λ�õ�Ȩ��
		//	if(sss[c]!=0)cout<<sss[c]<<endl;
		}
	}
	
	imshow("threshold_begin",sal);
	threshold(sal, sal,0.08,2,CV_THRESH_BINARY);
	return sal;
}

//ģ���ȹ��ƺ���
Mat Cpic_cutDlg::blur(Mat sal){
	//IplImage* imgBuf = cvCreateImage(size,IPL_DEPTH_8U,1);
	//IplImage* src= cvCreateImage(cvSize(sal.cols,sal.rows),IPL_DEPTH_8U,3);
	//sal = src;
	//cvtColor(sal, sal, CV_BGR2Lab);
	//cvConvertScaleAbs(sal,sal);
	//cvtColor(sal, sal, CV_BGR2GRAY);
	cvtColor(sal, sal, CV_BGR2GRAY);
	sal.convertTo(sal, CV_8UC1, 1.0);
	double sum = 0;
	for (int i=0;i<sal.rows;i++){
		uchar *s = sal.ptr<uchar>(i);
		for(int j=0;j<sal.cols;j++){
			cout<<s[i]<<endl;
		}
	}
	//imshow("haha",sal);
	//sal.convertTo(sal, CV_8UC1);
	//sal = cv::Mat(sal.rows, sal.cols, CV_8UC3 ); 
	//cvtColor(sal, sal, CV_BGR2GRAY);
	//CV_8UC3
	/*for (int i=0;i<sal.rows;i++){
		float *s = sal.ptr<float>(i);
		for(int j=0;j<sal.cols;j++){
			cout<<s[j]<<endl;
		}
	}*/
	//cout<<"zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"<<endl;
	int i,j,k;
	int  btTempValue = 0;
	int lSrcWidth = sal.cols;
	int lSrcHeight = sal.rows;
	int nTistogram[256] = {0};
	//cout<<"345"<<endl;
	for (i = 0;i < lSrcHeight; ++i)  
    {  
		uchar *s = sal.ptr<uchar>(i);
		//cout<<11<<endl;
        //lpSrcPtr = lpBmp + i * dLineBites;  
        for (j = 0;j <lSrcWidth; ++j)  
        {  
            //btTempValue = (BYTE)*(lpSrcPtr + j);  
            nTistogram[max(0,min(int(s[j]),255))]++;  
        }  
    }
	//for(int i=0;i<256;++i) cout<<nTistogram[i]<<endl;
	int nSum = 0, nMaxTtg = 0;  
    const int c_nScop = 5;  
    int arrValue[c_nScop] = {0};  
    for (j = 0;j <256; ++j)  
    {  
        nSum += nTistogram[j];  
        if(j < c_nScop)  
        {  
            arrValue[j] = nTistogram[j];  
            nTistogram[j] = nSum/(j+1);  
        }  
        else  
        {  
            i = j%c_nScop;  
            nSum -= arrValue[i];  
            arrValue[i] = nTistogram[j];  
            nTistogram[j] = nSum/c_nScop;  
        }  
        if(nMaxTtg < nTistogram[j])  
            nMaxTtg = nTistogram[j];  
        //outFile<<nTistogram[j]<<endl;  
    }//end  
	cout<<"123"<<endl;
	vector <Peack> vctPeak; 
	GetPeaks(nTistogram,nMaxTtg/500,vctPeak);  
    int nNum = vctPeak.size();  
    if(nNum > 1)  
    {  
        int arrThesh[255] = {0};  
        int nSetScop = 255/(nNum -1);  
        for (i=0; i<nNum-1; i++)  
        {  
            int nWinWidth = int(0.3*(vctPeak[i+1].nValue-vctPeak[i].nValue));  
            double dGetMemship = 0,dMinData = 0xFFFFFFFF;  
            for (int nGrayPos = vctPeak[i].nValue;nGrayPos <= vctPeak[i+1].nValue; ++nGrayPos)  
            {  
                double dOutData = 0;  
                for (j = 0;j <256; ++j)  
                {  
                    dGetMemship = MemshipFunc(j,nGrayPos,nWinWidth);  
                    if(dGetMemship > 0.5)  
                        dGetMemship = 1 - dGetMemship;  
                    if(dGetMemship < 0)  
                        dGetMemship = 0;//-dGetMemship;  
                    dOutData += nTistogram[j]*dGetMemship;  
                }  
                //dOutData *= 2.0/(lSrcHeight*lSrcWidth);  
                if(dMinData > dOutData)  
                {  
                    dMinData = dOutData;  
                    arrThesh[i] = nGrayPos;  
                }  
            }  
        }  
        //---------  
        for (i = 0;i < lSrcHeight; ++i)  
        {  
			uchar *s = sal.ptr<uchar>(i);
            //lpSrcPtr = lpSrcData + i * dLineBites;  
            //lpDstPtr = lpDstData + i * dLineBites;  
            for (j = 0;j <lSrcWidth; ++j)  
            {  
                //btTempValue = (BYTE)*(lpSrcPtr + j);  
				btTempValue = int(s[j]);  
                int k;  
                for ( k=0; k<nNum-1; k++)  
                {  
                    if(btTempValue < arrThesh[k])  
                    {  
                        s[j]=  (int)(k*nSetScop);  
                        break;  
                    }  
                }  
				//cout<<"haha"<<endl;
                if(k == nNum-1)  
                    s[j] = 255;  
            }  
        }//END FOR  
    }  
    else if(nNum == 1)//���壬�÷�ֵ����Ϊ�ָ��  
    {  
        for (i = 0;i < lSrcHeight; ++i)  
        {  
			uchar *s = sal.ptr<uchar>(i);
            //lpSrcPtr = lpSrcData + i * dLineBites;  
            //lpDstPtr = lpDstData + i * dLineBites;  
            for (j = 0;j <lSrcWidth; ++j)  
            {  
                btTempValue = int(s[j]);  
				cout<<"haha"<<endl;
                if(btTempValue < vctPeak[0].nEnd)  
                    s[j]=  0;  
                else  
                   s[j] = 255;  
            }  
        }  
    }  
    else  
    {  
        //MessageBox(_T("�ָ�ʧ��"),_T("��ʾ"),MB_ICONWARNING);  
    } 
	//imshow("1",sal);
	return sal;
}


void Cpic_cutDlg::GetPeaks(const int pTistogram[256], const int nLowValue,vector<Peack> &vctPeak)  
{
    int arrPos[2] = {0};  
    int nSratMin = 0xFFFFFF,nContinueNum=0;  
    int nPreValue = pTistogram[0];  
    int nSetThres = 8;  
    for (int i=1; i<256; i++)  
    {  
        if(nSratMin > pTistogram[i])  
        {  
            nSratMin = pTistogram[i];  
            if(nSratMin <= nLowValue)  
                nSetThres = 5;  
        }  
        //-------------------------------  
        if(arrPos[0] != 0)  
        {  
            if(pTistogram[i] < nPreValue)  
            {  
                nContinueNum ++;  
                if(nContinueNum >= nSetThres)  
                    arrPos[1] = i;  
            }  
            else// if(nTistogram[i] > nPreValue)  
            {  
                if(arrPos[1] != 0)//data out  
                {  
                    Peack pk;  
                    pk.nStat = arrPos[0];  
                    pk.nEnd = arrPos[1];  
                    vctPeak.push_back(pk);  
                    //--------  
                    arrPos[0] = arrPos[1] =0;  
                    nSratMin = 0xFFFFFF;  
                    nSetThres = 10;  
                }  
                nContinueNum = 0;  
            }  
        }  
        else  
        {  
            if(pTistogram[i] > nPreValue)  
            {  
                nContinueNum ++;  
                if(nContinueNum >= nSetThres)  
                    arrPos[0] = i-nSetThres;  
            }  
            else //if(nTistogram[i] < nPreValue)  
            {  
                static int s_nLowNum = 0;  
                if(pTistogram[i] < nPreValue)  
                {  
                    s_nLowNum ++;  
                    if(s_nLowNum == i && s_nLowNum > 10)  
                        arrPos[0] = 1;  
                }  
                else if(nContinueNum > 2)  
                    nContinueNum ++;  
                else  
                    nContinueNum = 0;  
            }  
        }  
        /////////////////////////////////  
        nPreValue = pTistogram[i];  
    }  
    //============��ֵ����==============  
    int nSum = 0,nTistoSum = 0;  
    vector<Peack>::iterator it=vctPeak.begin();  
    while (it != vctPeak.end())  
    {  
        nSum = nTistoSum = 0;  
        for (int i=(*it).nStat; i<=(*it).nEnd; i++)  
        {  
            nSum += i*pTistogram[i];  
            nTistoSum += pTistogram[i];  
        }  
        (*it).nValue = nSum/nTistoSum;  
        it++;  
    }  
}  


double Cpic_cutDlg::MemshipFunc(int nGray,const int& nWinCent,const int& nWinWidth)  
{  
    int nLeft = nWinCent-nWinWidth;  
    int nRight = nWinCent+nWinWidth;  
    if(nGray >= 0 && nGray <= nLeft)  
        return 0;  
    else if(nGray > nLeft && nGray <= nWinCent)  
    {  
        double dMem = double(nGray - nLeft)/(2*nWinWidth);  
        return 2*dMem*dMem;  
    }  
    else if(nGray > nWinCent && nGray <= nRight)  
    {  
        double dMem = double(nGray - nLeft)/(2*nWinWidth);  
        return 1-2*dMem*dMem;  
    }  
    return 1;  
}  


/**�ںϺ���**/
Mat  Cpic_cutDlg::Merge(Mat& blurImg,Mat& salImg)
{	
	Mat mergeImg(blurImg.size(), CV_32F);	//���建�����mergeImg
	Scalar colorMerge1 = mean(blurImg);		//Scalar��һ��short��vector�ṹ�����ݣ�����洢
	Scalar colorMerge2 = mean(salImg);		

	if(blurImg.size()!=salImg.size()){cout<<"ģ����Mat��������Mat��С��ͬ"<<endl;}
	else{
		/*�ںϿ�ʼ*/
		float r1 =0.75;	//����ԽС��ζ��Խ����ģ����
		float r2 =0.25; //����ԽС��ζ��Խ����������
	for (int r = 0; r < blurImg.rows; r++)
	{
		float* mergeTem = mergeImg.ptr<float>(r);
		uchar* bImg = blurImg.ptr<uchar>(r);
		float* sImg = salImg.ptr<float>(r);

		for (int c = 0; c < blurImg.cols; c++)
		{
			//cout<<sImg[c]<<" ";
			float  tem1 = 1.0-exp((-1)*(int)bImg[c]/(255*r1));
			float  tem2 = 1.0-exp((-1)*sImg[c]/r2);
			mergeTem[c] = (0.5)*(tem1+tem2);
		}
		cout<<endl;
	}

	/*for (r = 0; r < tImg.rows; r++)
	{
		float *s = sal.ptr<float>(r);
		float *lab = tImg.ptr<float>(r);
		for (c = 0; c < tImg.cols; c++, lab += 3)
		{
			s[c] = (float)(sqr(colorM[0] - lab[0]) + sqr(colorM[1] - lab[1]) + sqr(colorM[2] - lab[2]));    //������ɫ��Ȩ�أ���ԵȨ��
			//s[c]/=(float)(sqr((tImg.rows/2.0)-r)/tImg.rows)*(float)(sqr((tImg.cols/2.0)-c)/tImg.cols);		//����λ�õ�Ȩ��
		}
	}
	*/
	}
	return  mergeImg;
}
/**�������**/
Mat Cpic_cutDlg::solve(Mat& sal,Mat& sal2)                      //�ں�ͼ��ķָ�
{
	threshold(sal, sal, 0.4, 1,CV_THRESH_BINARY);
	Mat mask;
	Mat sal3 = sal2;
	mask.create( sal2.size(), CV_8UC1);
	
	for (int i=0;i<sal.rows;i++){
		float *s = sal.ptr<float>(i);
		for(int j=0;j<sal.cols;j+=3){
			if(fabs(s[j])<1e-7){
				circle( mask, Point(j,i), 2, 2, -1 );
			}
			else circle( mask, Point(j,i), 2, 3, -1 );
		}
	}
	
	Mat haha,hh ;
	//imshow("33",sal2);
	//imshow("44",mask);

	grabCut(sal2,mask,Rect(0,0,sal2.rows,sal2.cols),haha,hh,1,1);
	
	compare(mask,cv::GC_PR_FGD,mask,cv::CMP_EQ);
	
	// �������ͼ��
	Mat foreground(sal2.size(),CV_8UC3,cv::Scalar(255,255,255));
	//����ֵΪ GC_BGD=0����Ϊ����
	sal2.copyTo(foreground,mask);
	return foreground;
	//imshow(consol_name,foreground);
}
void Cpic_cutDlg::solve(Mat& sal,Mat& sal2,int n){
	string consol_name;
	if(n==1){consol_name="FT_GrabCut";}
	else if(n==2){consol_name="HC_GrabCut";}
	else if(n==3){
		consol_name="Merge_GrabCut";
		threshold(sal, sal, 0.4, 1,CV_THRESH_BINARY);
	}

	Mat mask;
	Mat sal3 = sal2;
	mask.create( sal2.size(), CV_8UC1);
	
	for (int i=0;i<sal.rows;i++){
		float *s = sal.ptr<float>(i);
		for(int j=0;j<sal.cols;j+=3){
			if(fabs(s[j])<1e-7){
				circle( mask, Point(j,i), 2, 2, -1 );
			}
			else circle( mask, Point(j,i), 2, 3, -1 );
		}
	}
	cout<<sal.rows<<"   "<<sal.cols<<endl;
	//imshow("imaa",mask);
	Mat haha,hh ;

	grabCut(sal2,mask,Rect(0,0,sal2.rows,sal2.cols),haha,hh,1,1);
	
	compare(mask,cv::GC_PR_FGD,mask,cv::CMP_EQ);
	
	// �������ͼ��
	Mat foreground(sal2.size(),CV_8UC3,cv::Scalar(255,255,255));
	//����ֵΪ GC_BGD=0����Ϊ����
	sal2.copyTo(foreground,mask);
	imshow(consol_name,foreground);
}

void Cpic_cutDlg::OnStnClickedMohu()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
