#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>

template <typename DataType>
class Matriz
{
    /*vector vertical filas -> vector horizontal columnas*/
    using RowType = std::vector<DataType>; //typedef
    using MatrizType = std::vector<RowType>;

    MatrizType data{};

    std::size_t Rows{};
    std::size_t Columns{};

public:
    Matriz();
    Matriz(const std::size_t& rows,const std::size_t& cols);

    const RowType& operator[](unsigned rowIndex) const{return data[rowIndex];};
    RowType& operator[](unsigned rowIndex){return data[rowIndex];};

};

template <typename DataType>
Matriz<DataType>::Matriz():
    data{MatrizType(0, RowType(0,{}))}, Rows{},Columns{}
//data{MatrizType(Rows, RowType(Columns,{}))}
{

}

template <typename DataType>
Matriz<DataType>::Matriz(const std::size_t& rows,const std::size_t& cols):
    data{MatrizType(rows, RowType(cols,DataType{}))},Rows{rows},Columns{cols}
  //data{MatrizType(rows, RowType(cols,{}))}
{

}


#endif // MATRIZ_H
