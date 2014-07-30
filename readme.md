# ledcube

## 目次

<!-- MarkdownTOC depth=3 -->

- 座標
- サンプルスケッチ
	- お題：「座標`(0,0,0)`のLEDを点滅させる」
- `Cube`オブジェクト
	- 概要
	- 宣言
	- メソッド
	- コピー
	- `LEDCUBE`へ反映

<!-- /MarkdownTOC -->


## 座標

各方向それぞれ`0~7`の座標で表す

* 原点
	* 正面からみて左上の手前
* `x`方向
	* 原点から右方向
* `y`方向
	* 原点から奥方向
* `z`方向
	* 原点から下方向

## サンプルスケッチ

基本的に`ledcube.ino`のみ編集する.

### お題：「座標`(0,0,0)`のLEDを点滅させる」

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
* `8*8*8`の2値(HIGH or LOW)配列を持つ
* `Cube`オブジェクトを用いることで配列の計算が簡単にできる

### 宣言
* 宣言時に自動で配列の中身がLOWに初期化される
```cpp
Cube box;	//Cubeオブジェクトのインスタンスboxを生成
```

### メソッド
* `set(x,y,z)`
	* 座標`(x,y,z)`をHIGHで上書き
* `clr(x,y,z)`
	* 座標`(x,y,z)`をLOWで上書き

```cpp
Cube matrix;

matrix.set(0,0,0);	//(0,0,0)をHIGHに
matrix.clr(7,7,7);	//(7,7,7)をLOWに
```

* `clearAll()`
	* `8*8*8`すべてをLOWに上書き
```cpp
Cube empty;

empty.clearAll();	//すべてLOWに
```

* `get(x,y,z)`
	* 座標`(x,y,z)`の内容を返す(boolean)
```cpp
Cube cube;
boolean data;

cube.set(3,5,1);	//(3,5,1)をHIGHに
data = cube.get(3,5,1);	//(3,5,1)の内容HIGHを返す
```

* `line(x,y,z,value)`
	* 例えば`line(LINE,3,4,HIGH)`ならば`z=4`,`y=4`の直線上を`HIGH`で上書きする
	* `line(7,LINE,1,LOW)`ならば`x=7`,`z=1`の直線上を`LOW`で上書きする

### コピー

`Cube`オブジェクトは`=`でコピーできる
```cpp
Cube a;
Cube b;
boolean c;

a.set(1,2,3);	//(1,2,3)をHIGHに
b = a;	//bにaをコピー
c = b.get(1,2,3);	//(1,2,3)の内容HIGHを返す
```
* 処理に時間がかかるので、あまり多用しない

### `LEDCUBE`へ反映
* `LEDCUBE::update(Cube)`
	* `Cube`の内容を`LEDCUBE`に反映
	* `HIGH`,`LOW`はそれぞれLEDのON,OFFとなる
* `LEDCUBE::pull(Cube)`
	* `LEDCUBE`の現在の状態を`Cube`に複製
	* できるだけ使用しない(時間のかかる処理のため)
