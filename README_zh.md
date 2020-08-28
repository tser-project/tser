# Tser
一个TypeScript虚拟机。

Switch Language: [English](./README.md)。

#### 安装使用
```bash
$ brew tap tser-project/tser && brew install tser;

$ tser ./input.ts;
```

## 为什么要创造Tser？
TypeScript（TS）是一个伟大的发明，让我们在复用JS生态的同时拥有了静态类型语言的开发体验。
TS本质是一门预编译语言，编译到JS后再使用JS虚拟机执行，由于强依赖于JS，也因此无法摆脱JS的一些顽疾，比如执行效率。而TS本身是静态类型语言，拥有确定的数据类型标记，只是在转义为JS时丢失了类型标记；如果我们能直接执行TS程序，而不是先转义为JS再执行，这些数据类型标记可以为程序带来很大的性能提升。

我们来看一组性能对比数据，仅对比`fib(42)`在各个虚拟机或语言中的性能表现（并不能完全依此来作为性能评价标准；测试条件：同一设备同一状态，编译过程均未使用任何优化）。


|       语言        |    虚拟机         |     执行耗时(ms)    |
| ----             | ----             | ----               |
| TypeScript       | deno             | 4150               |
| JavaScript       | v8 / node        | 3859               |
| TypeScript       | Tser             | 2035               |
| C++              | --               | 2106               |


TS技术发展很快，业界已经有越来越多的项目使用TS开发和重构；抛开眼下去看TS技术的发展，它的终点会在哪里？会一直停留在一个预编译语言上吗？当TS生态发展越来越健全，是不是还有必要完全依托于JS的生态？业界会不会诞生一个真正的TS虚拟机（Deno并不是）？如果业界有一个稳定且高性能的TS虚拟机，对TS生态是不是一件好事，会不会将TS推向一个新的高度？


*<u>TS应该无法取代JS的生态，但是在某些领域，TS可以脱离JS生态而独立存在；TS虚拟机是独立TS生态的基石，可以让TS在这些领域有明显优于JS的运行时表现，并为这些领域带来实际的业务收益。</u>*

## Tser能做什么？
Tser编译性能相对不高而运行时性能高，更适合独立后台服务、Serverless等场景。如果语法支持完善，可以运行绝大部分现有的使用TS编写的后台服务时，这些服务可以因此获得很大的性能提升。

Tser目前能做的事情还非常少，因为语法支持很不完善，仅能支持一些简单脚本的执行，比如应该能够支持一些简单的云函数场景。

## Tser技术原理
Tser前端依托于Antlr来生成的语法解析器，然后进行语法树的生成与遍历；后端依托于LLVM建设，将TS代码编译为LLVM IR，并使用其JIT引擎立即执行IR。

业界雷同产品: [AssemblyScript](https://www.assemblyscript.org/)、[StaticScript](https://github.com/ovr/StaticScript)

## Tser语法支持
> 可参考[__test](./__test/)目录下的测试文件。

### 变量
支持`var` `let` `const`, `var`与`let`相同。

### 基础类型
| 类型              | 字节 (in 64bit)          | 支持            |
| ----             | ----                     | ----            |
| boolean          | 1                        | ✔️               |
| number           | 4                        | ✔️ 同int32        |
| int32            | 4                        | ✔️               |
| int64            | 8                        | ✔️               |
| float            | 4                        | ✔️               |
| double           | 8                        | ✔️               |
| string           | --                       | ✔️ 暂不支持运算     |

### 运算符
| 运算符                     | 支持                     |
| ----                      | ----                    |
| `+` `-` `*` `/` `%`       | ✔️                       |
| `++` `--`                 | ✔️                       | 
| `+=` `-=` `*=` `/=` `%=`  | ✔️                       |
| `<` `>` `<=` `>=`         | ✔️                       |
| `==` `===` `!=` `!==`     | ✔️ `===`与`==`目前没有区别 |
| `&&` `||`                 | ✔️                       |
| `!`                       | ✔️                       |
| `? :`                     | ✔️                       |
| `()`                      | ✔️                       |
| `.`                       | ✔️                       |

### 逻辑控制语句
| 语句                      | 支持                     |
| ----                      | ----                    |
| `if else`                 | ✔️                       |
| `while` `do while`        | ✔️                       | 
| `for`                     | ✔️                       |
| `switch`                  | ✔️                       |
| `continue`                | ✔️                       |
| `break`                   | ✔️                       |

### 函数
支持绝大部分函数功能，函数嵌套，暂不支持闭包和函数参数。

示例参考: [__test/basic/function](./__test/basic/7_function.ts)

### Class
Class支持继承、多态，支持Class组合，支持静态属性与静态方法，不支持方法重载；Class继承和多态使用类似虚拟表的方式来支持，多态支持方法和属性。

示例参考: [__test/class/](./__test/class/)

### 内置对象
目前内置对象支持力度非常低，仅用于测试。

| 内置对象                    | 方法                                 |
| ----                      | ----                                 |
| `console`                 | `debug` `log` `info` `warn` `error`  |
| `Date`                    | `now`                                | 

### 暂不支持
`module` `内置对象`、`Event Loop`、`GC`等等。

## 贡献Tser
Tser是一个巨大的工程，很难用一己之力完成。Tser现在还是一个baby，更希望它能起到一个抛砖引玉的作用，能聚集起一些有能力的人来一起建设。

### 环境安装
1. 安装`cmake`、`make`
2. 安装 [LLVM](http://clang.llvm.org/get_started.html) 
3. 安装 [Antlr](https://www.antlr.org/download/)
4. 环境变量配置
    ```bash
    # Clang
    export CC=/usr/bin/clang
    export CXX=/usr/bin/clang++

    # LLVM
    export PATH="/Users/vifird/C/compile/llvm-project/build/bin:$PATH"

    # Antlr
    export ANTLR_RUNTIME=${Path of runtime}/runtime/usr/local
    alias antlr4='java -jar /usr/local/lib/antlr-4.8-complete.jar'
    alias grun='java org.antlr.v4.gui.TestRig'
    export ANTLR_EXECUTABLE=/usr/local/lib/antlr-4.8-complete.jar
    export CLASSPATH=".:/usr/local/lib/antlr-4.8-complete.jar:$CLASSPATH"
    ```

### 构建命令
- `make build-debug` : 构建调试包（开发时LLVM建议使用Debug模式构建）
- `make build` : 构建生产包
- `make build-builtin` : 构建内置对象
- `make build-parser` : 重新生成语法解析器
- `make grun` : 可视化查看TS代码生成的语法树

## 捐赠支持
<a target="_blank" href="https://github.com/lanistor/assets/blob/master/tser/support_tser_zfb.jpg">捐赠给Tser</a>，以支持作者继续创作Tser。

## 友情链接
| 支持产品                   | 介绍                                 |
| ----                      | ----                                 |
| <a target="_blank" href="https://flicker.cool/?mark=tser_github_rm">【闪点清单】<br/>一款独特的悬浮清单软件</a>                 | <a target="_blank" href="https://flicker.cool/?mark=tser_github_rm"><img src="https://raw.githubusercontent.com/lanistor/assets/master/tser/ads/flicker/flicker_gif_500x120.gif" width="400"/></a>  |




