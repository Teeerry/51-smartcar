# 基于STC89C52RC的智能小车
## 基本情况
开发环境：Keil C51 uVision5

开发套件：BST-Car

如何使用：首先详细阅读BST-Car及小车地盘的原理图，按照要求连线组装小车，然后在Keil新建工程，导入Source里面的文件，经过编译烧录，即可对小车进行测试。
## 实现功能
通过安卓APP进行功能选择以及遥控，蓝牙连接后小车以默认蓝牙遥控模式运行。
### 1. 蓝牙遥控
通过蓝牙进行遥控（前进，后退，左转，右转，加速，减速）以及工作模式切换。
### 2. 红外循迹
在红外循迹模式下，小车可以通过地盘调节红外精度，以达到最佳循迹效果。
### 3. 超声波避障
在超声波模式下，遇到近距离有障碍物，小车自动转向规避。
### 4. 红外跟随
在红外跟随模式下，小车跟随测试者手部动作前进、后退以及转向等。
## 效果图示 
