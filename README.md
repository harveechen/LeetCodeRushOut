## Prerequisite

安装 vscode `C/C++ Extension Pack`

## How to use

### 一键debug

`F5`

### 只编译


`Ctrl Shift + B`

### 代码片段先导词


`oj` leetcode 初始化模板，然后将leetcode playground对应位置代码复制到缺省位置（有的题目不行）
`foj` 只使用function风格

### 输入重定向

需要输入文件时，在root目录下创建 `input.txt`

### 其他细节
* 编译好的文件统一放在build文件目录下，格式为 `父文件夹名-文件名`
* 代码模板中的 `extra/utils.hpp` 包含了leetcode的输入输出处理函数
* 部分笔试记录 `git checkout oj`

## Examples

### 输入

#### stringToIntegerVector
```cpp
// input.txt
[1,2,3,4]

// xxx.cpp
vector<int> input = stringToIntegerVector(line);

```

#### stringToStringVector
```cpp
// input.txt
["a","b","c"]

// xxx.cpp
vector<string> input = stringToStringVector(line);

```

#### stringToTreeNode
```cpp
// input.txt
[1,null,0,0,1]

// xxx.cpp
TreeNode *input = stringToTreeNode(line);

```


