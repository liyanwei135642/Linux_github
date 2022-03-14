#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<vector>
#include<stack>
#include <string>

using namespace std;

namespace mat_namespace
{
	/// <summary>
	/// ������ģ��
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<class T>
	class matlab
	{
		/// <summary>
		/// ��Ԫ���� int���������˷���������أ�
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="d"></param>
		/// <param name="mat1"></param>
		/// <returns></returns>
		template<class T>
		friend matlab<double> operator*(int d, matlab<T> mat1);

		/// <summary>
		/// ��Ԫ���� double���������˷���������أ�
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="d"></param>
		/// <param name="mat1"></param>
		/// <returns></returns>
		template<class T>
		friend matlab<double> operator*(double d, matlab<T> mat1);


		int  _n;
		int _m;
		vector<vector<T>> _arr;
	public:

		string _name;

		/// <summary>
		///���� n �� m �� ȫΪ x �ľ���
		/// </summary>
		/// <param name="n"></param>
		/// <param name="m"></param>
		/// <param name="x"></param>
		matlab(int n = 0, int m = 0, T x = T())
		{
			_name = "ans";
			_n = n;
			if (m == 0)
			{
				m = n;
			}
			_m = m;
			_arr.resize(n + 1);
			for (auto& i : _arr)
			{
				i.resize(m + 1, x);
			}
		}

		/// <summary>
		/// �������죺
		/// </summary>
		/// <param name="mat1"></param>
		matlab(const matlab<T>& mat1)
		{
			_name = mat1._name;
			_n = mat1._n;
			_m = mat1._m;
			_arr.resize(_n + 1);
			for (int i = 0; i <= _n; i++)
			{
				_arr[i].resize(_m + 1);
				for (int j = 0; j <= _m; j++)
				{
					_arr[i][j] = mat1._arr[i][j];
				}
			}
		}

		/// <summary>
		/// ��ֵ��������أ�
		/// </summary>
		/// <param name="mat1"></param>
		/// <returns></returns>
		matlab<T>& operator=(const matlab<T>& mat1)
		{
			if (this != &mat1)
			{
				_n = mat1._n;
				_m = mat1._m;
				_name = mat1._name;
				_arr.resize(_n + 1);
				for (int i = 0; i <= _n; i++)
				{
					_arr[i].resize(_m + 1);
					for (int j = 0; j <= _m; j++)
					{
						_arr[i][j] = mat1._arr[i][j];
					}
				}
			}
			return *this;
		}

		/// <summary>
		/// ��ȡ�����������
		/// </summary>
		/// <returns></returns>
		int lin()
		{
			return _n;
		}

		/// <summary>
		/// ��ȡ����ĵ� n ��, ����һ���о���
		/// </summary>
		/// <param name="n"></param>
		/// <returns></returns>
		matlab<T> lin(int n)
		{
			matlab<T> mat1(1, _m);
			for (int i = 1; i <= _m; i++)
			{
				mat1(1, i) = (*this)(n, i);
			}
			return mat1;
		}

		/// <summary>
		/// �Ѿ��� mat1 ��ֵ��ֵ����ǰ����ĵ� n �У�
		/// </summary>
		/// <param name="n"></param>
		/// <param name="mat1"></param>
		void lin(int n, matlab<T>& mat1)
		{
			for (int i = 1; i <= _m; i++)
			{
				(*this)(n, i) = mat1(1, i);
			}
		}


