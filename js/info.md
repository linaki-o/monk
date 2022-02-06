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