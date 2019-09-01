## 정렬 시간복잡도 비교

<img src="https://camo.githubusercontent.com/7d4ae6dd7e846eac5957efa8ad70d46c0e86abf4/68747470733a2f2f676d6c776a64393430352e6769746875622e696f2f696d616765732f616c676f726974686d2d717569636b2d736f72742f736f72742d74696d652d636f6d706c65786974792e706e67">

<br>

#### 안정성

> 같은 값을 가진 데이터의 순서가 정렬 후에도 그대로 유지되는 지

**안정 정렬** : 삽입, 버블, 병합

**불안정 정렬** : 선택, 쉘, 퀵, 힙

<br>

**추가 메모리 필요** : 병합 정렬

<br>

#### 퀵 정렬 vs 병합 정렬

---

둘다 시간복잡도는 O(nlogn)

하지만 병합 정렬은 병합하는 과정에서 임시 저장공간을 추가로 만들어 사용하기 때문에 추가적인 메모리가 필요함

퀵 정렬은 추가 메모리 없이 내부 교환만으로 수행할 수 있어서 좀 더 빠른 속도를 가짐

<br>

***퀵소트 최악의 경우는 n^2인데 왜 퀵소트 써요?***

최악의 경우가 나오는 경우는, 정렬해야 할 병렬이 역순으로 정렬된 상황 (ex [5,4,3,2,1])

pivot 값을 N만큼 움직이며 교환해야 되는 상황임

따라서 이를 해결하기 위해 보통 pivot값의 위치를 **배열의 중간값**으로 가져감 (n^2 최악상황 해결)

<br>

```java
public static void quickSort(int[] arr, int left, int right) {

    if(left >= right) return;

    if(left < right) {

        int pivot = arr[(left+right)/2]; // 중간값
        int i = left - 1;
        int j = right + 1;

        while(true) {

            while(arr[++i] < pivot) {
            }

            while(arr[--j] > pivot) {
            }

            if(i >= j) break;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        quickSort(arr, left, i-1);
        quickSort(arr, j+1, right);

    }

}
```

그래서 보통 정렬 상황에서는 퀵소트를 많이 활용함