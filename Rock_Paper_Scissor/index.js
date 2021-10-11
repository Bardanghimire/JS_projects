//Defining variables 

let image = document.querySelectorAll('.img');



image.forEach(img=>{
    img.addEventListener("click",()=>{
        console.log("clicked");
    })
})