#pragma once
namespace aek {

	template<typename T>
	class Mat
	{
	private:
		int width;
		int height;
		int depth;
		T* data;
	public:
		~Mat();
		Mat();
		Mat(int _width, int _height, int _channel);
		Mat(int _width, int _height, int _channel, T* _data);

		int getWidth();
		int getHeight();
		int getDepth();
		int getSize();
		T* getData();

		int indexOf(int x, int y, int z);

		T getElement(int index);
		T getElement(int x, int y, int z);

		void setElement(int index, T value);
		void setElement(int x, int y, int z, T value);

		Mat<T> copy(int x, int y, int z, int w, int h, int d);
		void paste(int x, int y, int z, Mat<T> frame);

		void fill(T value);
	};

	template<typename T>
	inline Mat<T>::~Mat()
	{
		delete[]this->data;
	}

	template<typename T>
	Mat<T>::Mat()
	{
	}

	template<typename T>
	Mat<T>::Mat(int _width, int _height, int _channel)
	{
		this->width = _width;
		this->height = _height;
		this->depth = _channel;
		this->data = new T[this->getSize()];
	}

	template<typename T>
	inline Mat<T>::Mat(int _width, int _height, int _channel, T* _data)
	{
		this->width = _width;
		this->height = _height;
		this->depth = _channel;
		this->data = _data;
	}

	template<typename T>
	int Mat<T>::getWidth() {
		return this->width;
	}

	template<typename T>
	int Mat<T>::getHeight()
	{
		return this->height;
	}

	template<typename T>
	int Mat<T>::getDepth()
	{
		return this->depth;
	}

	template<typename T>
	int Mat<T>::getSize()
	{
		return this->getWidth() * this->getHeight() * this->getDepth();
	}

	template<typename T>
	inline T* Mat<T>::getData()
	{
		return this->data;
	}

	template<typename T>
	inline int Mat<T>::indexOf(int x, int y, int z)
	{
		return y * this->width * this->depth + x * this->depth + z;
	}

	template<typename T>
	inline T Mat<T>::getElement(int index)
	{
		return this->data[index];
	}

	template<typename T>
	inline T Mat<T>::getElement(int x, int y, int z)
	{
		return this->getElement(this->indexOf(x, y, z));
	}

	template<typename T>
	inline void Mat<T>::setElement(int index, T value)
	{
		this->data[index] = value;
	}

	template<typename T>
	inline void Mat<T>::setElement(int x, int y, int z, T value)
	{
		this->setElement(this->indexOf(x, y, z), value);
	}

	template<typename T>
	inline Mat<T> Mat<T>::copy(int x, int y, int z, int w, int h, int d)
	{
		Mat<T> res(w, h, d);
		T curr;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				for (int k = 0; k < d; k++) {
					curr = this->getElement(x + j, y + i, z + k);
					res.setElement(j, i, k, curr);
				}
			}
		}
		return res;
	}

	template<typename T>
	inline void Mat<T>::paste(int x, int y, int z, Mat<T> frame)
	{
		T curr;
		for (int i = 0; i < frame.getHeight(); i++) {
			for (int j = 0; j < frame.getWidth(); j++) {
				for (int k = 0; k < frame.getDepth(); k++) {
					curr = frame.getElement(j, i, k);
					this->setElement(x + j, y + i, z + k, curr);
				}
			}
		}
	}

	template<typename T>
	inline void Mat<T>::fill(T value)
	{
		for (int i = 0; i < this->getSize(); i++)
		{
			this->setElement(i, value);
		}
	}

}