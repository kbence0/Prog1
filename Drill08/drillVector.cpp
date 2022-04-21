//g++ drillVector.cpp -o main
#include "../std_lib_facilities.h"

int main()
{

	vector<double> vd;
	ofstream Vectortxt("vectorDouble.txt");

	double read = 0;
	cout << "Data to write:" << endl;

	for (int i = 0; i < 2; ++i)
	{
		cin >> read;
		Vectortxt << read << "\n";
		vd.push_back(read);
	}

	Vectortxt.close();

	vector<int> vi(vd.size());

	copy(vd.begin(),vd.end(),vi.begin());

	cout << endl;

	for (int i = 0; i < vd.size(); ++i)
	{
		cout << vi[i] << endl;
	}
	
	cout << endl << "vd[i]" << "\t" << "vi[i]" << endl;
	for (int i = 0; i < vd.size(); ++i)
	{
		cout << vd[i] << "\t" << vi[i] << endl;
	}

	double sumvd = 0;
	int sumvi = 0;

	for (int i = 0; i < vd.size(); ++i)
	{
		sumvd+=vd[i];
		sumvi+=vi[i];
	}

	cout << endl << "vd Sum\t" << "vi Sum" << endl;
	cout << sumvd << "\t" << sumvi << endl;

	reverse(vd.begin(),vd.end());

	cout << endl << "vd reversed" << endl;
	for (int i = 0; i < vd.size(); ++i)
	{
		cout << vd[i] << endl;
	}

	double mean = sumvd/vd.size();

	cout << endl << "vd mean value: " << mean << endl;

	vector<double> vd2;

	for (int i = 0; i < vd.size(); ++i)
	{
		if (vd[i] < mean)
		{
			vd2.push_back(vd[i]);
		}
	}


	cout << endl << "values lower than mean" << endl;
	for (int i = 0; i < vd2.size(); ++i)
	{
		cout << vd2[i] << endl;
	}

	sort(vd.begin(),vd.end());

	cout << endl << "sorted vd" << endl;
	for (int i = 0; i < vd.size(); ++i)
	{
		cout << vd[i] << endl;
	}

	return 0;
}