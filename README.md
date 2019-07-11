# Third Semester C++ Programming

Tasks from the laboratory: [__Programming II__](https://usosweb.umk.pl/kontroler.php?_action=katalog2/przedmioty/pokazPrzedmiot&kod=1000-I1PR2).

Tasks come from [ZawodyWeb](https://www.mat.umk.pl:8070/ZawodyWeb) or they are additionally asked by the lecturer. 
Many tasks come from the [UVa](https://uva.onlinejudge.org) website.

I used the __functional__ and __objected-oriented programming__ paradigm and the __C++14__ standard.

---

### Issues doscussed during the course:

- the concept of class, object, method
- constructors and destructors
- getters and setters
- overloading operators and methods
- friend functions and class
- inheritance
- virtual classes and methods
- polimorphism
- templates
- STL

---

## Matrix calculator

As a semester project, I created `Matrix` class with templates, overloading operators, which can use rational numbers, complex numbers, rings of integers and primitive types - integers, doubles and floats. You can also perform operations on square matrices.

Supports operations:
- [transpose](https://en.wikipedia.org/wiki/Transpose) operation
- bringing to [row echelon form](https://en.wikipedia.org/wiki/Row_echelon_form)
- on rows and columns: 
  - swap
  - adding and subtracting one to another
  - multiply one by number
- overloading operators: `+`, `+=`, `-`, `-=`, `*` (with other `Matrix<T>` or with `T` type), `==`, `!=`, `<<`, `>>`
- additionally for `SquareMatrix`:
  - calculation of the [determinant](https://en.wikipedia.org/wiki/Determinant)
  - calculation of the [algebraic complement matrix](http://mathworld.wolfram.com/Cofactor.html)
  - calculation of the [inverse matrix](https://en.wikipedia.org/wiki/Invertible_matrix)
