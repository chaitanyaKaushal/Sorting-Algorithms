#include<iostream>
#include<time.h>
#include<iomanip>
#include<cmath>
using namespace std;

void print(countyTax **counties,int size){
	for(int i=0;i<size;i++){
		cout<<counties[i]->getCounty()<<" "<<counties[i]->getTax()<<endl;
	}
}
//Bubble Sort
void bubbleSort(countyTax **counties,int size){
	clock_t start,end;
	start=clock();
	for(int i=0;i<size-1;i++){
		bool flag=false;//to check if in an entire pass there were no swaps that means the taxRates are sorted in that pass. So no need to iterate further :)
		for(int j=0;j<size-1-i;j++){
			if(counties[j]->getTax() > counties[j+1]->getTax()){
				flag=true;
				countyTax *temp;
				temp=counties[j];
				counties[j]=counties[j+1];
				counties[j+1]=temp;
			}
		}
		if(!flag)
		    break;
	}
	end=clock();
	print(counties,size);
	double duration=double(end-start);
	cout<<"The time of execution for Bubble Sort is: "<<fixed<<duration/CLOCKS_PER_SEC<<" seconds"<<endl;
}
//Insertion Sort
void insertionSort(countyTax **counties,int size){
	clock_t start,end;
	start=clock();
	for(int j=1;j<size;j++){
		countyTax *key=counties[j];
		int i=j-1;
		while(i>=0 && counties[i]->getTax() > key->getTax()){
			counties[i+1]=counties[i];
			i--;
		}
		counties[i+1]=key;
	}
	end=clock();
	print(counties,size);
	double duration=double(end-start);
	cout<<"The time of execution for Insertion Sort is: "<<fixed<<duration/CLOCKS_PER_SEC<<" seconds"<<endl;
	
}
//Selection sort
void selectionSort(countyTax **counties,int size){
	clock_t start,end;
	start=clock();
	for(int i=0;i<size;i++){
		countyTax *min=counties[i];
		int minIndex=i;
		for(int j=i+1;j<size;j++){
			if(min->getTax() > counties[j]->getTax()){
				min=counties[j];
				minIndex=j;
			}
		}
		countyTax *temp=counties[i];
		counties[i]=min;
		counties[minIndex]=temp;
	}
	end=clock();
	print(counties,size);
	double duration=double(end-start);
	cout<<"The time of execution for Selection Sort is: "<<fixed<<duration/CLOCKS_PER_SEC<<" seconds"<<endl;
}
//QuickSort
int partition(countyTax **counties,int l, int h){
	countyTax *pivot=counties[l];
	int count=0;
	for(int i=l+1;i<=h;i++){
		if(pivot->getTax() >= counties[i]->getTax()){
			count++;
		}
	}
	int pivotIndex=l+count;
	countyTax *temp=counties[pivotIndex];
	counties[pivotIndex]=pivot;
	counties[l]=temp;
	int i=l;
	int j=h;
	while(i<j){
		while(i<=h && pivot->getTax() >= counties[i]->getTax()){
			++i;
		}
		while(j>=l && pivot->getTax() < counties[j]->getTax()){
			--j;
		}
		if(i<=j){
			countyTax *temp=counties[i];
			counties[i]=counties[j];
			counties[j]=temp;
			++i;
			--j;
		}
	}
	return pivotIndex;
}
void quick_sort(countyTax **counties,int l,int h){
	if(l < h){
		int j=partition(counties,l,h);
		quick_sort(counties,l,j-1);
		quick_sort(counties,j+1,h);
	}
	return ;
}
void quickSort(countyTax **counties,int size){
	clock_t start,end;
	start=clock();
	int l=0;
	int h=size-1;
	quick_sort(counties,l,h);
	end=clock();
	print(counties,size);
	double duration=double(end-start);
	cout<<"The time of execution for Quick Sort is: "<<fixed<<duration/CLOCKS_PER_SEC<<" seconds"<<endl;
}
//mergeSort
void merge(countyTax **counties,int l,int mid,int h){
	int i=l;
	int j=mid+1;
	countyTax **newCounty=new countyTax*[h-l+1];
	int k=0;
	while(i <= mid && j<=h){
		if(counties[i]->getTax() <= counties[j]->getTax()){
			newCounty[k]=new countyTax();
			newCounty[k]->setTax(counties[i]->getTax());
			newCounty[k]->setCounty(counties[i]->getCounty());
			k++;
			i++;
		}
		if(counties[i]->getTax() > counties[j]->getTax()){
			newCounty[k]=new countyTax();
			newCounty[k]->setTax(counties[j]->getTax());
			newCounty[k]->setCounty(counties[j]->getCounty());
			k++;
			j++;
		}
	}
	while(i<=mid){
        newCounty[k]=new countyTax();
		newCounty[k]->setTax(counties[i]->getTax());
		newCounty[k]->setCounty(counties[i]->getCounty());
		k++;
		i++;	
	}
	while(j<=h){
		newCounty[k]=new countyTax();
		newCounty[k]->setTax(counties[j]->getTax());
		newCounty[k]->setCounty(counties[j]->getCounty());
		k++;
		j++;	
	}
	for(int k=0;k<(h-l+1);k++){
		counties[l+k]=newCounty[k];
	}
}

void merge_sort(countyTax **counties,int l,int h){
	if(l < h){
		int mid=(l+h)>>1;
		merge_sort(counties,l,mid);
		merge_sort(counties,mid+1,h);
		merge(counties,l,mid,h);
	}
	return ;
}
void mergeSort(countyTax **counties,int size){
	clock_t start,end;
	start=clock();
	int l=0;
	int h=size-1;
	merge_sort(counties,l,h);
	end=clock();
	print(counties,size);
	double duration=double(end-start);
	cout<<"The time of execution for Merge Sort is: "<<fixed<<duration/CLOCKS_PER_SEC<<" seconds"<<endl;
}
