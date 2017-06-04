

# F题

### 题解

根据题意，要求得 $a_i\  xor\ x_j$ 的最大值， 也就是选取一个 $a_i$ 使得任意一个二进制位

尽量与 $x_j$ 不同，可以考虑将 $a_i$ 根据二进制位存储为一颗字典树，在查询时便可以很方便可以很方便的得到答案。

不得不感叹字典树的代码是如此的经典，能在寥寥几行完成需要完成的工作

#### 建树

```c++
void insert(int x)
{
    int cur = 0, cur_bit;//cur为当前的节点编号，cur_bit为当前的二进制
    for (int i = 30; i >= 0; --i)
    {
        cur_bit = (x >> i) & 1;//自高位到低位取二进制位
        if(dict_tree[cur][cur_bit] == 0)//当前节点是叶子节点，则向下延伸
            dict_tree[cur][cur_bit] = cur_node++;
        cur = dict_tree[cur][cur_bit];//获取下一个节点编号
    }
    value[cur] = x;//在相应的cur中存入x的值
}
```

#### 查询

```c++
int query(int x)
{
    int cur = 0, cur_bit;
    for (int i = 30; i >= 0; --i)
    {
        cur_bit = !((x >> i) & 1);//因为是异或，尽量满足x与a的二进制位不同
        if(dict_tree[cur][cur_bit] == 0)
            cur_bit = !cur_bit;//如果无法满足不同则变为相同
        cur = dict_tree[cur][cur_bit];
    }
    return value[cur];
}
```



以上