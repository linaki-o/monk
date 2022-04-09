font-family: Lobster, Monospace;
# One
Bootstrap 会根据屏幕大小来动态调整 HTML 元素的大小————因此称为 Responsive Design（响应式设计）。

首先，我们应该将所有 HTML（ link 标签和 style 元素除外）嵌套在带有 container-fluid class 的 div 元素里面。

只需要为 image 标签上设置 class 属性为 img-responsive ， 就可以让它完美地适应你的页面的宽度了

class 属性设置为 text-center 就可以实现居中


```
<button class="btn btn-default btn-block">Submit</button>
```
这个按钮会 100% 占满所有的可用宽度。

btn-primary 深蓝色 
浅蓝色的 btn-info
btn-danger

Bootstrap 具有一套 12 列的响应式栅格系统，可以轻松的将多个元素放入一行并指定它们的相对宽度。
# Two

Bootstrap 具有一套 12 列的响应式栅格系统，可以轻松的将多个元素放入一行并指定它们的相对宽度。
col-md-* class 来说。 在这里， md 表示 medium （中等的）， 而 * 是一个数字，说明了这个元素占有多少个列宽度。
col-xs-* ， 其中 xs 是 extra small 的缩写 (比如窄屏手机屏幕)， * 是填写的数字，代表一行中的元素该占多少列宽
将 Like，Info 和 Delete 三个按钮并排放入一个 <div class="row"> 元素中，然后每个按钮都各用一个 <div class="col-xs-4"> 元素包裹起来。

 大部分的 Bootstrap 的 class 都能用在 div 元素上。

# Three
Font Awesome 是一个非常便利的图标库。 我们可以通过 webfont 或矢量图的方式来使用这些图标。 这些图标就和字体一样， 不仅能通过像素单位指定它们的大小，它们也同样会继承父级 HTML 元素的字号。

```html
<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.8.1/css/all.css" integrity="sha384-50oBUHEmvpQ+1lW4y57PTFmhCaXp0ML5d60M1M7uH2+nqUivzIebhndOJK28anvf" crossorigin="anonymous">
```

下述要求中的 i 元素也可以用 span 元素代替。

Bootstrap 的 col-xs-* class 也可以用在 form 元素上！

所有文本输入类的元素如 <input>，<textarea> 和 <select> 只要设置 .form-control class 就会占满100%的宽度。

Bootstrap 有一个叫作 well 的 class，作用是使界面更具层次感。

并不是所有 class 属性都需要有对应的 CSS 样式。 有时候我们设置 class 只是为了更方便地在 jQuery 中选中这些元素。