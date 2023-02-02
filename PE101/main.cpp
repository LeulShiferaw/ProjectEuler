/*
    Solved using matrix
    inverse matrix of(n^k, n^(k-1), ... 1) from 1 to q for n
    multiply with matrix(f(1), f(2), ... f(n))^T 
    this will find the coefficient matrix
    then just find the last+1 element to find the first different one(this is an assumption)
*/
#include <cmath>
#include <vector>
#include <chrono>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using boost::multiprecision::cpp_int;
using boost::multiprecision::cpp_dec_float_50;

class Matrix
{
    private:
        vector<vector<cpp_dec_float_50>> mat;
    public:
        Matrix();
        Matrix(int, int);
        cpp_dec_float_50 get(int, int);
        void set(int, int, const cpp_dec_float_50&);
        void set(const vector<vector<cpp_dec_float_50>> &);
        void display();

        cpp_dec_float_50 det();
        Matrix coFactorMat();
        Matrix inverse();
        void trans();
        vector<vector<cpp_dec_float_50>> subMatrix(int, int);
        friend Matrix mult(const Matrix &, const Matrix &);
        friend cpp_dec_float_50 poly(const Matrix &, const int &);
};

Matrix::Matrix()
{

}

Matrix::Matrix(int n, int m)
{
    vector<cpp_dec_float_50> row;
    for(int j = 0; j<m; ++j)
        row.push_back(0);

    for(int i = 0; i<n; ++i)
        mat.push_back(row);
}

cpp_dec_float_50 Matrix::get(int x, int y)
{
    if(x >= 0 && y >= 0 && x < mat.size() && y < mat[0].size())
        return mat[x][y];
    else throw -1; //Error
}

void Matrix::set(int x, int y, const cpp_dec_float_50 &val)
{
    if(x >= 0 && y >= 0 && x < mat.size() && y < mat[0].size())
        mat[x][y] = val;
    else throw -2;
}

void Matrix::set(const vector<vector<cpp_dec_float_50>> &m)
{
    mat = m;
}

cpp_dec_float_50 Matrix::det()
{
    if(mat.size() == 1 && mat[0].size() == 1)
    {
        return mat[0][0];
    }
    else if(mat.size() == 2 && mat[0].size() == 2)
    {
        return mat[0][0]*mat[1][1] - mat[1][0]*mat[0][1];
    }

    if(mat.size() != mat[0].size())
    {
        throw "Error";
    } 
    cpp_dec_float_50 res = 0;
    for(int i = 0; i<mat.size(); ++i)
    {
        Matrix temp;
        temp.set(subMatrix(0, i));
        cpp_dec_float_50 minor = temp.det();
        if(i%2 == 1)
            minor *= -1;
        res += mat[0][i]*minor;
    }
    return res;
}

Matrix Matrix::coFactorMat()
{
    Matrix res(mat.size(), mat[0].size());
    for(int i = 0; i<mat.size(); ++i)
    {
        for(int j = 0; j<mat[i].size(); ++j)
        {
            auto temp = subMatrix(i, j);
            Matrix tempM;
            tempM.set(temp);
            auto minor = tempM.det();
            if((i+j) % 2 == 1)
                minor *= -1;
            res.set(i, j, minor);
        }
    }
    return res;
}

Matrix Matrix::inverse()
{
    auto dt = det();
    if(dt == 0)
    {
        throw "Error";
    }
    auto cm = coFactorMat();
    for(int i = 0; i<mat.size(); ++i)
    {
        for(int j = 0; j<mat[i].size(); ++j)
        {
            cm.set(i, j, cm.get(i, j)/dt);
        }
    }
    cm.trans();
    return cm;
}

void Matrix::trans()
{
    for(int i = 0; i<mat.size(); ++i)
    {
        for(int j = i; j<mat.size(); ++j)
            swap(mat[i][j], mat[j][i]);
    }
}

vector<vector<cpp_dec_float_50>> Matrix::subMatrix(int x, int y)
{
    vector<vector<cpp_dec_float_50>> res;
    for(int i = 0; i<mat.size(); ++i)
    {
        if(i == x)
            continue;
        vector<cpp_dec_float_50> row;
        for(int j = 0; j<mat[i].size(); ++j)
        {
            if(j == y)
                continue;
            row.push_back(mat[i][j]); 
        }
        res.push_back(row);
    }
    return res;
}

Matrix mult(const Matrix &m1, const Matrix &m2)
{
    if(m1.mat[0].size() != m2.mat.size())
        throw "mult Error";
    Matrix res(m1.mat.size(), m2.mat[0].size());
    for(int i = 0; i<m1.mat.size(); ++i)
    {
        for(int j = 0;j<m2.mat[0].size(); ++j)
        {
            cpp_dec_float_50 curr = 0;
            for(int k = 0; k<m1.mat.size(); ++k)
            {
                curr += m1.mat[i][k]*m2.mat[k][j]; 
            }
            res.mat[i][j] = curr;
        }
    }
    return res;
}

void Matrix::display()
{
    for(int i = 0; i<mat.size(); ++i)
    {
        for(int j = 0; j<mat[i].size(); ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

Matrix generateMatrix(int n)
{
    vector<vector<cpp_dec_float_50>> res;
    for(int i = 0; i<n; ++i)
    {
        vector<cpp_dec_float_50> row;
        for(int j = 0; j<n; ++j)
            row.push_back(pow(i+1, n-1-j));
        res.push_back(row);
    }

    Matrix m;
    m.set(res);
    return m;
}

cpp_dec_float_50 poly(const Matrix &coeffMat, const int &x)
{
    cpp_dec_float_50 xn = x;
    cpp_dec_float_50 res = coeffMat.mat[coeffMat.mat.size()-1][0];
    for(int i = coeffMat.mat.size()-2; i>=0; --i)
    {
        res += xn*coeffMat.mat[i][0];
        xn*=x;
    }
    return res;
}

long long f(int n)
{
    long long res = 1;
    for(int i = 1; i<=10; ++i)
    {
        if(i%2 == 0)
            res += pow(n, i);
        else res -= pow(n, i);
    }
    return res;
}

int main()
{   
    try
    {
        int n = 10;
        cpp_dec_float_50 res = 1;
        for(int i = 2; i<=n; ++i)
        {
            vector<vector<cpp_dec_float_50>> resVec;
            for(int j = 1; j<=i; ++j)
            {
                resVec.push_back({f(j)});
            }

            Matrix leftSide = generateMatrix(i);
            leftSide = leftSide.inverse();
            
            Matrix rightSide;
            rightSide.set(resVec);

            Matrix coeffMat = mult(leftSide, rightSide);
            res += poly(coeffMat, i+1);//First one to not equal each other is the last+1 th element
        }
        cout << setprecision(numeric_limits<cpp_dec_float_50>::digits10) << res << endl;
    }
    catch(string str)
    {
        cerr << str << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...)
    {
        cout << "Error" << endl;
    }
    
       return 0;
}
