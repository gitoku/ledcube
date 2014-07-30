# ledcube

## 座標

各方向それぞれ`0~7`の座標で表す

* `x`方向
* `y`方向
* `z`方向

## サンプルスケッチ

基本的に`ledcube.ino`のみ編集する.

### 座標`(0,0,0)`のLEDを点滅させる

#### 個別に指定

`ledcube.ino`
```cpp
#include "ledcube.h"

void setup(){
	LEDCUBE::begin();
}

void loop(){
	LEDCUBE::set(0,0,0);	//ON
	delay(500);

	LEDCUBE::clr(0,0,0);	//OFF
	delay(500);
}
```
* `LEDCUBE::begin()`:LEDCUBEを開始( `setup()` に必ず書く)
* `LEDCUBE::set(x,y,z)`:座標`(x,y,z)`のLEDをON
* `LEDCUBE::clr(x,y,z)`:座標`(x,y,z)`のLEDをOFF

#### まとめて更新
* `Cube`オブジェクトを用いる
* 推奨

`ledcube.ino`
```cpp
#include "ledcube.h"

void setup(){
	LEDCUBE::begin();
}

void loop(){
	Cube cube;

	cube.set(0,0,0);
	LEDCUBE::update(cube);
	delay(500);

	cube.clr(0,0,0);
	LEDCUBE::update(cube);
	delay(500);
}
```

* `LEDCUBE::update(Cube)`:Cubeの内容をLEDCUBEに反映

## `Cube`オブジェクト

### 概要
* `8*8*8`の2値(0 or 1)配列を持つ
* `Cube`オブジェクトを用いることで配列の計算が簡単にできる

### 宣言
* 宣言時に自動で配列の中身が0に初期化される
```cpp
Cube box;	//Cubeオブジェクトのインスタンスcを生成
```

### メソッド
* `set(x,y,z)`
	* 座標`(x,y,z)`を1で上書き
* `clr(x,y,z)`
	* 座標`(x,y,z)`を0で上書き

```cpp
Cube matrix;

matrix.set(0,0,0);	//(0,0,0)を1に
matrix.clr(7,7,7);	//(7,7,7)を0に
```

* `clearAll()`
	* `8*8*8`すべてを0に上書き
```cpp
Cube empty;

empty.clearAll();	//すべて0に
```

* `get(x,y,z)`
	* 座標`(x,y,z)`の内容を返す(boolean)
```cpp
Cube cube;
boolean data;

cube.set(3,5,1);	//(3,5,1)を1に
data = cube.get(3,5,1);	//(3,5,1)の内容1を返す
```

### コピー

`Cube`オブジェクトは`=`でコピーできる
```cpp
Cube a;
Cube b;
boolean c;

a.set(1,2,3);	//(1,2,3)を1に
b = a;	//bにaをコピー
c = b.get(1,2,3);	//(1,2,3)の内容1を返す
```

### `LEDCUBE`へ反映
* `LEDCUBE::update(Cube)`
	* Cubeの内容をLEDCUBEに反映
	* `0,1`はそれぞれLEDのON,OFFとなる