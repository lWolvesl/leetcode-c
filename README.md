- 02/2506
  - ```c++
    for (const string &word : words)
    {
        int state = 0;
        for (char c : word)
        {
            state |= 1 << (c - 'a');
        }
        res += cnt[state];
        cnt[state]++;
    }
    ```
  - 这是一种位压缩算法，巧妙的利用二进制的位来表示一个单词中出现的所有字母。
  - 关键就是`state |= 1 << (c - 'a');`这一行。这一行的作用是将state的第(c - 'a')位设为1，这样就可以表示这个单词中出现了字母c。