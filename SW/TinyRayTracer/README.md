# 1. C++ cout 输出 PPM 图片（P3 文本格式，RayTracing in One Weekend 标准格式）

PPM `P3` 是**文本格式**，正好可以直接用 `std::cout` 输出，不用文件库；你只需要**把 cout 重定向到文件**，或者直接用 `ofstream`（推荐）。

> 
> PPM P3 格式规则（必须严格遵守，否则图片打不开）

```
P3
width height
max_color_value
r g b
r g b
...
```

- `P3`：标识文本PPM
- 一行：宽 高
- 一行：最大值，一般用 `255`
- 之后每行一组 r g b，范围 0~255，空格分隔

## 方式1：代码用 cout，**运行时命令行重定向（One Weekend原版做法）**

代码里面直接 `cout` 输出像素，**代码不打开文件**，编译后命令行把 stdout 写入 `.ppm`

```
#include <iostream>
int main() {
    const int w = 200;
    const int h = 100;

    std::cout << "P3\n" << w << " " << h << "\n255\n";

    for (int j = h - 1; j >= 0; j--) { // 图片坐标系：从上到下
        for (int i = 0; i < w; i++) {
            double r = double(i) / w;
            double g = double(j) / h;
            double b = 0.2;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
    return 0;
}
```

### 编译 & 运行（Windows cmd / PowerShell）

```
# 编译
g++ main.cpp -o ray
# 把cout输出写入image.ppm
ray.exe > image.ppm
```

> 
> 原理：`>` 把进程标准输出(stdout)捕获写入文件，就是 Peter Shirley 书中的原生写法。

## 方式2：C++ 直接写入文件（ofstream，不依赖命令行重定向，更推荐工程使用）

不用cout重定向，把 `cout` 替换成 `std::ofstream` 对象，逻辑完全一样：

```
#include <iostream>
#include <fstream>
int main() {
    const int w = 200;
    const int h = 100;
    std::ofstream out("image.ppm");

    out << "P3\n" << w << " " << h << "\n255\n";

    for (int j = h - 1; j >= 0; j--) {
        for (int i = 0; i < w; i++) {
            double r = double(i) / w;
            double g = double(j) / h;
            double b = 0.2;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            out << ir << " " << ig << " " << ib << "\n";
        }
    }
    out.close();
    return 0;
}
```

## ⚠️ RayTracing 最容易踩坑的3个点

1. **图片行顺序**：PPM第一行对应图片**最上面一行**，所以循环 `j` 要**从 h-1 往下到0**，否则图像上下颠倒。
2. **`255.999` 而不是 `255`**：浮点值接近1时 `255 * 1.0` 有可能因为浮点截断变成254，`255.999` 规避截断bug。
3. **不要多余空行**，部分ppm解析器对空白敏感。

## 查看PPM图片工具

- IrfanView（Windows）直接打开ppm
- GIMP
- VS Code插件：PPM viewer
- ImageMagick：`magick image.ppm image.png` 转png

## 如果你想：把已有cout输出流，直接重定向到文件（替换全局cout）

```
#include <iostream>
#include <fstream>
int main() {
    std::ofstream file("out.ppm");
    std::streambuf* old_cout_buf = std::cout.rdbuf(file.rdbuf());

    // 这里所有cout都会写入文件
    std::cout << "P3\n200 100\n255\n";

    // 恢复cout到控制台
    std::cout.rdbuf(old_cout_buf);
    file.close();
    return 0;
}
```