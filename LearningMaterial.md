# RayTracing 入门学习资料（推荐顺序：先动手写简易路径追踪，再理论，最后硬件实时光追）
> 你的背景是GPU驱动/图形渲染，所以我会区分**离线路径追踪（基础原理）** 和**DXR/Vulkan RTX硬件光线追踪（游戏/实时，和你工作强相关）**

## ✅ 首选入门（必看，写代码，零门槛）
### 1. Ray Tracing in One Weekend 三部曲（Peter Shirley，免费在线书，CC0）
官网：[https://raytracing.github.io/](https://raytracing.github.io/)
- Book1：Ray Tracing in One Weekend：几百行C++，从零实现基础路径追踪，球体求交、反射折射、蒙特卡洛全局光照。**入门第一站**，数学轻，直接出图，成就感强。
- Book2：Ray Tracing: The Next Week：BVH加速结构、纹理、矩形、实例化、体积雾。
- Book3：Ray Tracing: The Rest Of Your Life：采样理论、重要性采样、概率，深入渲染方程。
Github源码：[https://github.com/RayTracing/raytracing.github.io](https://github.com/RayTracing/raytracing.github.io)

> 社区有CUDA版本移植，适合GPU方向：NVIDIA博客《Accelerated Ray Tracing in One Weekend in CUDA》

## 📚 理论进阶书籍
### 2. PBRT v4 *Physically Based Rendering: From Theory to Implementation*（渲染圣经，免费在线）
官网：[https://pbr-book.org/](https://pbr-book.org/)
适合你：完整物理渲染、光线传输方程、采样、加速结构。**在One Weekend写完之后再读**，不要上来啃。附带完整开源渲染器pbrt-v4。

### 3. Ray Tracing Gems 系列（NVIDIA，免费）
重点是**实时硬件光线追踪**（DXR/RTX），讲管线、BVH构建、着色器、降噪、性能优化。非常贴合GPU驱动开发方向。
> Ray Tracing Gems 1 / 2 免费在线阅读。

## 🎓 课程 & 视频
1. **Ray Tracing Essentials (NVIDIA SIGGRAPH)**（强烈推荐，B站有中文字幕）
7集短片，直观解释光追核心概念：光线、求交、阴影、反射、全局光照、加速结构。先看这个建立直觉。
2. Berkeley CS184 / CS284A 计算机图形学
经典图形课，包含路径追踪作业，配套讲义、slides、录播。
3. ETH Nori渲染器课程：Nori2，C++简易渲染器框架，作业一步步实现光追/路径追踪，框架已经搭好，只写核心光照代码。

## 💻 开源代码项目（边学边调试）
1. Nori2（ETH）：教学向PBR渲染器，作业友好
2. pbrt-v4：工业级离线渲染器，代码规范
3. Microsoft D3D12 Raytracing Samples（DXR官方样例）
DirectX12硬件光追管线入门，HelloWorld、三角形求交、着色器表，**和Windows GPU驱动高度相关**，非常适合你现在的方向。
4. Sascha Willems Vulkan Ray Tracing Samples：Vulkan RT 全套demo，跨平台硬件光追。

## 📖 网站教程
1. Scratchapixel：计算机图形学在线教程，光线追踪章节，数学推导清晰，适合查漏补缺。
2. Real-Time Rendering 官网资源页：Ke-Sen Huang整理的RayTracing资源大全，包含论文、博客、课程链接。

## 🗺️ 推荐学习路线（适配你GPU驱动背景）
1. 先看 NVIDIA Ray Tracing Essentials 视频，建立概念
2. 实现 **Ray Tracing in One Weekend Book1**（C++简易路径追踪，CPU），理解：ray、hit、材质、蒙特卡洛
3. Book2，学习BVH（重中之重，硬件光追的核心加速结构）
4. 切换到**硬件光追**：跑Microsoft DXR sample / Vulkan RT sample，理解RT pipeline、TLAS/BLAS、shader table
5. 进阶：Ray Tracing Gems（实时光追优化），PBRT（物理渲染理论）
6. 拓展：阅读Whitted 1980原始光追论文、Veach的蒙特卡洛光追经典论文

## 区分两个容易混淆概念（你工作会频繁遇到）
- **离线Ray Tracing / Path Tracing**：One Weekend / PBRT，CPU/GPU暴力采样，电影渲染，不依赖硬件RT核心
- **Real-time Hardware Ray Tracing（DXR/VK RT）**：游戏RTX，GPU硬件BVH遍历，你做WDDM/UMD驱动接触的就是这套



如果你想要，我可以：
1. 给你精简的数学前置清单（向量、球面求交、概率、渲染方程）
2. 或者给一份One Weekend Book1的C++极简工程模板，直接编译运行
3. 或者直接梳理DXR硬件光追管线、TLAS/BLAS原理（贴合你Windows GPU驱动方向）