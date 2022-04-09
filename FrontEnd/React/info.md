React 是由 Facebook 创建和维护的开源视图库。 它是渲染现代 Web 应用程序用户界面（UI）的好工具。

React 使用名为 JSX 的 JavaScript 语法扩展，可以直接在 JavaScript 中编写 HTML。 这有几个好处。 可以在 HTML 中使用 JavaScript 的完整程序功能，并有助于保持代码的可读性。 
因为 JSX 是 JavaScript 的语法扩展，所以实际上可以直接在 JSX 中编写 JavaScript。 要做到这一点，只需在花括号中包含希望被视为 JavaScript 的代码：{ 'this is treated as JavaScript code' }（这被视为 JavaScript 代码）

但是，由于浏览器不能解析 JSX，因此必须将 JSX 代码编译为 JavaScript。 在这个过程中，转换器 Babel 是一个很受欢迎的工具。 后续挑战已经在后台引入了 Babel，可以直接写 JSX 代码。

值得注意的是，这些挑战在底层调用 ReactDOM.render(JSX, document.getElementById('root'))。 这个函数调用将 JSX 置于 React 自己的轻量级 DOM 中。 然后，React 使用自己的 DOM 快照来实现增量更新。