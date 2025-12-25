# [Silver V] 쿠폰 잘 사용하기? - 34995 

[문제 링크](https://www.acmicpc.net/problem/34995) 

### 성능 요약

메모리: 2392 KB, 시간: 4 ms

### 분류

그리디 알고리즘, 문자열

### 제출 일자

2025년 12월 21일 20:37:45

### 문제 설명

<p>토카는 일정 금액까지 현금 대신 사용할 수 있는 쿠폰을 사용하여 음식을 주문하려 한다.</p>

<p>쿠폰에는 $N$자리 정수로 쿠폰의 금액이 적혀 있다. 하지만 쿠폰 금액의 일부 숫자는 가끔 얼룩이 묻어 얼마인지 알아볼 수 없어 토카는 얼룩이 묻은 부분의 숫자를 적당히 지어내기로 한다. 쿠폰의 각 금액은 $1$ 이상 $9$ 이하의 숫자로 이루어져 있으며, 토카가 지어낼 숫자도 $1$ 이상 $9$ 이하의 숫자여야 한다.</p>

<p>토카가 지어낸 쿠폰의 금액이 음식의 가격보다 작으면 주문할 수 없다. 토카가 음식을 주문할 수 있도록 쿠폰을 어떻게 지어내야 할지 알아보자.</p>

### 입력 

 <p>첫 번째 줄에 쿠폰에 적힌 금액의 자릿수 $N$ $(1 \leq N \leq 10^{5})$과 쿠폰에 적힌 금액을 나타내는 길이 $N$의 문자열이 공백으로 구분되어 주어진다. 문자열은 <span style="color:#e74c3c;"><code>1</code></span>, <span style="color:#e74c3c;"><code>2</code></span>, <span style="color:#e74c3c;"><code>3</code></span>, <span style="color:#e74c3c;"><code>4</code></span>, <span style="color:#e74c3c;"><code>5</code></span>, <span style="color:#e74c3c;"><code>6</code></span>, <span style="color:#e74c3c;"><code>7</code></span>, <span style="color:#e74c3c;"><code>8</code></span>, <span style="color:#e74c3c;"><code>9</code></span>, <span style="color:#e74c3c;"><code>?</code></span>로 이루어져 있으며 숫자는 쿠폰에 적힌 알아볼 수 있는 숫자, <span style="color:#e74c3c;"><code>?</code></span>는 얼룩이 묻어있어 알아볼 수 없는 숫자를 의미한다.</p>

<p>두 번째 줄에 음식의 가격을 나타내는 정수 $A$ $(1 \leq A \leq 10^{100000})$가 주어진다.</p>

### 출력 

 <p>토카가 음식을 주문하기 위해 지어낼 쿠폰의 금액을 아무거나 하나 출력한다. 어떻게 지어내도 주문할 수 없다면 대신 <span style="color:#e74c3c;"><code>-1</code></span>을 출력한다.</p>

