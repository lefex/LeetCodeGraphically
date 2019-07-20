 // 监听 p 标签的点击，并更新它的值
 const para = document.querySelector('p');
 para.addEventListener('click', updateName);
 function updateName() {
     let name = prompt("Enter the name");
     para.textContent = name;
 }
 document.addEventListener("DOMContentLoaded", function () {
     function createParagraph() {
         let para = document.createElement('p');
         para.textContent = "You clicked the button";
         document.body.appendChild(para);
     }

     const buttons = document.querySelectorAll('button');
     for (let i = 0; i < buttons.length; i++) {
         buttons[i].addEventListener('click', createParagraph);
     }
 })