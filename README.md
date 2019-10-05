# matrix-class-template
Simple matrix class template in C++

* 3 dimensional
* reach by single component index
* reach by 3 component coordinate
* ROI copy and paste

# Usage

```cpp
	// create a matrix size of 12x12 and depth of 1
	aek::Mat<unsigned char> mat0(12,12,1);
	
	// print the size of a matrix in sense of width x height x depth
	std::cout << mat0.getSize() << std::endl;
	

	// set individual elements by coordinate
	mat0.setElement(5, 5, 0, 65);
	mat0.setElement(5, 6, 0, 66);
	mat0.setElement(6, 5, 0, 67);
	mat0.setElement(6, 6, 0, 68);
	
	// print individual element by coordinate
	std::cout << mat0.getElement(5, 5, 0) << std::endl;
	
	// set individual element by index
	mat0.setElement(123, 66);
	
	// print individual element by index
	std::cout << mat0.getElement(123) << std::endl;


	// copy a roi from a mat and store it in another mat
	aek::Mat<unsigned char> mat1 = mat0.copy(5, 5, 0, 2, 2, 1);
	
	// paste a roi mat into another mat
	mat0.paste(0, 0, 0, mat1);
	
	// print pasted elements one by one
	std::cout << (int)mat0.getElement(0, 0, 0) << std::endl;
	std::cout << (int)mat0.getElement(0, 1, 0) << std::endl;
	std::cout << (int)mat0.getElement(1, 0, 0) << std::endl;
	std::cout << (int)mat0.getElement(1, 1, 0) << std::endl;

	
	// create with data
	int data[] = { 1,2,3,4 };
	aek::Mat<int> mat2(2, 2, 1, data);
	std::cout << mat2.getElement(0, 0, 0) << std::endl;
	std::cout << mat2.getElement(1, 0, 0) << std::endl;
	std::cout << mat2.getElement(0, 1, 0) << std::endl;
	std::cout << mat2.getElement(1, 1, 0) << std::endl;
```
