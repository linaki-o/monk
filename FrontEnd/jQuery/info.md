# One
$(document).ready(function() {});

jQuery 库和 Animate.css 库，所以你可以在编辑器里直接使用它们。 你将使用 jQuery 将 Animate.css bounce class 应用于 button 元素。

```js
$(".text-primary").addClass("animated shake");

$("#target6").addClass("animated fadeOut");
```

# Two

```
$("#target1").css("color", "blue");
```

jQuery 有一个 .prop() 方法，可以用其调整标签的属性。

下面是禁用所有的按钮的代码：

```js
$("button").prop("disabled", true);
```

# Three
```js
$("h3").html("<em>jQuery Playground</em>");
$("h3").text("<em>jQuery Playground</em>");
```

<i> 标签虽然传统上用来强调文本，但此后常用作图标的标签。 <em> 标签作为强调标签现在已被广泛接受。

jQuery 有一个 .remove() 方法，能完全移除 HTML 标签。

jQuery 有一个 appendTo() 方法，可以选取 HTML 标签并将其添加到另一个标签里面。

jQuery 有一个 clone() 方法，可以复制标签。
```js
$("#target2").clone().appendTo("#right-well");
```
链式调用（function chaining）

jQuery 有一个 parent() 方法，可以访问被选取标签的父标签。
```js
$("#left-well").parent().css("background-color", "blue")
```

jQuery 有一个 children() 方法，可以访问被选取标签的子标签。

```js
$(".target:nth-child(3)").addClass("animated bounce");
```

也可以用基于位置的奇 :odd 和偶 :even 选择器选取标签。
```js
$(".target:odd").addClass("animated shake");
```

移除
```js
$("body").addClass("animated hinge");
```