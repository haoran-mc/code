#include <cstdio>
#define maxn 100
typedef int Status;
#define STRINGSIZE 100
#define INCREASEMENTSTRING 10
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2
struct Triple{
    int i;
    int j;
    int Elem;
};

class TripleMatrix{
    private:
        Triple data[maxn];
        int rows;
        int cols;
        int zero;
        int cont;
    public:
        TripleMatrix();
        TripleMatrix(int x, int y, int z);
        ~TripleMatrix();
        int getElem(int row, int col);
        Status setElem(int row, int col, int Elem);
        void printTriple();
        void printMatrix();
        friend Status transpose(TripleMatrix triple, TripleMatrix &pose);
        friend Status Transpose(TripleMatrix triple, TripleMatrix &pose);
        friend bool matrixAdd(TripleMatrix a, TripleMatrix b, TripleMatrix &res);
        friend bool matrixMulty(TripleMatrix a, TripleMatrix b, TripleMatrix &res);
};

/*构造函数，初始化矩阵的行数、列数和非零元个数*/
TripleMatrix::TripleMatrix() {
    rows = 0;
    cols = 0;
    zero = 0;
}

/*构造函数，初始化矩阵的行数、列数和非零元个数*/
TripleMatrix::TripleMatrix(int x, int y, int z) {
    rows = x;
    cols = y;
    zero = z;
    cont = 1;
}

/*析构函数*/
TripleMatrix::~TripleMatrix() {

}

/*根据行号、列号获得稀疏矩阵元素的值*/
int TripleMatrix::getElem(int row, int col) {
    if (row > rows || col > cols)
        return 0;

    for (int i = 1; i <= zero; ++i)
        if (data[i].i == row && data[i].j == col)
            return data[i].Elem;

    return 0;
}

/*插入非零元*/
Status TripleMatrix::setElem(int row, int col, int Elem) {
    if (row > rows || col > cols)
        return ERROR;
    if (zero == maxn)
        return ERROR;
    if (Elem == 0)
        return OK;

    int index = 1;
    while (index < cont) {
        if (row > data[index].i)
            ++index;
        else if (row == data[index].i && col > data[index].j)
            ++index;
        else
            break;
    }

    if ((row == data[index].i) && (col == data[index].j))
        data[index].Elem = Elem;
    else {
        /*插入元素，原数据后移*/
        for (int i = cont; i > index; --i) {
            data[i].i = data[i-1].i;
            data[i].j = data[i-1].j;
            data[i].Elem = data[i-1].Elem;
        }
        data[index].i = row;
        data[index].j = col;
        data[index].Elem = Elem;
    }
    ++cont;
    return OK;
}

/*以三元组的方式打印出矩阵*/
void TripleMatrix::printTriple() {
    printf("print triple:\n");
    //printf("row\\col\\Elem\n");
    for (int i = 1; i <= zero; ++i)
        printf("%4d%4d%4d\n", data[i].i, data[i].j, data[i].Elem);
}

/*以矩阵的方式打印出矩阵*/
void TripleMatrix::printMatrix() {
    int Triidx = 1;
    //printf("print matrix:\n");
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            if (i == data[Triidx].i && j == data[Triidx].j)
                printf("%4d", data[Triidx++].Elem);
            else
                printf("%4d", 0);
        }
        printf("\n");
    }
    //printf("matrix's row: %d\t\t", rows);
    //printf("matrix's col: %d\n", cols);
}

/*输入三元组*/
void inputTriple(int zero, TripleMatrix &triple) {
    int row;
    int col;
    int Elem;
    for (int i = 1; i <= zero; ++i) {
        printf("input row, col and Elem: ");
        scanf("%d", &row);
        scanf("%d", &col);
        scanf("%d", &Elem);
        if (Elem != 0) {
            if (triple.setElem(row, col, Elem) == ERROR) {
                printf("ERROR!\n");
                break;
            }
        }
    }
}

void inputMatrix(int rows, int cols, TripleMatrix &triple) {
    int Elem;
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            scanf("%d", &Elem);
            if (triple.setElem(i, j, Elem) == ERROR) {
                printf("ERROR!\n");
                break;
            }
        }
    }
}

/*稀疏矩阵的加法*/
bool matrixAdd(TripleMatrix matrix1, TripleMatrix matrix2, TripleMatrix &sum) {
    if (matrix1.rows != matrix2.rows || matrix2.rows != sum.rows || matrix1.cols != matrix2.cols || matrix2.cols != sum.cols)
        return false;
    else {
        for (int i = 1; i <= matrix1.rows; ++i) {
            for (int j = 1; j <= matrix1.cols; ++j) {
                int Elem = matrix1.getElem(i, j) + matrix2.getElem(i, j);
                if (Elem != 0)
                    sum.setElem(i, j, Elem);
            }
        }
        return true;
    }
}

/*稀疏矩阵的乘法*/
bool matrixMulty(TripleMatrix matrix1, TripleMatrix matrix2, TripleMatrix &prod) {
    if (matrix1.cols != matrix2.rows)
        return false;

    prod.rows = matrix1.rows;
    prod.cols = matrix2.cols;

    for (int i = 1; i <= matrix1.rows; ++i) {
        for (int j = 1; j <= matrix2.cols; ++j) {
            int sum = 0;
            for (int k = 1; k <= matrix1.cols; ++k)
                if (matrix1.getElem(i, k) && matrix2.getElem(k, j))
                    sum += matrix1.getElem(i, k) * matrix2.getElem(k, j);
            if (sum)
                prod.setElem(i, j, sum);
        }
    }
    return true;
}

Status Transpose(TripleMatrix triple, TripleMatrix &pose) {
    pose.rows = triple.cols;
    pose.cols = triple.rows;
    pose.zero = triple.zero;
    int q;
    if (triple.zero) {
        q = 1;
        for (int col = 1; col <= triple.cols; ++col)
            for (int p = 1; p <= triple.zero; ++p)
                if (triple.data[p].j == col) {
                    pose.data[q].i = triple.data[p].j;
                    pose.data[q].j = triple.data[p].i;
                    pose.data[q].Elem = triple.data[p].Elem;
                    ++q;
                }
    }
    return OK;
}

int main()
{
    printf("Please input the Matrix:\n");
    TripleMatrix triple(2, 3, 6);
    TripleMatrix pose(3, 2, 6);
    inputMatrix(2, 3, triple);
    Transpose(triple, pose);
    printf("\n");
    triple.printMatrix();
    printf("\n");
    pose.printMatrix();
    return 0;
}
