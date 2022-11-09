#include <vector>
#include <iostream>


class Vec{
  public:
    std::vector<double> value;


    double operator^(Vec second_vec) { //скалярное произведение
        int n = value.size();

        if (n != second_vec.value.size()){

          std::runtime_error("Incorrect vec concatenation");

        } else {

            int concat = 0;

            for (int i=0; i<n; i++){
              concat += value[i] * second_vec.value[i];
            }

            return concat;
            }
          }

    Vec operator*(double val) { //умножение на число
        int n = value.size();
        std::vector<double> new_value;

        for (int i=0; i<n; i++){
          new_value.push_back(value[i] * val);
        }

        Vec new_vec;
        new_vec.value = new_value;
        return new_vec;

      }


    Vec operator*(Vec second_vec) { // умножение на вектор поэлементно
        int n = value.size();

        if (n != second_vec.value.size()){

          std::runtime_error("Incorrect vec concatenation");

        } else {

            std::vector<double> new_value;

            for (int i=0; i<n; i++){
              new_value.push_back(value[i] * second_vec.value[i]);
            }

            Vec new_vec;
            new_vec.value = new_value;
            return new_vec;
            }
          }

    int operator[](int i) {return value[i];}

    Vec operator+(Vec second_vec) {
        int n = value.size();

        if (n != second_vec.value.size()){

          std::runtime_error("Incorrect vec concatenation");

        } else {

            std::vector<double> new_value;

            for (int i=0; i<n; i++){
              new_value.push_back(value[i] + second_vec.value[i]);
            }

            Vec new_vec;
            new_vec.value = new_value;
            return new_vec;
            }
          }


    Vec operator-(Vec second_vec) { // умножение на вектор поэлементно
        int n = value.size();

        if (n != second_vec.value.size()){

          std::runtime_error("Incorrect vec concatenation");

        } else {

            std::vector<double> new_value;

            for (int i=0; i<n; i++){
              new_value.push_back(value[i] - second_vec.value[i]);
            }

            Vec new_vec;
            new_vec.value = new_value;
            return new_vec;
            }
          }

    friend std::ostream& operator<< (std::ostream &out, const Vec &vec);

    friend std::ostream& operator>> (std::ostream &cin, Vec &vec);

};


class Matrix{
  public:

  std::vector<std::vector<double>> value;


  Matrix operator+(Matrix second_table) {
      int n = value.size(); // высота матрицы
      int m = value[0].size(); // длина
      if (n != second_table.value.size() | m != second_table.value[0].size()){
        std::runtime_error("Incorrect sum"); // корректрность сложения
      } else {
          std::vector<std::vector<double>> new_value = {};
          std::vector<double> new_line;
          for (int i=0; i<n; i++){
            new_line = {};
            for (int j=0; j<m; j++){
              new_line.push_back(value[i][j] + second_table.value[i][j]);
            }
            new_value.push_back(new_line);
          }

          Matrix new_matrix;
          new_matrix.value = new_value;
          return new_matrix;
          }
        }


    Matrix operator * (Matrix second_table) {
        int n = value.size(); // высота матрицы
        int m = value[0].size(); // длина
        if (m != second_table.value[0].size()){
          std::runtime_error("Incorrect mat concatenation");
        } else {
            std::vector<std::vector<double>> new_value = {};
            std::vector<double> new_line;
            for (int i=0; i<n; i++){
              new_line = {};
              for (int j=0; j<m; j++){
                double tmp = 0;
                for (int k=0; k<m; k++){
                  tmp += value[i][k] * second_table.value[k][j];
                }
                new_line.push_back(tmp);
              }
              new_value.push_back(new_line);
            }

            Matrix new_matrix;
            new_matrix.value = new_value;
            return new_matrix;
            }
      }


    friend std::ostream& operator<< (std::ostream &out, const Matrix &matrix);
};


std::ostream& operator<< (std::ostream &out, const Matrix &matrix)
{
  int n = matrix.value.size(); // высота матрицы
  int m = matrix.value[0].size(); // длина
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        out << matrix.value[i][j] << ' ';
      }
      out << '\n';
    }
    return out;
}

std::ostream& operator<< (std::ostream &out, const Vec &vec)
{
  int n = vec.value.size();

    for (int i=0; i<n; i++){
      out << vec.value[i] << ' ';
    }
    return out;
}


std::istream& operator>> (std::istream& cin, Vec &vec)
{
  std::string s;
  getline(cin, s);
  if (s[s.length() - 1] != '.')
        s += '.';

  std::string  tmp;
  std::vector<std::string> vs;
  for (int i = 0; i < s.length(); i++)
  {
      if (s[i] == ' ' || s[i] == '.')
      {
          vs.push_back(tmp);
          tmp.clear();
      }
      else
          tmp += s[i];
  }

  std::vector<double> new_value;

  for (int i = 0; i < vs.size(); i++) {
    new_value.push_back(std::stod(vs[i]));
  }

  vec.value = new_value;
  return cin;
}





int main() {
  Matrix M_1;
  M_1.value = {{1, 2}, {3, 4}};

  Matrix M_2;
  M_2.value = {{3, 4}, {1, 2}};

  std::cout << M_1 * M_2;
  std::cout << '\n';
  std::cout << M_1 + M_2;
  std::cout << '\n';


  Vec v_1;
  Vec v_2;
  Vec v;
  double d;
  v_1.value =  {1, 2, 3};
  v_2.value =  {3, 4, 5};
  std::cout << v_1 * v_2 << '\n';
  d = v_1 ^ v_2;
  std::cout << d << '\n';
  std::cout << v_1 + v_2 << '\n';
  std::cout << v_1 - v_2 << '\n';


  std::cin >> v;
  std::cout << v << '\n';
  return 0;
}
