/**
 * Programmer Name: V.N. Anriudh Oruganti
 * Class: CSCE 350
 * Application:
 * Excution:
 * Copyright 2021 V.N. Anirudh Oruganti
 **/

// Includes
#include <Project_1/inc/QuickSort.h>

  void QuickSort::swap(int leftIndex, int rightIndex) {
    float temp = 0;
    temp = _dataList[leftIndex];
    _dataList[leftIndex] = _dataList[rightIndex];
    _dataList[rightIndex] = temp;
  }
  int QuickSort::median_of_three(int firstIndex,int middleIndex,int lastIndex){
    
  return  ((_dataList[firstIndex]<=_dataList[middleIndex] && _dataList[firstIndex]>= _dataList[lastIndex])||
             (_dataList[firstIndex]>=_dataList[middleIndex] && _dataList[firstIndex]<=_dataList[lastIndex]))?firstIndex:
            ((_dataList[middleIndex]<=_dataList[firstIndex] && _dataList[middleIndex]>=_dataList[lastIndex])||
            (_dataList[middleIndex]>=_dataList[firstIndex] && _dataList[middleIndex]<=_dataList[lastIndex]))?middleIndex:lastIndex; 
  }
  void QuickSort::doSort(int firstIndex, int lastIndex) {
    if ( firstIndex < lastIndex  ){
      int s = doPartition(firstIndex, lastIndex);
       doSort(firstIndex, (s - 1));
       doSort((s + 1), lastIndex);
    }
  }
  int QuickSort::doPartition(int firstIndex, int lastIndex) {
    int middleIndex = (lastIndex+firstIndex)/2;
    int pivotIndex = median_of_three(firstIndex,middleIndex,lastIndex);   
    swap(pivotIndex,firstIndex);
    pivotIndex = firstIndex;
    float pivot =  _dataList[pivotIndex];
    int i = firstIndex;
    int j = lastIndex;

    while (1){
        while ((_dataList[i] < pivot || i == pivotIndex ) && (i+1)<= lastIndex && (i+1) >= firstIndex )++i;
        while ((_dataList[j] > pivot || j == pivotIndex ) && (j-1)>= firstIndex && (j-1) <= lastIndex )--j;
        if (i >= j) break; swap(i, j);
        ++i; --j;
    }

   swap(pivotIndex,j);
  return j;

  }


