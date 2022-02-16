/*
 * Store.h
 *
 *  Created on: 23 Jan 2021
 *      Author: faez zangariya
 */

#ifndef STORE_H_
#define STORE_H_

#include<iostream>
#include<cstring>
#include<fstream>
#include <iterator>
#include <map>
#include"Mapval.h"
#include"IndexOutOfRange.h"
using namespace std;






template<class T>
class Store :public Mapval{
public:
	Store():size(0){fstream f("store.bin", ios::in | ios::out | ios::binary);}
	virtual ~Store(){
		delete this;
	}
	void append(T& add){
		f.write(serialize(add),sizeof(T));
		size++;
	}

	void write(T& add,int i){
		try{
			if(i>size)
				throw IndexOutOfRange();
		}
		catch(IndexOutOfRange& x){
			throw x;
		}
		f.seekp(sizeof(T)*i);
		f.write(serialize(&add),sizeof(T));
		f.seekp(sizeof(T)*size);
	}

	T& read(int& i){
		try{
			if(i>size)
				throw IndexOutOfRange();
		}
		catch(IndexOutOfRange& x){
			throw x;
		}
		char buffer[sizeof(T)*size];
		f.read(buffer,sizeof(T)*size);
		char toreturn[4];
		for(int j=0;j<4;j++)
			toreturn[j]=buffer[sizeof(T)*i+j];
		T ret=deserialize(toreturn);
		return ret;
	}

	char* serialize(T* num){
		char* numchars=reinterpret_cast<char*>(num);
		return numchars;
	}

	T* deserialize(char* num){
		T* numint=reinterpret_cast<T*>(num);
		return numint;
	}




private:
	fstream f;
	int size;
};




template<>
class Store<int>{
public:
	Store():size(0){fstream f("store.bin", ios::in | ios::out | ios::binary);}
	virtual ~Store(){
		delete this;
	}
	void append(int& add){
		f.write(serialize(&add),sizeof(int));
		size++;
	}

	void write(int& add,int& i){
		try{
			if(i>size)
				throw IndexOutOfRange();
		}
		catch(IndexOutOfRange& x){
			throw x;
		}
		f.seekp(sizeof(int)*i);
		f.write(serialize(&add),sizeof(int));
		f.seekp(sizeof(int)*size);
	}

	int& read(int& i){
		try{
			if(i>size)
				throw IndexOutOfRange();
		}
		catch(IndexOutOfRange& x){
			throw x;
		}
		char toreturn[sizeof(int)];
		f.seekp(sizeof(int)*i);
		f.read(toreturn,sizeof(int));
		f.seekp(sizeof(int)*size);
		int* ret=deserialize(toreturn);
		return *ret;
	}

	char* serialize(int* num){
		char* numchars=reinterpret_cast<char*>(num);
		return numchars;
	}

	int* deserialize(char* num){
		int* numint=reinterpret_cast<int*>(num);
		return numint;
	}

private:
	fstream f;
	int size;
};



template<>
class Store<char>{
public:
	Store():size(0){fstream f("store.bin", ios::in | ios::out | ios::binary);}
	virtual ~Store(){
		delete this;
	}
	void append(char& add){
		f.write(serialize(add),sizeof(char));
		size++;
	}

	void write(char& add,int& i){
		try{
			if(i>size)
				throw IndexOutOfRange();
		}
		catch(IndexOutOfRange& x){
			throw x;
		}
		f.seekp(sizeof(char)*i);
		f.write(serialize(add),sizeof(char));
		f.seekp(sizeof(char)*size);
	}

	char& read(int& i){
		try{
			if(i>size)
				throw IndexOutOfRange();
		}
		catch(IndexOutOfRange& x){
			throw x;
		}
		char toreturn[sizeof(char)];
		f.seekp(sizeof(char)*i);
		f.read(toreturn,sizeof(char));
		f.seekp(sizeof(char)*size);
		return *deserialize(toreturn);
	}

	char* serialize(char& num){
		return &num;
	}

	char* deserialize(char* num){
		return num;
	}

private:
	fstream f;
	int size;
};



template<>
class Store<double>{
public:
	Store():size(0){fstream f("store.bin", ios::in | ios::out | ios::binary);}
	virtual ~Store(){
		delete this;
	}
	void append(double& add){
		f.write(serialize(&add),sizeof(double));
		size++;
	}

	void write(double& add,int i){
		try{
			if(i>size)
				throw IndexOutOfRange();
		}
		catch(IndexOutOfRange& x){
			throw x;
		}
		f.seekp(sizeof(double)*i);
		f.write(serialize(&add),sizeof(double));
		f.seekp(sizeof(double)*size);
		}

	double& read(int& i){
		try{
			if(i>size)
				throw IndexOutOfRange();
		}
		catch(IndexOutOfRange& x){
			throw x;
		}
		char toreturn[sizeof(double)];
		f.seekp(sizeof(double)*i);
		f.read(toreturn,sizeof(double));
		f.seekp(sizeof(double)*size);
		return *deserialize(toreturn);
	}

	char* serialize(double* num){
		char* numchars=reinterpret_cast<char*>(num);
		return numchars;
	}

	double* deserialize(char* num){
		double* numdouble=reinterpret_cast<double*>(num);
		return numdouble;
	}

private:
	fstream f;
	int size;
};




template<>
class Store<bool>{
public:
	Store():size(0){fstream f("store.bin", ios::in | ios::out | ios::binary);}
	virtual ~Store(){
		delete this;
	}
	void append(bool& add){
		f.write(serialize(&add),sizeof(bool));
		size++;
	}

	void write(bool& add,int i){
		try{
			if(i>size)
				throw IndexOutOfRange();
		}
		catch(IndexOutOfRange& x){
			throw x;
		}
		f.seekp(sizeof(bool)*i);
		f.write(serialize(&add),sizeof(bool));
		f.seekp(sizeof(bool)*size);
	}

	bool& read(int& i){
		try{
			if(i>size)
				throw IndexOutOfRange();
		}
		catch(IndexOutOfRange& x){
			throw x;
		}
		char toreturn[sizeof(bool)];
		f.seekp(sizeof(bool)*i);
		f.write(toreturn,sizeof(bool));
		f.seekp(sizeof(bool)*size);
		return *deserialize(toreturn);
	}

	char* serialize(bool* num){
		char* numchars=reinterpret_cast<char*>(num);
		return numchars;
	}

	bool* deserialize(char* num){
		bool* numbool=reinterpret_cast<bool*>(num);
		return numbool;
	}

private:
	fstream f;
	int size;
};


#endif /* STORE_H_ */
