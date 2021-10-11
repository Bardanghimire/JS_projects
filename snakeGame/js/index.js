//Decalaring constant and variables

let Inputdir = { x: 0, y: 0 };
const foodEaten = new Audio('../music/food.mp3')
const gameOver = new Audio('../music/gameover.mp3')
const move = new Audio('../music/move.mp3')
const music = new Audio('../music/music.mp3')
let speed = 10;
let score = 0;
let lastTime = 0;
let unrequired = true
let snakeArr = [
    {
        x: 15, y: 15
    }
]
let food = {
    x: 10, y: 10
}
//functions in js
function main(ctime) {
    window.requestAnimationFrame(main);
    // console.log(ctime);
    if ((ctime - lastTime) / 1000 < 1 / speed) return
    lastTime = ctime;
    gameEngine();
}
function isCollide(snake) {
    for (let i = 1; i < snakeArr.length; i++) {
        if (snake[0].x === snake[i].x && snake[0].y === snake[i].y) return true;
        if (snake[0].x >= 20 || snake[0].x <= 0 || snake[0].y >= 20 || snake[0].y <= 0) return true;
    }
}
function gameEngine() {
    //Updating the display
    if (isCollide(snakeArr)) {
        gameOver.play();
        music.pause();
        Inputdir = { x: 0, y: 0 }
        alert("Game Over. Press Enter to play again")
        snakeArr = [{
            x: 15, y: 15
        }]
        // music.play();
        score = 0;
    }
    //If snake eat food
    if (snakeArr[0].x === food.x && snakeArr[0].y === food.y) {
        foodEaten.play();
        score++;
        scoreBox.innerHTML = "Score: " + score;
        if(score>hiscoreval){
            hiscoreval = score;
            localStorage.setItem("hiscore",JSON.parse(hiscoreval));
            HIscore.innerHTML = "Hiscore: "+hiscoreval;
        }
        snakeArr.unshift({ x: snakeArr[0].x + Inputdir.x, y: snakeArr[0].y + Inputdir.y })
        let a = 2, b = 18;
        food = { x: Math.round(a + (b - a) * Math.random()), y: Math.round(a + (b - a) * Math.random()) }
    }
    //snakeMove
    for (let i = snakeArr.length - 2; i >= 0; i--) {
        snakeArr[i + 1] = { ...snakeArr[i] };
    }
    if (unrequired) {
        snakeArr[0].x += Inputdir.x
        snakeArr[0].y += Inputdir.y
    }
    //Display the snake
    board.innerHTML = ""
    snakeArr.forEach((element, index) => {
        let Element = document.createElement('div');
        Element.style.gridRowStart = element.y;
        Element.style.gridColumnStart = element.x;
        if (index === 0) {
            Element.classList.add('head');
        }
        else {
            Element.classList.add('snake');
        }
        board.appendChild(Element);
    });
    //Display the food

    let Elementood = document.createElement('div');
    Elementood.style.gridRowStart = food.y;
    Elementood.style.gridColumnStart = food.x;
    Elementood.classList.add('food')
    board.appendChild(Elementood);


}


//main loops
// music.play();
// music.pause();
let hiscore = localStorage.getItem("hiscore")
if(hiscore === null){
    hiscoreval = 0;
    localStorage.setItem("hiscore",JSON.parse(hiscoreval))
}
else{
    hiscoreval = JSON.parse(hiscore);
    HIscore.innerHTML = "HiScore: " + hiscore;
}
window.requestAnimationFrame(main);
window.addEventListener("keydown", e => {
    Inputdir = { x: 0, y: 0 }
    move.play();
    // music.play();
    switch (e.key) {
        case "ArrowUp":
            Inputdir.x = 0;
            Inputdir.y = -1;
            break;
        case "ArrowDown":
            Inputdir.x = 0;
            Inputdir.y = 1;
            break;
        case "ArrowLeft":
            Inputdir.x = -1;
            Inputdir.y = 0;
            break;
        case "ArrowRight":
            Inputdir.x = 1;
            Inputdir.y = 0;
            break;
        case "Space":
            unrequired = false;
        default:
            break;
    }
})