		/// <summary>
		/// ��ȡ���������� arr ���е�ĳ����,�����Ǽ��еľ���
		/// </summary>
		/// <param name="arr"></param>
		/// <returns></returns>
		matlab<T> lin(vector<int>& arr)
		{
			int n = arr.size();
			matlab<T> mat1(n, _m);
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= _m; j++)
				{
					mat1(i, j) = (*this)(arr[i - 1], j);
				}
			}
			return mat1;
		}

		/// <summary>
		/// �Ѿ��� mat1 ��ֵ��ֵ����ǰ���� arr ���鵱�е�ĳ���У�
		/// </summary>
		/// <param name="arr"></param>
		/// <param name="mat1"></param>
		void lin(vector<int>& arr, matlab<T>& mat1)
		{
			int n = arr.size();
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= _m; j++)
				{
					(*this)(arr[i - 1], j) = mat1(i, j);
				}
			}
		}

		/// <summary>
		/// ��ȡ�����������
		/// </summary>
		/// <returns></returns>
		int col()
		{
			return _m;
		}

		/// <summary>
		/// ��ȡ����ĵ� m ��, ����һ���о���
		/// </summary>
		/// <param name="m"></param>
		/// <returns></returns>
		matlab<T> col(int m)
		{
			matlab<T> mat1(_n, 1);
			for (int i = 1; i <= _n; i++)
			{
				mat1(i, 1) = (*this)(i, m);
			}
			return mat1;
		}

		/// <summary>
		/// �Ѿ��� mat1 ��ֵ��ֵ����ǰ����ĵ� n �У�
		/// </summary>
		/// <param name="m"></param>
		/// <param name="mat1"></param>
		void col(int m, matlab<T>& mat1)
		{
			for (int i = 1; i <= _n; i++)
			{
				(*this)(i, m) = mat1(i, 1);
			}
		}

		/// <summary>
		/// ��ȡ���������� arr ���е�ĳ����,�����Ǽ��еľ���
		/// </summary>
		/// <param name="arr"></param>
		/// <returns></returns>
		matlab<T> col(vector<int>& arr)
		{
			int m = arr.size();
			matlab<T> mat1(_n, m);
			for (int i = 1; i <= _n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					mat1(i, j) = (*this)(i, arr[j - 1]);
				}
			}
			return mat1;
		}

		/// <summary>
		/// �Ѿ��� mat1 ��ֵ��ֵ����ǰ���� arr ���鵱�е�ĳ���У�
		/// </summary>
		/// <param name="arr"></param>
		/// <param name="mat1"></param>
		void col(vector<int>& arr, matlab<T>& mat1)
		{
			int m = arr.size();
			for (int i = 1; i <= _n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					(*this)(i, arr[j - 1]) = mat1(i, j);
				}
			}
		}

		/// <summary>
		/// ���ؾ���ĵ� n �У��� m �е�Ԫ�أ�
		/// </summary>
		/// <param name="n"></param>
		/// <param name="m"></param>
		/// <returns></returns>
		T& operator()(int n, int m)
		{
			if (n > _n)
			{
				_arr.resize(n + 1);
				for (int i = _n + 1; i <= n; i++)
				{
					_arr[i].resize(_m + 1);
				}
				_n = n;
			}
			if (m > _m)
			{
				for (int i = 0; i <= _n; i++)
				{
					_arr[i].resize(m + 1);
				}
				_m = m;
			}
			return _arr[n][m];
		}

		/// <summary>
		/// ��ȡ���������� arr1 ���е�ĳ���к� arr2 ���е�ĳ����,������һ���¾���
		/// </summary>
		/// <param name="arr1"></param>
		/// <param name="arr2"></param>
		/// <returns></returns>
		matlab<T> operator()(vector<int>& arr1, vector<int>& arr2)
		{
			int n = arr1.size();
			int m = arr2.size();
			matlab<T> mat1(n, m);
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					mat1(i, j) = (*this)(arr1[i - 1], arr2[j - 1]);
				}
			}
			return mat1;
		}

		/// <summary>
		/// �Ѿ��� mat1 ��ֵ��ֵ����ǰ����� arr1 ��ĳЩ�к� arr2 ��ĳЩ�У�
		/// </summary>
		/// <param name="arr1"></param>
		/// <param name="arr2"></param>
		/// <param name="mat1"></param>
		void operator()(vector<int>& arr1, vector<int>& arr2, matlab<T>& mat1)
		{
			int n = arr1.size();
			int m = arr2.size();
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					(*this)(arr1[i - 1], arr2[j - 1]) = mat1(i, j);
				}
			}
		}

		/// <summary>
		/// ��ӡ����
		/// </summary>
		void print()
		{
			cout << "\n\n����� ������" << _n << " ������" << _m << "\n\n";
			cout << "\t" << _name << "=\n\n";
			for (int i = 1; i <= _n; i++)
			{
				cout << "�� " << i << " ��" << "\t  ";
				for (int j = 1; j <= _m; j++)
				{
					cout << (*this)(i, j) << "\t";
				}
				cout << "\n\n";
			}
		}

		/// <summary>
		/// ���� 15 λС�� ��ӡ����
		/// </summary>
		void print_15()
		{
			cout << "\n\n����� ������" << _n << " ������" << _m << "\n\n";
			cout << "\t" << _name << "=\n\n";
			for (int i = 1; i <= _n; i++)
			{
				cout << "�� " << i << " ��" << "\t  ";
				for (int j = 1; j <= _m; j++)
				{
					printf("%.15f\t", (*this)(i, j));
				}
				cout << "\n\n";
			}
		}

		/// <summary>
		/// ���� 6 λС�� ��ӡ����
		/// </summary>
		void print_6()
		{
			cout << "\n\n����� ������" << _n << " ������" << _m << "\n\n";
			cout << "\t" << _name << "=\n\n";
			for (int i = 1; i <= _n; i++)
			{
				cout << "�� " << i << " ��" << "\t  ";
				for (int j = 1; j <= _m; j++)
				{
					printf("%.6f\t", (*this)(i, j));
				}
				cout << "\n\n";
			}
		}

		/// <summary>
		/// ��ͨ��ӡ����
		/// </summary>
		void print_double()
		{
			cout << "\n\n\t" << _name << "=\n\n";
			for (int i = 1; i <= _n; i++)
			{
				cout << "\t";
				for (int j = 1; j <= _m; j++)
				{
					cout << (*this)(i, j) << "\t";
				}
				cout << "\n\n";
			}
		}

		/// <summary>
		/// ���� 15 λС�� ��ӡ����
		/// </summary>
		void print_15_double()
		{
			cout << "\n\n\t" << _name << "=\n\n";
			for (int i = 1; i <= _n; i++)
			{
				cout << "\t";
				for (int j = 1; j <= _m; j++)
				{
					printf("%.15f\t", (*this)(i, j));
				}
				cout << "\n\n";
			}
		}

		/// <summary>
		/// ���� 6 λС�� ��ӡ����
		/// </summary>
		void print_6_double()
		{
			cout << "\n\n\t" << _name << "=\n\n";
			for (int i = 1; i <= _n; i++)
			{
				cout << "\t";
				for (int j = 1; j <= _m; j++)
				{
					printf("%.6f\t", (*this)(i, j));
				}
				cout << "\n\n";
			}
		}

		/// <summary>
		/// ��ǰ���������;���ʱ��ת��Ϊ�����;��󣬷���һ�������;���
		/// </summary>
		/// <returns></returns>
		matlab<double> to_double()
		{
			matlab<double>d;
			d(_n, _m);
			for (int i = 0; i <= _n; i++)
			{
				for (int j = 0; j <= _m; j++)
				{
					d(i, j) = _arr[i][j];
				}
			}
			return d;
		}

		/// <summary>
		///����ֵ�;���������:
		/// </summary>
		/// <param name="arr"></param>
		/// <returns></returns>
		matlab<double> inv()
		{
			matlab<double> mat0;
			int n = _n;
			if (_n != _m || _n == 0)
			{
				cout << "\n\t��ǰ��������ֵ���󣡲����棺\n";
				return mat0;
			}
			matlab<double> mat1;
			string s = typeid((*this)(0, 0)).name();
			if (s != "int" && s != "double")
			{
				cout << "\n\t��ǰ��������ֵ���󣡲����棺\n";
				return mat0;
			}
			mat1 = (*this).to_double();
			matlab<double> mat2(n, n, 0);
			int i = 0, j = 0, c = 0;
			for (i = 1; i <= n; i++)
				{
					mat2(i, i) = 1;
				}
			for (i = 1; i <= n; i++)
				{
					if (mat1(i, i) == 0)
					{
						int k = 0;
						for (k = i + 1; k <= n; k++)
						{
							if (mat1(k, i) != 0)
								break;
						}
						if (k == n + 1)
						{
							cout << "\n\t��ǰ��������Ч���󣡲����棺\n";
							return mat0;
						}
						matlab<double> d1;
						matlab<double> d2;
						d1 = mat2.lin(i);
						d2 = mat2.lin(k);
						mat2.lin(i, d2);
						mat2.lin(k, d1);
						d1 = mat1.lin(i);
						d2 = mat1.lin(k);
						mat1.lin(i, d2);
						mat1.lin(k, d1);
					}
					for (j = 1; j <= n; j++)
					{
						if (j == i)
							continue;
						double a = mat1(j, i) * 1.0 / mat1(i, i);
						for (c = 1; c <= n; c++)
						{
							mat1(j, c) -= a * mat1(i, c);
							mat2(j, c) -= a * mat2(i, c);
						}
					}
				}
			for (i = 1; i <= n; i++)
				{
					for (j = 1; j <= n; j++)
					{
						mat2(i, j) /= mat1(i, i);
					}
				}
			return mat2;
		}

		/// <summary>
		/// ����ֵ�;��������ʽ:
		/// </summary>
		/// <returns></returns>
		T det()
		{
			matlab<double> mat0;
			int n = _n;
			if (n != _m || n == 0)
			{
				cout << "\n\t��ǰ��������Ч����\n";
				return 0;
			}
			string s = typeid((*this)(0, 0)).name();
			matlab<double> mat1;
			if (s != "int" && s != "double")
			{
				cout << "\n\t��ǰ��������ֵ����\n";
				return 0;
			}
			mat1 = (*this).to_double();
			int i = 0, j = 0, c = 0;
			for (i = 1; i <= n; i++)
			{
				if (mat1(i, i) == 0)
				{
					int k = 0;
					for (k = i + 1; k <= n; k++)
					{
						if (mat1(k, i) != 0)
							break;
					}
					if (k == n + 1)
					{
						return 0;
					}
					matlab<double> d1;
					matlab<double> d2;
					d1 = mat1.lin(i);
					d2 = mat1.lin(k);
					mat1.lin(i, d2);
					mat1.lin(k, d1);
				}
				for (j = i + 1; j <= n; j++)
				{
					double a = mat1(j, i) * 1.0 / mat1(i, i);
					for (c = 1; c <= n; c++)
					{
						mat1(j, c) -= a * mat1(i, c);
					}
				}
			}
			double d = 1;
			for (i = 1; i <= n; i++)
			{
				d *= mat1(i, i);
			}
			return d;
		}

		/// <summary>
		/// ���ؾ����ת�þ���
		/// </summary>
		/// <returns></returns>
		matlab<T> transpose()
		{
			matlab<T> mat1(_m, _n);
			for (int i = 0; i <= _m; i++)
			{
				for (int j = 0; j <= _n; j++)
				{
					mat1(i, j) = (*this)(j, i);
				}
			}
			return mat1;
		}

		/// <summary>
		/// ����ĳ˷���������أ�
		/// </summary>
		/// <param name="mat1"></param>
		/// <returns></returns>
		matlab<T> operator*(matlab<T> mat1)
		{
			matlab<T> mat2;
			if (_m != mat1._n)
			{
				cout << "\n\t�����������������Ҿ����������\n";
				return mat2;
			}
			mat2(_n, mat1._m);
			for (int i = 1; i <= _n; i++)
			{
				for (int j = 1; j <= mat1._m; j++)
				{
					mat2(i, j) = 0;
					for (int k = 1; k <= _m; k++)
					{
						mat2(i, j) += (*this)(i, k) * mat1(k, j);
					}
				}
			}
			return mat2;
		}

		/// <summary>
		/// ����ļӷ���������أ�
		/// </summary>
		/// <param name="mat1"></param>
		/// <returns></returns>
		matlab<T> operator+(matlab<T> mat1)
		{
			matlab<T> mat2;
			if (_n != mat1._n || _m != mat1._m)
			{
				cout << "\n\t�������������������Ҿ������������\n";
				return mat2;
			}
			mat2(_n, _m);
			for (int i = 1; i <= _n; i++)
			{
				for (int j = 1; j <= mat1._m; j++)
				{
					mat2(i, j) = (*this)(i, j) + mat1(i, j);
				}
			}
			return mat2;
		}

		/// <summary>
		/// ����ļ�����������أ�
		/// </summary>
		/// <param name="mat1"></param>
		/// <returns></returns>
		matlab<T> operator-(matlab<T> mat1)
		{
			matlab<T> mat2;
			if (_n != mat1._n || _m != mat1._m)
			{
				cout << "\n\t�������������������Ҿ������������\n";
				return mat2;
			}
			mat2(_n, _m);
			for (int i = 1; i <= _n; i++)
			{
				for (int j = 1; j <= mat1._m; j++)
				{
					mat2(i, j) = (*this)(i, j) - mat1(i, j);
				}
			}
			return mat2;
		}

		/// <summary>
		/// �����ָ����������أ�
		/// </summary>
		/// <param name="mat1"></param>
		/// <returns></returns>
		matlab<double> operator^(int n)
		{
			matlab<T> mat2;
			matlab<double> mat3;
			if (_n != _m || _n == 0)
			{
				cout << "\n\t����������Ч����\n";
				return mat3;
			}
			mat2(_n, _n);
			for (int i = 1; i <= _n; i++)
			{
				mat2(i, i) = 1;
			}
			for (int i = 1; i <= abs(n); i++)
			{
				mat2 = mat2 * (*this);
			}
			if (n < 0)
				return mat2.inv();
			for (int i = 1; i <= _n; i++)
			{
				for (int j = 1; j <= _n; j++)
				{
					mat3(i, j) = mat2(i, j);
				}
			}
			return mat3;
		}

		/// <summary>
		/// ���������ֵĳ˷���������أ�
		/// </summary>
		/// <param name="mat1"></param>
		/// <returns></returns>
		matlab<double> operator*(double d)
		{
			matlab<double> mat2;
			mat2(_n, _m);
			for (int i = 1; i <= _n; i++)
			{
				for (int j = 1; j <= _m; j++)
				{
					mat2(i, j) = d * (*this)(i, j);
				}
			}
			return mat2;
		}

		/// <summary>
		/// �������
		/// </summary>
		void input()
		{
			string s = typeid(_arr[0][0]).name();
			cout << "\n\n�������������";
			cin >> _name;
			while(getchar()!=10){}
			cout << "\n\n�������������: L=";
			int L = 0;
			scanf("%d", &L);
			while (L<1)
			{
				while (getchar() != 10) {}
				cout << "\n\n\t�������\n\n\t������һ������0��������L=";
				scanf("%d", &L);
			}
			while (getchar() != 10) {}
			cout << "\n\n�������������: C=";
			int C = 0;
			scanf("%d", &C);
			while (C < 1)
			{
				while (getchar() != 10) {}
				cout << "\n\n\t�������\n\n\t������һ������0��������C=";
				scanf("%d", &C);
			}
			while (getchar() != 10) {}
			(*this)(L, C);
			cout << "\n\t1 ָ��ĳһ��ĳһ������\n\n\t2 ��������ÿ��Ԫ��\n\n��ѡ�����ľ������뷽ʽ:";
			int m = 0;
			scanf("%d", &m);
			while (m != 1 && m != 2)
			{
				while (getchar() != 10) {}
				cout << "\n\n\t�������\n\n\t������ 1 ���� 2 ��������";
				scanf("%d", &m);
			}
			while (getchar() != 10) {}
			if (m == 1)
			{
				cout << "\n������һ��Ҫ���뼸��Ԫ�أ�";
				int k = 0;
				scanf("%d", &k);
				while (k<1 || k>L * C)
				{
					while (getchar() != 10) {}
					cout << "\n\n\t�������\n\n\t������һ�� 1-" << L * C << "��������";
					scanf("%d", &k);
				}
				while (getchar() != 10) {}
				for (int i = 1; i <= k; i++)
				{
					cout << "\n��" << i << "��Ҫ�����Ԫ�ص� ������ row=";
					int row = 0;
					scanf("%d", &row);
					while (row<1 || row>L)
					{
						while (getchar() != 10) {}
						cout << "\n\n\t�������\n\n\t������һ�� 1-" << L << "��������row=";
						scanf("%d", &row);
					}
					while (getchar() != 10) {}
					cout << "\n��" << i << "��Ҫ�����Ԫ�ص� ������ col=";
					int col = 0;
					scanf("%d", &col);
					while (col<1 || col>C)
					{
						while (getchar() != 10) {}
						cout << "\n\n\t�������\n\n\t������һ�� 1-" << C << "��������col=";
						scanf("%d", &col);
					}
					while (getchar() != 10) {}
					cout << "\n��" << i << "��Ҫ�����Ԫ�ص�ֵ�� "<<_name<<"(" << row << ", " << col << ") = ";
					if (s != "int" && s != "double"&&s!="float")
					{
						cin >> (*this)(row, col);
						while(getchar()!=10){}
					}
					else
					{
						double d = -0.0000000000000000001;
						scanf("%lf", &d);
						while (d == -0.0000000000000000001)
						{
							while (getchar() != 10) {}
							cout << "\n\n\t�������\n\n\t������һ��ʵ��: " << _name << "(" << row << ", " << col << ") = ";
							scanf("%d", &d);
						}
						while (getchar() != 10) {}
						(*this)(row, col) = d;
					}
				}
			}
			else
			{
				cout << "\n����������ÿ��Ԫ�ص�ֵ��\n\n\t";
				if (s == "int" || s == "double" || s == "float")
				{
					double d = -0.0000000000000000001;
					int a = 1;
					while (a)
					{
						a = 0;
						for (int i = 1; i <= L; i++)
						{
							for (int j = 1; j <= C; j++)
							{
								scanf("%lf", &d);
								if (d != -0.0000000000000000001)
								{
									(*this)(i, j) = d;
									d = -0.0000000000000000001;
								}
								else
								{
									while (getchar() != 10) {}
									cout << "��ʽ��������������:\n\n\t";
									a = 1;
									break;
								}
							}
							if (a == 1)
								break;
						}
					}
					while (getchar() != 10) {}
				}
				else
				{
					for (int i = 1; i <= L; i++)
					{
						for (int j = 1; j <= C; j++)
						{
							cin >> (*this)(i, j);
						}
					}
					while(getchar()!=10){}
				}
			}
			print();
		}
	};

	/// <summary>
	/// double���������˷���������أ�
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="d"></param>
	/// <param name="mat1"></param>
	/// <returns></returns>
	template<class T>
	matlab<double> operator*(double d, matlab<T> mat1)
	{
		matlab<double> mat2;
		mat2(mat1._n, mat1._m);
		for (int i = 1; i <= mat1._n; i++)
		{
			for (int j = 1; j <= mat1._m; j++)
			{
				mat2(i, j) = d * mat1(i, j);
			}
		}
		return mat2;
	}

	/// <summary>
	/// int���������˷���������أ�
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="d"></param>
	/// <param name="mat1"></param>
	/// <returns></returns>
	template<class T>
	matlab<double> operator*(int d, matlab<T> mat1)
	{
		matlab<double> mat2;
		mat2(mat1._n, mat1._m);
		for (int i = 1; i <= mat1._n; i++)
		{
			for (int j = 1; j <= mat1._m; j++)
			{
				mat2(i, j) = d * mat1(i, j);
			}
		}
		return mat2;
	}

	void main_space();

	void menu();

	void det();

	void inv();

	void add();

	void mul();

	void sub();

	void index();

	void dia();

	matlab<double> mat_solve(string str);

	vector<string> fen_ge_str(string str);

	vector<string> fen_ge_str_1(string str);

	vector<string> mid_convert_beh(vector<string>& arr);

	matlab<double> solve_beh(vector<string>& arr);

	matlab<double> solve(vector<string>& arr);

	matlab<double> solve_str(string str);

	matlab<double> mat_solve_1(string str);

	void print_mat(matlab<double> mat1);
}

