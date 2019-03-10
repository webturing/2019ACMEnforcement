# 第二讲：字符串及其相关算法

## 一、字符串的基本应用

## 二、C++中的string类型的使用

## 三、字符串高效匹配算法：KMP算法
```
KMP算法中最难理解的就是如何求next[]数组
推荐大家去https://www.cnblogs.com/yjiyjige/p/3263858.html当中查看
在这我就只给出代码
void get_next(String T, int *next) {
   int j=0;
    next[0] = -1;
    int k=-1;
    while (j < T.length-1) {
        if (k = -1 || T[j] == T[k]) {
            ++j;
            ++k;
            next[j] = k;
        } else
            k = next[k];
    }
}

```
## 四、字符串高效查找算法：字典树Trie