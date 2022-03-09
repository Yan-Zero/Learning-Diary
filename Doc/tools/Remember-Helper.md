# [Remember-Helper](../../Tools/Remember-Helper/)

[背诵助手](../../Tools/Remember-Helper.exe)

- 语言: C++
- 版本: 0.1.0

## 使用说明
### 模式
#### 英语单词

当开始记忆单词时，有三种模式，分别是

- 随机回归记忆
- 定期回归记忆 - 时间
- 定期回归记忆 - 数量

测试类型有

- 中文选英文
- 英文选中文
- 英文选词性
- 中文补拼写

##### 随机回归

即在测试一定数量后，开启数量不定的单词复习模式。

##### 定期回归

即在指定时间后，复习上个时间段的单词。<br/>
或者是<br/>
在指定数量单词过后，复习上个阶段的单词。<br/>
模式: n -> n-1 -> n-2 -> n+1 -> n -> ...

#### 中文诗词

测试类型有

- 上句选下句
- 上句补下句
- 下句补上句
- 下句选上句
- 句内补全

## [配置](../../Tools/Remember-Helper.yaml)

- root:
  - 名称: 根目录
  - 类型: string
  - 默认值: ../
- data:
  - 名称: 背诵配置目录
  - 类型: string
  - 默认值: data
- resources:
  - 名称: 资源目录
  - 类型: string
  - 默认值: Resources
- english:
  - 名称: 英语目录
  - 类型: string
  - 默认值: remember/english
- chinese:
  - 名称: 语文目录
  - 类型: string
  - 默认值: remember/chinese


## TODO

- [x] 播放音频
- [x] 记录与数据库分离
- [ ] 英语单词
- [ ] 自动完善单词表(Word List)
- [ ] 语文诗词
- [ ] CLI 界面
- [ ] Toast 界面

