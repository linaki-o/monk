> String

The value of String is immutable, you can't do this:
```js
let myStr = "Bob";
myStr[0] = "J";
```
but you can modify it by assigning it another value, like:
```js
let myStr = "Bob";
myStr = "Job";
```
----
> Array
- Array's elements are mutable and can be freely changed, even if the array is declared with const
- A simple way to add data to the end of an array is the **push()** function.
- Use the **pop()** function to delete the last item of the array
- Use the **shift()** function to delete the first item of the array
- **unshift()** insert a elem in the head
-----
> Scope

- Variables not declared with the let or const keywords are automatically created in the **global** scope
-------
> if-else-if
-----
> switch
----
> undefined
----
> Object

create

访问对象属性的第二种方式是方括号表示法（[]）。 如果你想访问的属性名中包含空格，就必须使用方括号表示法来获取它的属性值。

delete ourDog.bark;


.hasOwnProperty()


if();