# One
Sass 不同于 CSS 的一个特点是它允许使用变量。 可以在 Sass 中声明变量，并为它赋值，就像在 JavaScript 中一样。
```html
<style type='text/scss'>
</style>
```

```sass
$main-fonts: Arial, sans-serif;
$headings-color: green;
```
```css
h1 {
  font-family: $main-fonts;
  color: $headings-color;
}
```


# 用 Sass 嵌套 CSS

在对应的父元素中写子元素的样式

要按照子元素的顺序
```scss
nav {
  background-color: red;

  ul {
    list-style: none;

    li {
      display: inline-block;
    }
  }
}
```

# 用 Mixins 创建可重用 CSS

CSS 的新功能需要一段时间适配后，所有浏览器后才能完全使用。 随着浏览器的不断升级，使用这些 CSS 规则时可能需要添加浏览器前缀。

```scss
@mixin box-shadow($x, $y, $blur, $c){ 
  -webkit-box-shadow: $x $y $blur $c;
  -moz-box-shadow: $x $y $blur $c;
  -ms-box-shadow: $x $y $blur $c;
  box-shadow: $x $y $blur $c;
}

div {
  @include box-shadow(0px, 0px, 4px, #fff);
}
```

# 使用 @if 和 @else 为样式添加逻辑
```scss
@mixin text-effect($val) {
  @if $val == danger {
    color: red;
  }
  @else if $val == alert {
    color: yellow;
  }
  @else if $val == success {
    color: green;
  }
  @else {
    color: black;
  }
}
```

# 使用 @for 创建一个 Sass 循环

@for 以两种方式使用：“开始 through 结束” 或 “开始 to 结束”。 主要区别在于“开始 to 结束”不包括结束数字，而“开始 through 结束”包括 结束号码。

```scss
@for $i from 1 through 12 {
  .col-#{$i} { width: 100%/12 * $i; }
}

.col-1 {
  width: 8.33333%;
}

.col-2 {
  width: 16.66667%;
}

...

.col-12 {
  width: 100%;
}
```

# 使用 @each 遍历列表中的项目

```scss
@each $color in blue, red, green {
  .#{$color}-text {color: $color;}
}

$colors: (color1: blue, color2: red, color3: green);

@each $key, $color in $colors {
  .#{$color}-text {color: $color;}
}
```

# 使用 @while 循环创建样式
```scss
$x: 1;
@while $x < 13 {
  .col-#{$x} { width: 100%/12 * $x;}
  $x: $x + 1;
}
```

# 用 Partials 将样式分成小块
Sass 中的 Partials 是包含 CSS 代码段的单独的文件。 这些片段可以导入其它 Sass 文件使用。 可以把类似代码放到模块中，以保持代码结构规整且易于管理。

partials 的名称以下划线（_）字符开头，这样 Sass 就知道它是 CSS 的一小部分，而不会将其转换为 CSS 文件。 此外，Sass 文件以 .scss 文件扩展名结尾。 要将 partial 中的代码放入另一个 Sass 文件中，使用 @import 指令。

例如，如果所有 mixins 都保存在名为 “_mixins.scss” 的 partial 中，并且在 “main.scss” 文件中需要它们，下面是使用方法：
```scss
@import 'mixins'
```
请注意，import 语句中不需要下划线——Sass 知道它是 partial。 将 partial 导入文件后，可以使用所有变量、mixins 和其它代码。

# 将一组 CSS 样式扩展到另一个元素
```scss
.panel{
  background-color: red;
  height: 70px;
  border: 2px solid green;
}

.big-panel{
  @extend .panel;
  width: 150px;
  font-size: 2em;
}
```